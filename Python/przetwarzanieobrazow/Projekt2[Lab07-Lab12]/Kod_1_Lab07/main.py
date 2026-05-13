import cv2 as cv  
import numpy as np
import os
dir_path  = '/mnt/shared/Programming/Python/przetwarzanieobrazow/Projekt2[Lab07-Lab12]/Kod_1_Lab07'
os.chdir(dir_path)
photo_1 = cv.imread('test.jpg')
gray = cv.cvtColor(photo_1,cv.COLOR_BGR2GRAY) #converting to gray for easier detection
edges = cv.Canny(gray,30,200)
cv.waitKey(0)
#recognising
contours,hierarchy = cv.findContours(edges,cv.RETR_EXTERNAL,cv.CHAIN_APPROX_NONE)
cv.imshow("Obraz z wykrytymi konturami", edges)
cv.drawContours(photo_1,contours,-1,(0,255,0),3)
cv.imshow("Kontury",photo_1)
print("Liczba wykrytych konturów: " + str(len(contours)))
cv.waitKey(0)
cv.destroyAllWindows()
#Todo: 1. Aproksymacja kształtów (Liczba boków)Zgodnie z instrukcją, powinieneś użyć funkcji approxPolyDP, aby określić liczbę boków figury. To pozwoli Ci odróżnić np. trójkąt od prostokąta.  3 boki: trójkąt4 boki: kwadrat / prostokąt / rombWięcej boków: koło / elipsa2. Analiza koloruInstrukcja wymaga pobrania pikseli z wnętrza obiektu i zanalizowania ich wartości w przestrzeni kolorów (np. RGB).  Musisz zdefiniować przedziały dla kolorów (np. czerwony to $R > 150, G < 50, B < 50$).  Warto pobrać próbkę pikseli ze środka ciężkości konturu (możesz go wyznaczyć za pomocą tzw. momentów — cv.moments).3. Podpisywanie obiektówZadanie wymaga umieszczenia tekstu informującego o kształcie i kolorze bezpośrednio na obrazie za pomocą funkcji putText. Obecnie skrypt tylko wypisuje liczbę konturów w konsoli.  