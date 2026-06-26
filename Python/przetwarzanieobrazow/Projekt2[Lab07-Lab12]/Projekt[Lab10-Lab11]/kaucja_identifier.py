import cv2 as cv
import numpy as np
import os
import re


def natural_sort_key(s):
    return [int(text) if text.isdigit() else text.lower()
            for text in re.split('([0-9]+)', s)]


def is_valid_quadrilateral(dst, img_shape):
    """Validate that detected region makes geometric sense for a kaucja sign."""
    pts = dst.reshape(4, 2)

    # Must be at least 80% convex (no extreme concavities)
    area = cv.contourArea(np.float32(pts))
    hull_area = cv.contourArea(cv.convexHull(np.float32(pts)))
    if hull_area < 1:
        return False
    if area / hull_area < 0.80:
        return False

    img_area = img_shape[0] * img_shape[1]

    # Sign must occupy at least 0.5% of the image
    # Upper bound is 99%: a full-frame kaucja photo (like 16.jpg) is valid
    if area < img_area * 0.005 or area > img_area * 0.99:
        return False

    # Bounding box aspect ratio: kaucja sign is ~4:3, allow up to 6:1
    _, _, w, h = cv.boundingRect(np.int32(pts))
    if min(w, h) <= 0:
        return False
    if max(w, h) / min(w, h) > 6:
        return False

    # No side should be degenerate or wildly different from the others
    sides = [np.linalg.norm(pts[(i + 1) % 4] - pts[i]) for i in range(4)]
    if min(sides) < 5:
        return False
    if max(sides) / max(min(sides), 1) > 20:
        return False

    return True


def validate_homography_matrix(M):
    """Check that the homography matrix is not degenerate."""
    if M is None:
        return False
    det = np.linalg.det(M[:2, :2])
    # Determinant near zero = collapsed / flipped transformation
    if abs(det) < 0.01 or abs(det) > 1000:
        return False
    return True


def detect_kaucja(target_img, ref_imgs, sift, flann, min_inliers=12):
    """
    Detect kaucja sign using multiple references and strict geometric validation.

    Key difference from naive SIFT matching: we validate RANSAC inlier count
    (geometrically consistent matches), not just putative feature matches.
    This prevents false positives from images that contain the word 'kaucja'
    but lack the characteristic arrow+rectangle structure.
    """
    if target_img is None:
        return target_img, False, None, None, (0, 0)

    def preprocess(img):
        gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY) if len(img.shape) == 3 else img
        clahe = cv.createCLAHE(clipLimit=2.0, tileGridSize=(8, 8))
        return clahe.apply(gray)

    best_result = None
    best_inliers = 0

    for ref_img in ref_imgs:
        if ref_img is None:
            continue

        gray_ref = preprocess(ref_img)
        kp1, des1 = sift.detectAndCompute(gray_ref, None)
        if des1 is None or len(des1) < min_inliers:
            continue

        for scale in [1.0, 0.5, 1.5, 2.0]:
            if scale == 1.0:
                current_target = target_img
            else:
                w = int(target_img.shape[1] * scale)
                h = int(target_img.shape[0] * scale)
                current_target = cv.resize(target_img, (w, h))

            gray_target = preprocess(current_target)
            kp2, des2 = sift.detectAndCompute(gray_target, None)
            if des2 is None or len(des2) < min_inliers:
                continue

            matches = flann.knnMatch(des1, des2, k=2)

            # Stricter Lowe ratio test (0.70 vs 0.75) reduces spurious matches
            good = []
            for pair in matches:
                if len(pair) == 2:
                    m, n = pair
                    if m.distance < 0.70 * n.distance:
                        good.append(m)

            # Need enough candidates before even attempting homography
            if len(good) < min_inliers:
                continue

            src_pts = np.float32([kp1[m.queryIdx].pt for m in good]).reshape(-1, 1, 2)
            dst_pts = np.float32([kp2[m.trainIdx].pt for m in good]).reshape(-1, 1, 2)

            M, mask = cv.findHomography(src_pts, dst_pts, cv.RANSAC, 5.0)
            if M is None or mask is None:
                continue

            if not validate_homography_matrix(M):
                continue

            # CRITICAL: count only geometrically consistent RANSAC inliers,
            # not the putative good matches — this is what the old code got wrong
            inlier_mask = mask.ravel().astype(bool)
            inlier_count = int(inlier_mask.sum())

            # Inlier ratio: if too few candidates survive RANSAC, it's unreliable
            inlier_ratio = inlier_count / len(good)
            if inlier_count < min_inliers or inlier_ratio < 0.30:
                continue

            h_ref, w_ref = gray_ref.shape
            pts_ref = np.float32([[0, 0], [0, h_ref - 1],
                                   [w_ref - 1, h_ref - 1], [w_ref - 1, 0]]).reshape(-1, 1, 2)
            dst = cv.perspectiveTransform(pts_ref, M)

            if scale != 1.0:
                dst = dst / scale

            if not is_valid_quadrilateral(dst, target_img.shape[:2]):
                continue

            if inlier_count > best_inliers:
                best_inliers = inlier_count
                inlier_good = [good[i] for i in range(len(good)) if inlier_mask[i]]
                match_vis = cv.drawMatches(
                    ref_img, kp1, current_target, kp2, inlier_good, None,
                    flags=cv.DrawMatchesFlags_NOT_DRAW_SINGLE_POINTS
                )
                confidence = min(100, int((inlier_count / 25.0) * 100))
                best_result = (dst, match_vis, confidence, inlier_count)

    if best_result is not None:
        dst, match_vis, confidence, inlier_count = best_result
        result_img = target_img.copy()
        result_img = cv.polylines(result_img, [np.int32(dst)], True, (0, 255, 0), 3, cv.LINE_AA)
        return result_img, True, dst, match_vis, (confidence, inlier_count)

    return target_img, False, None, None, (0, 0)


