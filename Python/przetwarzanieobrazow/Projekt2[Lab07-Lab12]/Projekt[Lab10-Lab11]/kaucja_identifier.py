"""
Rozpoznawanie znaku systemu kaucyjnego
Wielostopniowa detekcja:
  1. SIFT + FLANN - dopasowanie cech
  2. Walidacja geometrii homografii (inliery RANSAC, kształt czworokąta)
  3. Weryfikacja strukturalna - sprawdzenie obecności strzałek w znalezionym regionie
     (kluczowe dla odrzucenia obrazów z samym słowem 'kaucja' bez strzałek/ramki)
"""

import cv2 as cv
import numpy as np
import os
import re

# ---------------------------------------------------------------------------
# Konfiguracja
# ---------------------------------------------------------------------------

REF_FILENAMES = ("kaucja.png", "kaucja50.jpg")
MIN_REF_DIM = 300        # upscaluj referencje mniejsze niż ta wartość
MIN_INLIERS = 12         # minimalna liczba geometrycznie spójnych inlierów RANSAC
RATIO_TEST = 0.70        # próg Lowe'a (ostrzejszy niż standardowe 0.75)
MIN_INLIER_RATIO = 0.30  # min. frakcja inlierów wśród kandydatów
SCALES = (1.0, 0.5, 1.5, 2.0)

# Regiony strzałek jako frakcje rozmiaru obrazu referencyjnego.
# Znak kaucji ma strzałkę (→) w górnej części i (←) w dolnej -
# to one odróżniają znak od zwykłego tekstu "KAUCJA".
ARROW_ROIS = [
    (0.05, 0.40, 0.08, 0.45),   # górna strzałka (→)
    (0.60, 0.95, 0.55, 0.92),   # dolna strzałka (←)
]
ARROW_NCC_MIN = 0.05  # minimalne NCC - przy pustym/białym regionie daje ≈ 0


# ---------------------------------------------------------------------------
# Pomocnicze funkcje
# ---------------------------------------------------------------------------

def natural_sort_key(s: str) -> list:
    return [int(t) if t.isdigit() else t.lower() for t in re.split(r'([0-9]+)', s)]


def preprocess(img: np.ndarray) -> np.ndarray:
    """Skala szarości + CLAHE dla lepszego kontrastu przy detekcji."""
    gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY) if img.ndim == 3 else img.copy()
    return cv.createCLAHE(clipLimit=2.0, tileGridSize=(8, 8)).apply(gray)


def load_references(img_dir: str) -> list:
    """Ładuje obrazy referencyjne, upscalując te zbyt małe dla SIFT."""
    refs = []
    for fname in REF_FILENAMES:
        path = os.path.join(img_dir, fname)
        img = cv.imread(path)
        if img is None:
            print(f"[WARN] Brak referencji: {fname}")
            continue
        h, w = img.shape[:2]
        if max(h, w) < MIN_REF_DIM:
            s = MIN_REF_DIM / max(h, w)
            img = cv.resize(img, (int(w * s), int(h * s)), interpolation=cv.INTER_CUBIC)
        refs.append(img)
    return refs


# ---------------------------------------------------------------------------
# Walidacja geometryczna
# ---------------------------------------------------------------------------

def homography_ok(M: np.ndarray) -> bool:
    if M is None:
        return False
    det = np.linalg.det(M[:2, :2])
    return 0.01 <= abs(det) <= 1000


def quad_ok(dst: np.ndarray, img_h: int, img_w: int) -> bool:
    """Sprawdza czy wykryty czworokąt ma sens geometryczny dla znaku kaucji."""
    pts = dst.reshape(4, 2).astype(np.float32)

    area = cv.contourArea(pts)
    hull_area = cv.contourArea(cv.convexHull(pts))
    if hull_area < 1 or area / hull_area < 0.80:
        return False

    img_area = img_h * img_w
    if not (img_area * 0.005 <= area <= img_area * 0.99):
        return False

    _, _, w, h = cv.boundingRect(pts.astype(np.int32))
    if min(w, h) <= 0 or max(w, h) / min(w, h) > 6:
        return False

    sides = [np.linalg.norm(pts[(i + 1) % 4] - pts[i]) for i in range(4)]
    if min(sides) < 5 or max(sides) / max(min(sides), 1e-6) > 20:
        return False

    return True


# ---------------------------------------------------------------------------
# Weryfikacja strukturalna - strzałki
# ---------------------------------------------------------------------------

