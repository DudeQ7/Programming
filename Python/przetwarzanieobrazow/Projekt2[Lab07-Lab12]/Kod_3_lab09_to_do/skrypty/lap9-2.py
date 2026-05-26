# -*- coding: utf-8 -*-
"""
Created on Mon May 18 22:04:09 2026

@author: Magda
"""
import cv2

# 1. Wczytanie obrazu
img = cv2.imread("C:\\Users\\Magda\\Desktop\\POC\\obraz_odblask.jpg")
h, w, _ = img.shape

# 2. Definiujemy obszar oczu (ROI) - wartości dopasowane do Twojego zdjęcia
# Wycinamy tylko pas z okularami, żeby algorytm nie patrzył na tło i koszulkę
ymin, ymax = int(h * 0.2), int(h * 0.32)
xmin, xmax = int(w * 0.35), int(w * 0.65)

roi = img[ymin:ymax, xmin:xmax]

# 3. Konwersja ROI do odcieni szarości
gray_roi = cv2.cvtColor(roi, cv2.COLOR_BGR2GRAY)

# 4. Progowanie adaptacyjne (szukamy lokalnych maksimów jasności na skórze i oku)
# Zamiast stałej wartości (np. 240), szukamy pikseli wyraźnie jaśniejszych od otoczenia
local_thresh = cv2.adaptiveThreshold(
    gray_roi, 255, cv2.ADAPTIVE_THRESH_MEAN_C, 
    cv2.THRESH_BINARY, 51, -30
)

# 5. Oczyszczenie maski z drobnych szumów
kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (3, 3))
mask_roi = cv2.morphologyEx(local_thresh, cv2.MORPH_OPEN, kernel)
mask_roi = cv2.dilate(mask_roi, kernel, iterations=1)

# 6. Naprawa (Inpainting) tylko w obszarze ROI
roi_repaired = cv2.inpaint(roi, mask_roi, inpaintRadius=5, flags=cv2.INPAINT_TELEA)

# 7. Wklejenie naprawionego obszaru z powrotem do oryginalnego zdjęcia
result = img.copy()
result[ymin:ymax, xmin:xmax] = roi_repaired

# Zapisanie wyniku
cv2.imshow('okulary_poprawione.jpg', result)
cv2.waitKey(0)
cv2.destroyAllWindows()
