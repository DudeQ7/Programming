import cv2 as cv  
import os
dir_path  = '/mnt/shared/Programming/Python/przetwarzanieobrazow/Projekt2[Lab07-Lab12]/Kod_1_Lab07'
os.chdir(dir_path)
photo_1 = cv.imread('test.jpg')
cv.imshow("zdjecie", photo_1)
cv.waitKey(0)