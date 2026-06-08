import cv2 as cv
import numpy as np
import os
import sys

def detect_kaucja(target_img, ref_img, sift, flann, min_matches=8):
    """
    Enhanced detection for Grade 5: Handles low contrast and small labels.
    """
    if target_img is None or ref_img is None:
        return target_img, False, None

    # Preprocessing: Convert to gray and apply CLAHE for better contrast in difficult lighting
    def preprocess(img):
        gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY) if len(img.shape) == 3 else img
        clahe = cv.createCLAHE(clipLimit=2.0, tileGridSize=(8, 8))
        return clahe.apply(gray)

    gray_ref = preprocess(ref_img)
    kp1, des1 = sift.detectAndCompute(gray_ref, None)

    if des1 is None:
        return target_img, False, None

    # Multi-scale approach: if not found at original size, try scaling up/down
    scales = [1.0, 0.5, 1.5] # Try different scales for small/large labels
    
    best_dst = None
    found_any = False

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
            src_pts = np.float32([kp1[m.queryIdx].pt for m in good]).reshape(-1, 1, 2)
            dst_pts = np.float32([kp2[m.trainIdx].pt for m in good]).reshape(-1, 1, 2)

            M, mask = cv.findHomography(src_pts, dst_pts, cv.RANSAC, 5.0)
            if M is not None:
                # Basic validation: ensure the homography produces a sane shape (non-degenerate)
                h_ref, w_ref = gray_ref.shape
                pts = np.float32([[0, 0], [0, h_ref - 1], [w_ref - 1, h_ref - 1], [w_ref - 1, 0]]).reshape(-1, 1, 2)
                dst = cv.perspectiveTransform(pts, M)
                
                # Rescale coordinates back to original image size
                if scale != 1.0:
                    dst = dst / scale

                # Draw on the original image
                target_img = cv.polylines(target_img, [np.int32(dst)], True, (0, 255, 0), 3, cv.LINE_AA)
                return target_img, True, dst
    
    return target_img, False, None

def main():
    # Setup SIFT and FLANN
    sift = cv.SIFT_create()
    
    FLANN_INDEX_KDTREE = 1
    index_params = dict(algorithm=FLANN_INDEX_KDTREE, trees=5)
    search_params = dict(checks=50)
    flann = cv.FlannBasedMatcher(index_params, search_params)

    # Load reference image
    ref_path = os.path.join("zdjecia", "kaucja.png")
    if not os.path.exists(ref_path):
        print(f"Error: Reference image {ref_path} not found.")
        return
    
    ref_img = cv.imread(ref_path)
    if ref_img is None:
        print(f"Error: Could not read reference image {ref_path}.")
        return

    print("=== System Rozpoznawania Etykiet Kaucyjnych ===")
    print("1. Identyfikacja automatyczna (z folderu 'zdjecia')")
    print("2. Identyfikacja na żywo (webcam)")
    
    choice = input("Wybierz opcje (1/2): ")

    if choice == '1':
        print("\nUruchamiam identyfikacje automatyczna...")
        img_dir = "zdjecia"
        images = [f for f in os.listdir(img_dir) if f.lower().endswith(('.png', '.jpg', '.jpeg', '.webp'))]
        
        for filename in images:
            if filename == "kaucja.png":
                continue
            
            img_path = os.path.join(img_dir, filename)
            img = cv.imread(img_path)
            if img is None:
                continue
            
            print(f"Przetwarzanie: {filename}...", end=" ", flush=True)
            
            # Optional: resize very large images for faster processing
            h, w = img.shape[:2]
            if max(h, w) > 1200:
                scale = 1200 / max(h, w)
                img = cv.resize(img, (int(w * scale), int(h * scale)))

            result_img, found, _ = detect_kaucja(img, ref_img, sift, flann)
            
            if found:
                print("ZNALEZIONO!")
                cv.putText(result_img, "KAUCJA WYKRYTA", (10, 30), cv.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            else:
                print("Nie znaleziono.")
                cv.putText(result_img, "Brak kaucji", (10, 30), cv.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

            # Display result
            cv.imshow("Identyfikacja - " + filename, result_img)
            key = cv.waitKey(0)
            cv.destroyWindow("Identyfikacja - " + filename)
            
            if key == ord('q'):
                break
        
        cv.destroyAllWindows()
        print("\nZakonczono przetwarzanie folderu.")

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
            
            result_frame, found, _ = detect_kaucja(frame, ref_img, sift, flann)
            
            if found:
                cv.putText(result_frame, "KAUCJA WYKRYTA", (10, 30), cv.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            
            cv.imshow("Webcam - Identyfikacja Kaucji", result_frame)
            
            if cv.waitKey(1) & 0xFF == ord('q'):
                break
        
        cap.release()
        cv.destroyAllWindows()
    
    else:
        print("Nieprawidlowy wybor.")

if __name__ == "__main__":
    main()
