# -*- coding: utf-8 -*-
"""
Created on Wed Oct 27 09:50:31 2021

@author: Magda
"""
import numpy as np
import cv2
import math
from matplotlib import pyplot as plt

img = cv2.imread("D:\\Pulpit\\User\\t2.jpg",0)

dft = cv2.dft(np.float32(img),flags = cv2.DFT_COMPLEX_OUTPUT)
dft_shift = np.fft.fftshift(dft)

magnitude_spectrum = 20*np.log(cv2.magnitude(dft_shift[:,:,0],dft_shift[:,:,1]))

plt.subplot(121),plt.imshow(img, cmap = 'gray')
plt.title('Input Image'), plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(magnitude_spectrum, cmap = 'terrain')
plt.title('Magnitude Spectrum'), plt.xticks([]), plt.yticks([])
plt.show()

rows, cols = img.shape
crow,ccol = int(rows/2) , int(cols/2)

# create a mask first, center square is 1, remaining all zeros
mask = np.zeros((rows,cols,2),np.uint8)

#filtr wycinający dolne częstotliwoci
#mask[crow-30:crow+30, ccol-30:ccol+30] = 1

#filtr wycinający górne częstotliwoci
"""dep = 5
mask[0:crow-dep, 0:ccol-dep]=1
mask[0:crow-dep,ccol+dep:cols]=1
mask[crow+dep:rows,ccol+dep:cols]=1
mask[crow+dep:rows,0:ccol-dep]=1"""
x0=int(rows/2)
y0=int(cols/2)
r=10

for i in range(rows):
    for j in range(cols):
        if(math.pow(i-x0,2.0)+math.pow(j-y0,2.0)>=math.pow(r,2.0)):
            mask[int(i),int(j)]=1


# apply mask and inverse DFT
fshift = dft_shift*mask
f_ishift = np.fft.ifftshift(fshift)
img_back = cv2.idft(f_ishift)
img_back = cv2.magnitude(img_back[:,:,0],img_back[:,:,1])

plt.subplot(121),plt.imshow(img, cmap = 'gray')
plt.title('Input Image'), plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(img_back, cmap = 'gray')
plt.title('Magnitude Spectrum'), plt.xticks([]), plt.yticks([])
plt.show()

rows, cols = img.shape
crow,ccol = int(rows/2) , int(cols/2)

# create a mask first, center square is 1, remaining all zeros
mask = np.zeros((rows,cols,2),np.uint8)
mask[crow-30:crow+30, ccol-30:ccol+30] = 1

# apply mask and inverse DFT
fshift = dft_shift*mask
f_ishift = np.fft.ifftshift(fshift)
img_back = cv2.idft(f_ishift)
img_back = cv2.magnitude(img_back[:,:,0],img_back[:,:,1])

plt.subplot(121),plt.imshow(img, cmap = 'gray')
plt.title('Input Image'), plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(img_back, cmap = 'gray')
plt.title('Magnitude Spectrum'), plt.xticks([]), plt.yticks([])
plt.show()