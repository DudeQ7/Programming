import cv2 as cv
import numpy as np
import os

# Konfiguracja ścieżki
dir_path = os.path.dirname(os.path.realpath(__file__))
image_path = os.path.join(dir_path, "1.png")
subtracted_path = os.path.join(dir_path, "2.png")

# Wczytywanie obrazów
img = cv.imread(image_path)
sub = cv.imread(subtracted_path)

if img is None or sub is None:
    print("Błąd: Nie można wczytać obrazów. Sprawdź, czy 1.png i 2.png istnieją w folderze Lab05!")
    exit()

# Konwersja na odcienie szarości
img_gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
sub_gray = cv.cvtColor(sub, cv.COLOR_BGR2GRAY)

# --- 1. ODEJMOWANIE ---
result_diff = cv.absdiff(img_gray, sub_gray)

# --- 2. WYKRYWANIE KRAWĘDZI (Poziome) ---
shifted_h = np.roll(img_gray, 1, axis=1)
edges_h = cv.absdiff(img_gray, shifted_h)

# --- 3. OPERACJE GEOMETRYCZNE ---
rows, cols = img_gray.shape

# Obrót (45 stopni)
rotation_matrix = cv.getRotationMatrix2D((cols/2, rows/2), 45, 1)
rotated = cv.warpAffine(img_gray, rotation_matrix, (cols, rows))

# Skalowanie (używamy oryginału, aby nie tracić jakości)
scaled = cv.resize(img_gray, None, fx=0.8, fy=0.8, interpolation=cv.INTER_LINEAR)

# --- 4. WYŚWIETLANIE OBOK SIEBIE ---
# Przygotowanie listy obrazów do wyświetlenia (muszą mieć tę samą liczbę kanałów - gray)
# Uwaga: obraz 'scaled' musimy dopasować rozmiarem do 'img_gray', 
# żeby przy łączeniu nie było błędu wymiarów
scaled_resized = cv.resize(scaled, (cols, rows)) 

images_to_show = [img_gray, result_diff, edges_h, rotated, scaled_resized]

# Wyliczanie rozmiarów płótna
h_max = img_gray.shape[0]
w_sum = sum(img.shape[1] for img in images_to_show)

# Tworzenie pustego płótna
combined = np.zeros((h_max, w_sum), dtype=np.uint8)

# Wklejanie obrazów
curr_x = 0
for img_item in images_to_show:
    combined[0:h_max, curr_x:curr_x + img_item.shape[1]] = img_item
    curr_x += img_item.shape[1]

# Wyświetlenie wyniku
cv.imshow("Analiza Obrazu - Lab 05", combined)

print("Naciśnij dowolny klawisz w oknie z obrazem, aby zamknąć.")
cv.waitKey(0)
cv.destroyAllWindows()