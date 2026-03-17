import cv2 as cv 
import numpy as np 
def rgb(r,g,b):
    return (b,g,r)
img = np.zeros((400,400,3),dtype=np.uint8)
image = cv.imread("przetwarzanieobrazow/Projekt/assets/card.jpg")
#lewa polowa 
img[0:200,0:200] = rgb(128,128,128)
img[0:200,200:400] = rgb(255,0,255)
img[200:400,0:200] = rgb(255,255,0)
img[200:400,200:400] = rgb(0,0,255)
kanal_blue,kanal_green,kanal_red = cv.split(image) 
zeros = np.zeros_like(kanal_blue)
blue_colored = cv.merge([kanal_blue,zeros,zeros])
green_colored = cv.merge([zeros,kanal_green,zeros])
red_colored = cv.merge([zeros,zeros,kanal_red])
gora = np.hstack((image,blue_colored))
dol = np.hstack((green_colored,red_colored))
wynik = np.vstack((gora,dol))
cv.imshow("kanaly",wynik)
cv.imshow("Gotowe",img)
cv.waitKey(0)
cv.destroyAllWindows()