# -*- coding: utf-8 -*-
"""
Created on Mon May 18 21:58:20 2026

@author: Magda
"""


import cv2
#https://www.geeksforgeeks.org/python/image-inpainting-using-opencv/
# reading the damaged image
damaged_img = cv2.imread("C:\\Users\\Magda\\Desktop\\POC\\cat_damaged.png")

# get the shape of the image
height, width = damaged_img.shape[0], damaged_img.shape[1]

# Converting all pixels greater than zero to black while black becomes white
for i in range(height):
    for j in range(width):
        if damaged_img[i, j].sum() > 0:
            damaged_img[i, j] = 0
        else:
            damaged_img[i, j] = [255, 255, 255]

# saving the mask 
mask = damaged_img
cv2.imwrite('mask.png', mask)

# displaying mask
cv2.imshow("damaged image mask", mask)
cv2.waitKey(0)
cv2.destroyAllWindows()

# Open the image.
img = cv2.imread("C:\\Users\\Magda\\Desktop\\POC\\cat_damaged.png")

# Load the mask.
mask = cv2.imread('mask.png', 0)

# Inpaint.
dst = cv2.inpaint(img, mask, 3, cv2.INPAINT_NS)

# Write the output.
cv2.imshow('cat_inpainted.png', dst)
cv2.waitKey(0)
cv2.destroyAllWindows()