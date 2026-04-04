import cv2 as cv
import numpy as np 
import matplotlib.pyplot as plt 
def rgb(r,g,b):
    return (b,g,r)
image = cv.imread("przetwarzanieobrazow\\Projekt\\assets\\card1.jpg")
b_mod,g_mod,r_mod = cv.split(image)
b_mod,g_mod,r_mod = cv.split(image)
hsv_image = cv.cvtColor(image,cv.COLOR_BGR2HSV)
yuv_image = cv.cvtColor(image,cv.COLOR_BGR2YUV)
gray_image = gray_avg = ((r_mod.astype(float) + g_mod.astype(float) + b_mod.astype(float)) / 3).astype(np.uint8)
gray_image_2 = (0.299 * r_mod + 0.587 * g_mod + 0.114 * b_mod).astype(np.uint8)
wynik = np.hstack((image,hsv_image,yuv_image))
wynik2 = np.hstack((gray_image,gray_image_2))
cv.imshow("Kanaly",wynik)
cv.imshow("Szarosc",wynik2)
plt.hist(r_mod.ravel(),bins=256,color='red',alpha=0.5,label='Red')
plt.hist(g_mod.ravel(),bins=256,color='green',alpha=0.5,label='Green')
plt.hist(b_mod.ravel(),bins=256,color='blue',alpha=0.5,label='Blue')

plt.legend()
plt.show()
cv.waitKey(0)
cv.destroyAllWindows()