def ncc(a: np.ndarray, b: np.ndarray) -> float:
    """Znormalizowana korelacja wzajemna."""
    af, bf = a.astype(float), b.astype(float)
    ra = (af - af.mean()) / (af.std() + 1e-6)
    rb = (bf - bf.mean()) / (bf.std() + 1e-6)
    return float((ra * rb).mean())


def arrows_present(g_target: np.ndarray, g_ref: np.ndarray, M: np.ndarray) -> bool:
    """
    Dopasowuje region celu do przestrzeni referencji i sprawdza NCC w regionach
    strzałek. Obrazy z samym tekstem 'KAUCJA' (bez strzałek i ramki) mają pusty
    biały region w tych miejscach → NCC ≈ 0, co powoduje odrzucenie.
    Prawdziwy znak kaucji ma strzałki → NCC > ARROW_NCC_MIN.

    Uwaga: M mapuje ref→scaled_target, więc warpPerspective(g_target, M, ref_size)
    daje obraz celu wyrównany do przestrzeni referencji.
    """
    h_ref, w_ref = g_ref.shape[:2]
    warped = cv.warpPerspective(g_target, M, (w_ref, h_ref))

    clahe = cv.createCLAHE(clipLimit=2.0, tileGridSize=(8, 8))
    ref_eq = clahe.apply(g_ref)
    war_eq = clahe.apply(warped)

    for (y0, y1, x0, x1) in ARROW_ROIS:
        ys, ye = int(h_ref * y0), int(h_ref * y1)
        xs, xe = int(w_ref * x0), int(w_ref * x1)

        r_roi = ref_eq[ys:ye, xs:xe]
        w_roi = war_eq[ys:ye, xs:xe]

        if r_roi.size == 0 or w_roi.size == 0:
            return False

        if ncc(r_roi, w_roi) < ARROW_NCC_MIN:
            return False

    return True


# ---------------------------------------------------------------------------
# Główna funkcja detekcji
# ---------------------------------------------------------------------------

def detect_kaucja(img: np.ndarray, refs: list, sift, flann) -> tuple:
    """
    Wykrywa znak kaucji na obrazie.

    Zwraca:
        (result_img, found, dst_quad, match_vis, (confidence, inlier_count))
    """
    if img is None or not refs:
        return img, False, None, None, (0, 0)

    best_n = 0
    best = None

    for ref in refs:
        g_ref = preprocess(ref)
        kp_ref, des_ref = sift.detectAndCompute(g_ref, None)
        if des_ref is None or len(des_ref) < MIN_INLIERS:
            continue

        for scale in SCALES:
            if scale == 1.0:
                target = img
            else:
                target = cv.resize(img, (int(img.shape[1] * scale),
                                         int(img.shape[0] * scale)))

            g_target = preprocess(target)
            kp_t, des_t = sift.detectAndCompute(g_target, None)
            if des_t is None or len(des_t) < MIN_INLIERS:
                continue

            raw_matches = flann.knnMatch(des_ref, des_t, k=2)
            good = [m for pair in raw_matches
                    if len(pair) == 2
                    for m, n in [pair]
                    if m.distance < RATIO_TEST * n.distance]

            if len(good) < MIN_INLIERS:
                continue

            src_pts = np.float32([kp_ref[m.queryIdx].pt for m in good]).reshape(-1, 1, 2)
            dst_pts = np.float32([kp_t[m.trainIdx].pt  for m in good]).reshape(-1, 1, 2)

            M, mask = cv.findHomography(src_pts, dst_pts, cv.RANSAC, 5.0)
            if not homography_ok(M) or mask is None:
                continue

            inlier_mask = mask.ravel().astype(bool)
            n_inliers = int(inlier_mask.sum())

            if n_inliers < MIN_INLIERS or n_inliers / len(good) < MIN_INLIER_RATIO:
                continue

            # Transformuj narożniki referencji na współrzędne obrazu docelowego
            h_r, w_r = g_ref.shape[:2]
            corners_ref = np.float32(
                [[0, 0], [0, h_r - 1], [w_r - 1, h_r - 1], [w_r - 1, 0]]
            ).reshape(-1, 1, 2)
            dst_quad = cv.perspectiveTransform(corners_ref, M)

            # Przenieś z powrotem do skali oryginalnego obrazu
            if scale != 1.0:
                dst_quad = dst_quad / scale

            if not quad_ok(dst_quad, img.shape[0], img.shape[1]):
                continue

            # Weryfikacja strukturalna: czy w znalezionym regionie są strzałki?
            if not arrows_present(g_target, g_ref, M):
                continue

            if n_inliers > best_n:
                best_n = n_inliers
                inlier_matches = [good[i] for i in range(len(good)) if inlier_mask[i]]
                match_vis = cv.drawMatches(
                    ref, kp_ref, target, kp_t, inlier_matches, None,
                    flags=cv.DrawMatchesFlags_NOT_DRAW_SINGLE_POINTS,
                )
                confidence = min(100, int(n_inliers / 25.0 * 100))
                best = (dst_quad, match_vis, confidence, n_inliers)

    if best:
        dst_quad, match_vis, confidence, n_inliers = best
        result = img.copy()
        cv.polylines(result, [np.int32(dst_quad)], True, (0, 255, 0), 3, cv.LINE_AA)
        return result, True, dst_quad, match_vis, (confidence, n_inliers)

    return img, False, None, None, (0, 0)


