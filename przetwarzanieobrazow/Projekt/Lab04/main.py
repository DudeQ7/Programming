#l03
import cv2 as cv 
import numpy as np 
#przetwarzanieobrazow/Projekt/assets/l03/1jpg
image = cv.imread("przetwarzanieobrazow\\Projekt\\assets\\l03\\1.jpg")
image_gray = cv.cvtColor(image,cv.COLOR_BGR2GRAY)
cv.imshow("hyps",image)
cv.imshow("gray",image_gray)
cv.waitKey(0)