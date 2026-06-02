import cv2 as cv 
import numpy as np
import os 
#webcam
capture = cv.VideoCapture(0)
if not capture.isOpened():
    print("Error Couldn't open the webcam")
    exit()
while True: 
    ret, frame = capture.read()
    if not ret:
        print("Can't capture the frame")
        break
    cv.imshow("Webcam_image",frame)
    if cv.waitKey(1) ==ord('q'):
        break
capture.release()
cv.destroyAllWindows()