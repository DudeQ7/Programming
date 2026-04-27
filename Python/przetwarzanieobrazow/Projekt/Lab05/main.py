import cv2 as cv 
image = cv.imread("przetwarzanieobrazow/Projekt/assets/l04/Shopping-basket-info-256.png")
image2 = cv.imread("przetwarzanieobrazow/Projekt/assets/l04/Shopping-basket-remove-256.png")
cv.imshow("hyps",image)
cv.imshow("hyps2",image2)
cv.waitKey(0)