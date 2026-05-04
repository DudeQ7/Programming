import cv2
import numpy as np
import os
def nonlinear_filter(image, filter_type='median', kernel_size=3):
    """
    Filtracja nieliniowa obrazu.
    
    Args:
        image: obraz wejściowy (grayscale, numpy array)
        filter_type: 'median', 'min', 'max'
        kernel_size: rozmiar maski (3, 5, 7...) - musi być nieparzysty
    
    Returns:
        Przefiltrowany obraz
    """
    pad = kernel_size // 2  # np. dla 3x3 pad=1, dla 5x5 pad=2

    # Duplikacja krawędzi (ocena 4 i 5)
    padded = np.pad(image, pad, mode='edge')

    h, w = image.shape
    output = np.zeros_like(image)

    for i in range(h):
        for j in range(w):
            # Wytnij okno kernel_size x kernel_size
            window = padded[i:i + kernel_size, j:j + kernel_size]
            flat = window.flatten()

            if filter_type == 'median':
                output[i, j] = np.median(flat)
            elif filter_type == 'min':
                output[i, j] = np.min(flat)
            elif filter_type == 'max':
                output[i, j] = np.max(flat)

    return output


# --- Użycie ---
script_dir = os.path.dirname(os.path.abspath(__file__))
img = cv2.imread(os.path.join(script_dir, 'test.jpg'), cv2.IMREAD_GRAYSCALE)
result_median = nonlinear_filter(img, filter_type='median', kernel_size=3)
result_min    = nonlinear_filter(img, filter_type='min',    kernel_size=3)
result_max    = nonlinear_filter(img, filter_type='max',    kernel_size=3)

# Wyświetlenie porównania
cv2.imshow('Oryginał',        img)
cv2.imshow('Mediana 3x3',     result_median)
cv2.imshow('Minimum 3x3',     result_min)
cv2.imshow('Maksimum 3x3',    result_max)
cv2.waitKey(0)
cv2.destroyAllWindows()