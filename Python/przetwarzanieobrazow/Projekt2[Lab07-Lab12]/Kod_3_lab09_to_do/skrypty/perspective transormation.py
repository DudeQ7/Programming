import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread("C:\\Users\\Magda\\Desktop\\POC\\metody\\lab13\\sheet_paper.JPEG")

#punkty wyznaczające perspektywę
cv2.circle(img, (470, 206), 5, (0, 0, 255), -1)
cv2.circle(img, (1479, 198), 5, (0, 0, 255), -1)
cv2.circle(img, (32, 1122), 5, (0, 0, 255), -1)
cv2.circle(img, (1980, 1125), 5, (0, 0, 255), -1)

plt.imshow(img)
plt.show()

#wektor punktów z widoku (punkty są przepisane) 
pts1 = np.float32([[470, 206], [1479, 198], [32, 1122], [1980, 1125]])
#wektor punktów po przekształceniu
pts2 = np.float32([[0, 0], [500, 0], [0, 600], [500, 600]])

#wyliczenie perspektywy
matrix = cv2.getPerspectiveTransform(pts1, pts2)

#przekształcenie obrazu wejściowego na obraz wg wymiarów pts2 oraz wyliczonej prespektywy
result = cv2.warpPerspective(img, matrix, (500, 600))


plt.imshow(result)
plt.show()