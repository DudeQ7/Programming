import cv2 as cv
import numpy as np
import os
import sys
import re

def natural_sort_key(s):
   #sortowanie zdjec 
    return [int(text) if text.isdigit() else text.lower()
            for text in re.split('([0-9]+)', s)]

def detect_kaucja(target_img, ref_img, sift, flann, min_matches=8):
    if target_img is None or ref_img is None:
        return target_img, False, None, None, (0, 0)
    # Preprocessing: Zamiana na szary, dodanie CLAHE dla lepszej detekcji w trudnych warunkach
    def preprocess(img):
        gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY) if len(img.shape) == 3 else img
        clahe = cv.createCLAHE(clipLimit=2.0, tileGridSize=(8, 8))
        return clahe.apply(gray)
    gray_ref = preprocess(ref_img)
    kp1, des1 = sift.detectAndCompute(gray_ref, None)
    if des1 is None:
        return target_img, False, None, None, (0, 0)
    scales = [1.0, 0.5, 1.5]

    for scale in scales:
        if scale == 1.0:
            current_target = target_img
        else:
            w = int(target_img.shape[1] * scale)
            h = int(target_img.shape[0] * scale)
            current_target = cv.resize(target_img, (w, h))
        gray_target = preprocess(current_target)
        kp2, des2 = sift.detectAndCompute(gray_target, None)
        if des2 is None: continue
        matches = flann.knnMatch(des1, des2, k=2)
        good = [m for m, n in matches if m.distance < 0.75 * n.distance]
        if len(good) >= min_matches:
            match_vis = cv.drawMatches(ref_img, kp1, current_target, kp2, good, None, 
                                     flags=cv.DrawMatchesFlags_NOT_DRAW_SINGLE_POINTS)
            src_pts = np.float32([kp1[m.queryIdx].pt for m in good]).reshape(-1, 1, 2)
            dst_pts = np.float32([kp2[m.trainIdx].pt for m in good]).reshape(-1, 1, 2)

            M, mask = cv.findHomography(src_pts, dst_pts, cv.RANSAC, 5.0)
            if M is not None:
                h_ref, w_ref = gray_ref.shape
                pts = np.float32([[0, 0], [0, h_ref - 1], [w_ref - 1, h_ref - 1], [w_ref - 1, 0]]).reshape(-1, 1, 2)
                dst = cv.perspectiveTransform(pts, M)

                if scale != 1.0:
                    dst = dst / scale

                target_img_res = target_img.copy()
                target_img_res = cv.polylines(target_img_res, [np.int32(dst)], True, (0, 255, 0), 3, cv.LINE_AA)

                # Oblicznie pewnosci na podstawie liczby dobrych dopasowan (min_matches to 8, 30+ to bardzo silne dopasowanie)
                confidence = min(100, int((len(good) / 25.0) * 100))

                return target_img_res, True, dst, match_vis, (confidence, len(good))

    return target_img, False, None, None, (0, 0)

