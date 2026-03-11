#punkt wejscia do programu uruchamia GUI
#opencv ma BGR 
import cv2 
def rgb(r,g,b):
    return(b,g,r)
image = cv2.imread('C:\\Users\\DudeQ\\Documents\\programming\\przetwarzanieobrazow\\Projekt\\assets\\card.jpg')
gray_image = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
#magenta = cv2.cvtColor(image,cv2.rgb(255,0,255))
cv2.imshow("Default",image)
cv2.imshow("Grayscale",gray_image)
#cv2.imshow("Magenta",magenta)
cv2.destroyAllWindows()