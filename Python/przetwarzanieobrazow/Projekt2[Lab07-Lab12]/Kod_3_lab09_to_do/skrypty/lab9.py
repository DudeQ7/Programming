# -*- coding: utf-8 -*-
"""
Created on Mon May 18 21:45:00 2026

@author: Magda
"""

import cv2
import numpy as np

# Wczytanie obrazu w odcieniach szarości
img = cv2.imread("C:\\Users\\Magda\\Desktop\\POC\\metody\\lab13\\sheet_paper.JPEG", cv2.IMREAD_GRAYSCALE)
#img = cv2.imread("C:\\Users\\Magda\\Desktop\\POC\\obraz_odblask.jpg", cv2.IMREAD_GRAYSCALE)
img2 = cv2.imread("C:\\Users\\Magda\\Desktop\\POC\\obraz.jpg", cv2.IMREAD_GRAYSCALE)

# Utworzenie obiektu CLAHE z określonym limitem kontrastu i rozmiarem kafelka
clahe = cv2.createCLAHE(clipLimit=2.0, tileGridSize=(8, 8))
clahe_img = clahe.apply(img2)

cv2.imshow('clahe_output.jpg', clahe_img)
cv2.waitKey(0)
cv2.destroyAllWindows()

# Globalne wyrównanie histogramu
equalized_img = cv2.equalizeHist(img2)

cv2.imshow('equalized_output.jpg', equalized_img)
cv2.waitKey(0)
cv2.destroyAllWindows()

# alfa=1.5 (zwiększenie kontrastu o 50%), beta=0 (bez zmian jasności)
contrast_img = cv2.convertScaleAbs(img, alpha=1.5, beta=0)

cv2.imshow('linear_output.jpg', contrast_img)
cv2.waitKey(0)
cv2.destroyAllWindows()

# Wartość gamma < 1.0 rozjaśnia cienie, gamma > 1.0 przyciemnia obraz
gamma = 0.6  
lookUpTable = np.empty((1, 256), np.uint8)

for i in range(256):
    lookUpTable[0, i] = np.clip(pow(i / 255.0, gamma) * 255.0, 0, 255)

gamma_img = cv2.LUT(img, lookUpTable)

cv2.imshow('gamma_output.jpg', gamma_img)
cv2.waitKey(0)
cv2.destroyAllWindows()