def main():
    script_dir = os.path.dirname(os.path.abspath(__file__))
    
    # Sift i FLANN
    sift = cv.SIFT_create()
    
    FLANN_INDEX_KDTREE = 1
    index_params = dict(algorithm=FLANN_INDEX_KDTREE, trees=5)
    search_params = dict(checks=50)
    flann = cv.FlannBasedMatcher(index_params, search_params)

    ref_path = os.path.join(script_dir, "zdjecia", "kaucja.png")
    if not os.path.exists(ref_path):
        print(f"Error: Reference image {ref_path} not found.")
        return
    
    ref_img = cv.imread(ref_path)
    if ref_img is None:
        print(f"Error: Could not read reference image {ref_path}.")
        return

    print("=== System Rozpoznawania Etykiet Kaucyjnych (OCENA 5) ===")
    print("1. Identyfikacja automatyczna krok po kroku (z folderu 'zdjecia')")
    print("2. Identyfikacja na żywo (webcam)")
    
    choice = input("Wybierz opcje (1/2): ")

    if choice == '1':
        print("\n" + "="*50)
        print("URUCHAMIAM IDENTYFIKACJE AUTOMATYCZNA")
        print("="*50)
        print("Instrukcja: Dowolny klawisz - nastepne zdjecie, 'q' - przerwij.")
        print("AUTOMATYCZNE PRZEWIJANIE: Co 5 sekund.\n")
        
        img_dir = os.path.join(script_dir, "zdjecia")
        # Pobieramy i sortujemy pliki, aby szly kolejno (1, 2, 3...)
        images = sorted([f for f in os.listdir(img_dir) if f.lower().endswith(('.png', '.jpg', '.jpeg', '.webp'))],
                        key=natural_sort_key)
        
        stats = {"total": 0, "found": 0}
        
        for filename in images:
            if filename == "kaucja.png":
                continue
            
            img_path = os.path.join(img_dir, filename)
            img = cv.imread(img_path)
            if img is None:
                continue
            
            stats["total"] += 1
            print(f"[{stats['total']}/{len(images)-1}] Przetwarzanie: {filename:<20}", end=" ", flush=True)
            
            # Przeskalowanie do wyswietlania (zachowujemy proporcje)
            h, w = img.shape[:2]
            max_dim = 800
            if max(h, w) > max_dim:
                scale_disp = max_dim / max(h, w)
                img_disp = cv.resize(img, (int(w * scale_disp), int(h * scale_disp)))
            else:
                img_disp = img.copy()

            result_img, found, _, match_vis, conf_data = detect_kaucja(img_disp, ref_img, sift, flann)
            conf_val, match_count = conf_data
            
            if found:
                stats["found"] += 1
                print(f"-> [ZNALEZIONO] Pewnosc: {conf_val}%")
                cv.putText(result_img, f"KAUCJA WYKRYTA ({conf_val}%)", (10, 30), 
                           cv.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
                cv.putText(result_img, f"Punkty: {match_count}", (10, 60), 
                           cv.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 0), 1)
                
                cv.imshow("Krok 1: Dopasowanie punktow (SIFT)", match_vis)
                cv.imshow("Krok 2: Detekcja (Homografia)", result_img)
            else:
                print("-> [NIE ZNALEZIONO]")
                cv.putText(result_img, f"BRAK KAUCJI", (10, 30), 
                           cv.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
                cv.imshow("Krok 2: Detekcja (Homografia)", result_img)

            # Czekamy 5 sekund (5000ms) lub na klawisz
            key = cv.waitKey(5000)
            cv.destroyAllWindows()
            
            if key == ord('q'):
                print("\nPrzerwano przez uzytkownika.")
                break
        
        print("\n" + "="*50)
        print("PODSUMOWANIE PRZETWARZANIA")
        print(f"Przetworzono plikow: {stats['total']}")
        print(f"Wykryto znaczkow:     {stats['found']}")
        print(f"Skutecznosc:          {(stats['found']/stats['total']*100 if stats['total']>0 else 0):.1f}%")
        print("="*50)
        print("Nacisnij dowolny klawisz, aby zakonczyc.")
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
                print("Nie mozna pobrac klatki z kamerki.")
                break
            
            result_frame, found, _, match_vis, conf_data = detect_kaucja(frame, ref_img, sift, flann)
            
            if found:
                conf_val, _ = conf_data
                cv.putText(result_frame, f"KAUCJA WYKRYTA ({conf_val}%)", (10, 30), 
                           cv.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
                if match_vis is not None:
                    cv.imshow("Dopasowania SIFT", match_vis)
            
            cv.imshow("Webcam - Identyfikacja Kaucji", result_frame)
            
            if cv.waitKey(1) & 0xFF == ord('q'):
                break
        
        cap.release()
        cv.destroyAllWindows()
    
    else:
        print("Nieprawidlowy wybor.")

if __name__ == "__main__":
    main()