def main():
    script_dir = os.path.dirname(os.path.abspath(__file__))

    sift = cv.SIFT_create()
    FLANN_INDEX_KDTREE = 1
    index_params = dict(algorithm=FLANN_INDEX_KDTREE, trees=5)
    search_params = dict(checks=50)
    flann = cv.FlannBasedMatcher(index_params, search_params)

    img_dir = os.path.join(script_dir, "zdjecia")
    # kaucja50.jpg (113x79 px) is too small for reliable structural matching —
    # its SIFT features are almost entirely from text, not arrows/frame.
    # We upscale it so the structural features are preserved.
    REF_NAMES = {"kaucja.png", "kaucja50.jpg"}

    ref_imgs = []
    for name in REF_NAMES:
        path = os.path.join(img_dir, name)
        img = cv.imread(path)
        if img is None:
            print(f"Ostrzezenie: nie mozna wczytac referencji {name}")
            continue
        # Upscale small references so arrow structures are visible to SIFT
        h_r, w_r = img.shape[:2]
        if max(h_r, w_r) < 300:
            scale_up = 300 / max(h_r, w_r)
            img = cv.resize(img, (int(w_r * scale_up), int(h_r * scale_up)),
                            interpolation=cv.INTER_CUBIC)
        ref_imgs.append(img)

    if not ref_imgs:
        print("Blad: brak obrazow referencyjnych.")
        return

    print(f"=== System Rozpoznawania Etykiet Kaucyjnych ===")
    print(f"Zaladowano {len(ref_imgs)} obraz(ow) referencyjnych.")
    print("1. Identyfikacja automatyczna krok po kroku (folder 'zdjecia')")
    print("2. Identyfikacja na zywo (webcam)")

    choice = input("Wybierz opcje (1/2): ")

    if choice == '1':
        print("\n" + "=" * 50)
        print("URUCHAMIAM IDENTYFIKACJE AUTOMATYCZNA")
        print("=" * 50)
        print("Instrukcja: Dowolny klawisz - nastepne zdjecie, 'q' - przerwij.")
        print("AUTOMATYCZNE PRZEWIJANIE: Co 5 sekund.\n")

        all_files = sorted(
            [f for f in os.listdir(img_dir)
             if f.lower().endswith(('.png', '.jpg', '.jpeg', '.webp'))],
            key=natural_sort_key
        )
        images = [f for f in all_files if f not in REF_NAMES]

        stats = {"total": 0, "found": 0}

        for filename in images:
            img_path = os.path.join(img_dir, filename)
            img = cv.imread(img_path)
            if img is None:
                continue

            stats["total"] += 1
            print(f"[{stats['total']}/{len(images)}] Przetwarzanie: {filename:<25}", end=" ", flush=True)

            h, w = img.shape[:2]
            max_dim = 800
            if max(h, w) > max_dim:
                scale_disp = max_dim / max(h, w)
                img_disp = cv.resize(img, (int(w * scale_disp), int(h * scale_disp)))
            else:
                img_disp = img.copy()

            result_img, found, _, match_vis, conf_data = detect_kaucja(
                img_disp, ref_imgs, sift, flann
            )
            conf_val, match_count = conf_data

            if found:
                stats["found"] += 1
                print(f"-> [ZNALEZIONO] Inliery: {match_count}, Pewnosc: {conf_val}%")
                cv.putText(result_img, f"KAUCJA WYKRYTA ({conf_val}%)", (10, 30),
                           cv.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
                cv.putText(result_img, f"Inliery RANSAC: {match_count}", (10, 60),
                           cv.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 0), 1)
                cv.imshow("Krok 1: Dopasowanie punktow (SIFT - inliery)", match_vis)
                cv.imshow("Krok 2: Detekcja (Homografia)", result_img)
            else:
                print("-> [NIE ZNALEZIONO]")
                cv.putText(result_img, "BRAK KAUCJI", (10, 30),
                           cv.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
                cv.imshow("Krok 2: Detekcja (Homografia)", result_img)

            key = cv.waitKey(5000)
            cv.destroyAllWindows()

            if key == ord('q'):
                print("\nPrzerwano przez uzytkownika.")
                break

        print("\n" + "=" * 50)
        print("PODSUMOWANIE PRZETWARZANIA")
        print(f"Przetworzono plikow: {stats['total']}")
        print(f"Wykryto znakow:      {stats['found']}")
        print(f"Skutecznosc:         {(stats['found'] / stats['total'] * 100 if stats['total'] > 0 else 0):.1f}%")
        print("=" * 50)
        cv.waitKey(0)

    elif choice == '2':
        print("\nUruchamiam identyfikacje z kamerki... (Nacisnij 'q' aby wyjsc)")
        cap = cv.VideoCapture(0)

        if not cap.isOpened():
            print("Blad: Nie mozna otworzyc kamerki.")
            return

        while True:
            ret, frame = cap.read()
            if not ret:
                print("Nie mozna pobrac klatki.")
                break

            result_frame, found, _, match_vis, conf_data = detect_kaucja(
                frame, ref_imgs, sift, flann
            )

            if found:
                conf_val, match_count = conf_data
                cv.putText(result_frame, f"KAUCJA WYKRYTA ({conf_val}%)", (10, 30),
                           cv.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
                cv.putText(result_frame, f"Inliery: {match_count}", (10, 65),
                           cv.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 0), 2)
                if match_vis is not None:
                    cv.imshow("Dopasowania SIFT (inliery)", match_vis)
            else:
                cv.putText(result_frame, "BRAK KAUCJI", (10, 30),
                           cv.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

            cv.imshow("Webcam - Identyfikacja Kaucji", result_frame)

            if cv.waitKey(1) & 0xFF == ord('q'):
                break

        cap.release()
        cv.destroyAllWindows()

    else:
        print("Nieprawidlowy wybor.")


if __name__ == "__main__":
    main()
