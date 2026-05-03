import cv2 as cv 
import numpy as np 
from pathlib import Path
ASSETS_PATH = "/mnt/shared/Programming/Python/przetwarzanieobrazow/Projekt/assets/Lab03/"
def get_histogram_peak_threshold(image_gray):
    hist = cv.calcHist([image_gray], [0], None, [256], [0, 256])
    peak_value = np.argmax(hist)
    return peak_value
def binary_threshold_interactive(image_gray, window_name="Binary Threshold Interactive"):
    cv.namedWindow(window_name)
    def on_trackbar(value):
        binary = cv.threshold(image_gray, value, 255, cv.THRESH_BINARY)[1]
        cv.imshow(window_name, binary)
    cv.createTrackbar("Próg", window_name, 127, 255, on_trackbar)
    on_trackbar(127)
    cv.waitKey(0)
    cv.destroyWindow(window_name)
    threshold_value = cv.getTrackbarPos("Próg", window_name)
    return threshold_value
def binary_threshold_manual(image_gray, threshold_value):
    _, binary = cv.threshold(image_gray, threshold_value, 255, cv.THRESH_BINARY)
    return binary
def binary_threshold_histogram(image_gray):
    threshold_value = get_histogram_peak_threshold(image_gray)
    _, binary = cv.threshold(image_gray, threshold_value, 255, cv.THRESH_BINARY)
    return binary, threshold_value
def multi_level_thresholding(image_gray, threshold1, threshold2):
    multi_thresh = np.zeros_like(image_gray)
    multi_thresh[image_gray < threshold1] = 0
    multi_thresh[(image_gray >= threshold1) & (image_gray < threshold2)] = 85
    multi_thresh[image_gray >= threshold2] = 170
    return multi_thresh
def display_results(image_gray, image_original):
    while True:
        print("\n" + "="*60)
        print("MENU - Binaryzacja i Multiprogowanie")
        print("="*60)
        print("1. Binaryzacja - próg podany przez użytkownika (interaktywnie)")
        print("2. Binaryzacja - próg z histogramu (największy pik)")
        print("3. Multiprogowanie - dwa progi podane przez użytkownika")
        print("4. Wyświetl oryginał")
        print("5. Wyświetl obraz w skali szarości")
        print("0. Wyjście")
        print("="*60)
        choice = input("Wybierz operację (0-5): ").strip()
        if choice == "1":
            print("\nOtworzy się okno z trackbarem. Dostosuj próg i naciśnij klawisz aby zatwierdzić.")
            cv.namedWindow("Binaryzacja - Interaktywny próg") 
            def on_trackbar(value):
                binary = cv.threshold(image_gray, value, 255, cv.THRESH_BINARY)[1]
                cv.imshow("Binaryzacja - Interaktywny próg", binary)
            cv.createTrackbar("Próg (0-255)", "Binaryzacja - Interaktywny próg", 127, 255, on_trackbar)
            on_trackbar(127)
            print("Naciśnij dowolny klawisz aby zatwierdzić...")
            cv.waitKey(0)
            cv.destroyWindow("Binaryzacja - Interaktywny próg")
        elif choice == "2":
            threshold_value = get_histogram_peak_threshold(image_gray)
            binary, _ = binary_threshold_histogram(image_gray)
            print(f"\nZnaleziony próg z histogramu: {threshold_value}")
            cv.imshow("Binaryzacja - Próg z histogramu", binary)
            print("Naciśnij dowolny klawisz aby kontynuować...")
            cv.waitKey(0)
            cv.destroyWindow("Binaryzacja - Próg z histogramu")
        elif choice == "3":
            try:
                thresh1_str = input("Podaj pierwszy próg (0-255): ").strip()
                thresh2_str = input("Podaj drugi próg (0-255): ").strip()   
                thresh1 = int(thresh1_str)
                thresh2 = int(thresh2_str)    
                if not (0 <= thresh1 <= 255 and 0 <= thresh2 <= 255):
                    print("Próg musi być w zakresie 0-255!")
                    continue          
                if thresh1 >= thresh2:
                    print("Pierwszy próg musi być mniejszy od drugiego!")
                    continue          
                multi_result = multi_level_thresholding(image_gray, thresh1, thresh2)
                print(f"\nMultiprogowanie: Próg1={thresh1}, Próg2={thresh2}")
                print("Poziomy: 0 (czarny) | 85 (szary) | 170 (jasny)")
                cv.imshow("Multiprogowanie", multi_result)
                print("Naciśnij dowolny klawisz aby kontynuować...")
                cv.waitKey(0)
                cv.destroyWindow("Multiprogowanie")             
            except ValueError:
                print("Błąd! Proszę podać liczby całkowite.")             
        elif choice == "4":
            cv.imshow("Oryginał", image_original)
            print("Naciśnij dowolny klawisz aby kontynuować...")
            cv.waitKey(0)
            cv.destroyWindow("Oryginał")        
        elif choice == "5":
            cv.imshow("Skala szarości", image_gray)
            print("Naciśnij dowolny klawisz aby kontynuować...")
            cv.waitKey(0)
            cv.destroyWindow("Skala szarości")         
        elif choice == "0":
            print("Wyjście z programu.")
            break        
        else:
            print("Nieprawidłowy wybór! Spróbuj ponownie.")
def main():
    print("Dostępne obrazy:")
    images = ["1.jpg", "2.jpg", "3.jpg", "4.jpg"]
    for i, img in enumerate(images, 1):
        print(f"{i}. {img}")
    choice = input("Wybierz numer obrazu (1-4): ").strip()
    if choice not in ["1", "2", "3", "4"]:
        print("Nieprawidłowy wybór!")
        return
    image_path = ASSETS_PATH + images[int(choice) - 1]
    try:
        image = cv.imread(image_path)
        if image is None:
            print(f"Nie udało się załadować obrazu: {image_path}")
            return
        image_gray = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
        print(f"\nZaładowano obraz: {images[int(choice) - 1]}")
        display_results(image_gray, image)
    except Exception as e:
        print(f"Błąd: {e}")
    cv.destroyAllWindows()
if __name__ == "__main__":
    main()