# ---------------------------------------------------------------------------
# Interfejs użytkownika
# ---------------------------------------------------------------------------

def display_result(result_img: np.ndarray, found: bool, match_vis,
                   filename: str, conf: int, inliers: int) -> None:
    if found:
        cv.putText(result_img, f"KAUCJA WYKRYTA  ({conf}%)",
                   (10, 30), cv.FONT_HERSHEY_SIMPLEX, 0.7, (0, 200, 0), 2)
        cv.putText(result_img, f"RANSAC inliers: {inliers}",
                   (10, 58), cv.FONT_HERSHEY_SIMPLEX, 0.55, (0, 200, 100), 1)
        cv.imshow("Dopasowanie cech (inliery SIFT)", match_vis)
    else:
        cv.putText(result_img, "BRAK ZNAKU KAUCJI",
                   (10, 30), cv.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 220), 2)

    cv.imshow(f"Wynik: {filename}", result_img)


def main() -> None:
    script_dir = os.path.dirname(os.path.abspath(__file__))
    img_dir = os.path.join(script_dir, "zdjecia")

    refs = load_references(img_dir)
    if not refs:
        print("BLAD: Brak obrazow referencyjnych w folderze 'zdjecia'.")
        return

    sift = cv.SIFT_create()
    flann = cv.FlannBasedMatcher(
        dict(algorithm=1, trees=5),
        dict(checks=50),
    )

    ref_set = set(REF_FILENAMES)
    all_files = sorted(
        [f for f in os.listdir(img_dir)
         if f.lower().endswith((".png", ".jpg", ".jpeg", ".webp"))],
        key=natural_sort_key,
    )
    images = [f for f in all_files if f not in ref_set]

    print("=" * 55)
    print("  Rozpoznawanie znaku systemu kaucyjnego")
    print(f"  Obrazy referencyjne: {len(refs)} szt.")
    print(f"  Obrazy do analizy:   {len(images)} szt.")
    print("=" * 55)
    print("Sterowanie: dowolny klawisz = nastepny  |  q = koniec\n")

    stats = {"total": 0, "found": 0}

    for filename in images:
        img_path = os.path.join(img_dir, filename)
        img = cv.imread(img_path)
        if img is None:
            continue

        stats["total"] += 1
        label = f"[{stats['total']:>2}/{len(images)}]"
        print(f"{label} {filename:<30}", end=" ", flush=True)

        # Skaluj wyświetlanie do rozsądnych wymiarów (detekcja i tak na oryginale)
        h, w = img.shape[:2]
        disp_scale = min(1.0, 800 / max(h, w))
        img_disp = cv.resize(img, (int(w * disp_scale), int(h * disp_scale))) \
            if disp_scale < 1.0 else img.copy()

        result_img, found, _, match_vis, (conf, inliers) = detect_kaucja(
            img_disp, refs, sift, flann
        )

        if found:
            stats["found"] += 1
            print(f"-> ZNALEZIONO  pewnosc={conf}%  inliers={inliers}")
        else:
            print("-> BRAK")

        display_result(result_img, found, match_vis, filename, conf, inliers)

        key = cv.waitKey(5000) & 0xFF
        cv.destroyAllWindows()
        if key == ord('q'):
            print("\nPrzerwano.")
            break

    print("\n" + "=" * 55)
    print("PODSUMOWANIE")
    print(f"  Przetworzono: {stats['total']}")
    print(f"  Wykryto:      {stats['found']}")
    pct = stats['found'] / stats['total'] * 100 if stats['total'] else 0
    print(f"  Skutecznosc:  {pct:.1f}%")
    print("=" * 55)
    input("Nacisnij Enter aby zakonczyc...")


if __name__ == "__main__":
    main()
