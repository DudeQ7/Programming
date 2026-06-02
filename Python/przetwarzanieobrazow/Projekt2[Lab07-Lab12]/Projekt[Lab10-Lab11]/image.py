import cv2 as cv 
import numpy as np
import os 
os.chdir("/mnt/shared/Programming/Python/przetwarzanieobrazow/Projekt2[Lab07-Lab12]/Projekt[Lab10-Lab11]")
img_rgb = cv.imread("zdjecia/1.jpg")
cv.imshow("Image",img_rgb)
cv.waitKey(0)
cv.destroyAllWindows()