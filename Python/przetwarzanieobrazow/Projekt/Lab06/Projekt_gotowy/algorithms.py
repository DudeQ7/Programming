import numpy as np

# ============================================================
# LAB 01 – Kanały RGB
# ============================================================

def split_channels(img):
    """Rozdziela obraz BGR na osobne kanały. Zwraca (b, g, r)."""
    b = img[:, :, 0]
    g = img[:, :, 1]
    r = img[:, :, 2]
    return b, g, r

def get_channel_view(img, channel):
    """
    Zwraca obraz z wybranym kanałem (pozostałe = 0).
    channel: 'r', 'g' lub 'b'
    """
    b, g, r = split_channels(img)
    zero = np.zeros_like(b)
    if channel == 'r':
        return np.stack([zero, zero, r], axis=2)
    elif channel == 'g':
        return np.stack([zero, g, zero], axis=2)
    elif channel == 'b':
        return np.stack([b, zero, zero], axis=2)

def create_color_grid():
    """
    Tworzy własny obraz 400x400 z 4 kolorami (Lab 01):
    - Szary (128,128,128), Magenta (255,0,255),
    - Żółty (255,255,0),   Niebieski (0,0,255)
    Uwaga: OpenCV używa BGR, więc kolejność kanałów jest odwrócona.
    """
    img = np.zeros((400, 400, 3), dtype=np.uint8)
    # Górny lewy: Szary
    img[0:200, 0:200] = [128, 128, 128]
    # Górny prawy: Magenta (R=255, G=0, B=255) -> BGR: (255, 0, 255)
    img[0:200, 200:400] = [255, 0, 255]
    # Dolny lewy: Żółty (R=255, G=255, B=0) -> BGR: (0, 255, 255)
    img[200:400, 0:200] = [0, 255, 255]
    # Dolny prawy: Niebieski (R=0, G=0, B=255) -> BGR: (255, 0, 0)
    img[200:400, 200:400] = [255, 0, 0]
    return img

def get_rgb_collage(img):
    """Tworzy kolaż 2x2: oryginał, R, G, B."""
    b, g, r = split_channels(img)
    zero = np.zeros_like(b)
    r_view = np.stack([zero, zero, r], axis=2)
    g_view = np.stack([zero, g, zero], axis=2)
    b_view = np.stack([b, zero, zero], axis=2)
    top = np.hstack([img, r_view])
    bottom = np.hstack([g_view, b_view])
    return np.vstack([top, bottom])


# ============================================================
# LAB 02 – Modele barw, skala szarości, histogram
# ============================================================

def to_grayscale(img, method='yuv'):
    """
    Konwersja BGR -> skala szarości.
    method='yuv'  : Y = 0.299R + 0.587G + 0.114B
    method='avg'  : Y = (R + G + B) / 3
    """
    b = img[:, :, 0].astype(np.float32)
    g = img[:, :, 1].astype(np.float32)
    r = img[:, :, 2].astype(np.float32)
    if method == 'avg':
        gray = (r + g + b) / 3.0
    else:
        gray = 0.299 * r + 0.587 * g + 0.114 * b
    return gray.clip(0, 255).astype(np.uint8)

def convert_to_yuv(img):
    """
    Ręczna konwersja BGR -> YUV (wzory z POC2.pdf).
    Y = 0.299R + 0.587G + 0.114B
    U = 0.493(B - Y)
    V = 0.877(R - Y)
    Zwraca obraz znormalizowany do wyświetlenia (0-255).
    """
    img_f = img.astype(np.float32)
    b = img_f[:, :, 0]
    g = img_f[:, :, 1]
    r = img_f[:, :, 2]
    y = 0.299 * r + 0.587 * g + 0.114 * b
    u = 0.493 * (b - y)
    v = 0.877 * (r - y)
    # Normalizacja U i V do zakresu 0-255 (przesunięcie o 128)
    yuv = np.stack([y, u + 128, v + 128], axis=2)
    return yuv.clip(0, 255).astype(np.uint8)

def convert_to_hsv(img):
    """
    Ręczna konwersja BGR -> HSV.
    H: 0-360, S: 0-1, V: 0-1 -> normalizowane do 0-255.
    """
    img_f = img.astype(np.float32) / 255.0
    b = img_f[:, :, 0]
    g = img_f[:, :, 1]
    r = img_f[:, :, 2]

    cmax = np.max(img_f, axis=2)
    cmin = np.min(img_f, axis=2)
    delta = cmax - cmin

    # Value
    v = cmax

    # Saturation
    s = np.where(cmax != 0, delta / cmax, 0.0)

    # Hue
    h = np.zeros_like(cmax)
    mask_r = (cmax == r) & (delta != 0)
    mask_g = (cmax == g) & (delta != 0)
    mask_b = (cmax == b) & (delta != 0)

    h[mask_r] = (60 * ((g[mask_r] - b[mask_r]) / delta[mask_r])) % 360
    h[mask_g] = 60 * ((b[mask_g] - r[mask_g]) / delta[mask_g] + 2)
    h[mask_b] = 60 * ((r[mask_b] - g[mask_b]) / delta[mask_b] + 4)

    # Normalizacja do 0-255
    h_norm = (h / 360.0 * 255).astype(np.uint8)
    s_norm = (s * 255).astype(np.uint8)
    v_norm = (v * 255).astype(np.uint8)

    return np.stack([h_norm, s_norm, v_norm], axis=2)

def compute_histogram(gray_img):
    """Oblicza histogram dla obrazu w skali szarości (256 poziomów)."""
    return np.bincount(gray_img.flatten(), minlength=256)

def normalize_histogram(hist):
    """
    Normalizacja histogramu wg wzoru z Lab 02:
    xi_norm = (xi - min) / (max - min)
    Zwraca wartości w zakresie 0.0 - 1.0.
    """
    h_min = hist.min()
    h_max = hist.max()
    if h_max == h_min:
        return np.zeros_like(hist, dtype=np.float32)
    return (hist - h_min) / (h_max - h_min)


# ============================================================
# LAB 03 – Binaryzacja
# ============================================================

def binarize_manual(gray_img, threshold):
    """
    Binaryzacja z progiem podanym przez użytkownika.
    Piksel >= threshold -> 255 (biały), inaczej -> 0 (czarny).
    """
    result = np.zeros_like(gray_img)
    result[gray_img >= threshold] = 255
    return result

def binarize_auto(gray_img):
    """
    Binaryzacja automatyczna – próg = wartość największego piku histogramu.
    Zwraca (obraz_binarny, wartość_progu).
    """
    hist = compute_histogram(gray_img)
    threshold = int(np.argmax(hist))
    result = binarize_manual(gray_img, threshold)
    return result, threshold

def binarize_multi(gray_img, threshold1, threshold2):
    """
    Multiprogowanie z dwoma progami (Lab 03):
    - piksel < threshold1          -> 0   (czarny)
    - threshold1 <= piksel < threshold2 -> 128 (szary)
    - piksel >= threshold2         -> 255 (biały)
    """
    result = np.zeros_like(gray_img)
    result[(gray_img >= threshold1) & (gray_img < threshold2)] = 128
    result[gray_img >= threshold2] = 255
    return result


# ============================================================
# LAB 04 – Wykrywanie krawędzi (odejmowanie obrazów)
# ============================================================

def subtract_images(img1_gray, img2_gray):
    """
    Odejmowanie dwóch obrazów w skali szarości.
    Wynik = |img1 - img2|, ograniczony do 0-255.
    """
    a = img1_gray.astype(np.int16)
    b = img2_gray.astype(np.int16)
    result = np.abs(a - b)
    return result.clip(0, 255).astype(np.uint8)

def detect_edges(gray_img, direction='horizontal'):
    """
    Wykrywanie krawędzi przez odejmowanie przesuniętego obrazu.
    direction: 'horizontal', 'vertical', 'diagonal'
    """
    if direction == 'horizontal':
        # Przesunięcie o 1 piksel w prawo (axis=1)
        shifted = np.roll(gray_img, 1, axis=1)
        shifted[:, 0] = gray_img[:, 0]  # Zerowanie artefaktu roll
    elif direction == 'vertical':
        # Przesunięcie o 1 piksel w dół (axis=0)
        shifted = np.roll(gray_img, 1, axis=0)
        shifted[0, :] = gray_img[0, :]
    elif direction == 'diagonal':
        # Przesunięcie o 1 piksel w prawo i w dół
        shifted = np.roll(gray_img, 1, axis=1)
        shifted = np.roll(shifted, 1, axis=0)
        shifted[0, :] = gray_img[0, :]
        shifted[:, 0] = gray_img[:, 0]
    else:
        raise ValueError(f"Nieznany kierunek: {direction}")

    return subtract_images(gray_img, shifted)

def combine_edges(edge1, edge2):
    """Łączy dwa obrazy krawędzi przez dodawanie (z ograniczeniem do 255)."""
    result = edge1.astype(np.int16) + edge2.astype(np.int16)
    return result.clip(0, 255).astype(np.uint8)


# ============================================================
# LAB 05 – Operacje geometryczne (macierze transformacji)
# ============================================================

def _apply_transform(img, M):
    """
    Stosuje macierz transformacji 3x3 (współrzędne jednorodne) do obrazu.
    Dla każdego piksela w obrazie wynikowym oblicza jego pozycję w oryginale
    (transformacja odwrotna), aby uniknąć dziur.
    """
    h, w = img.shape[:2]
    is_color = len(img.shape) == 3

    # Macierz odwrotna
    M_inv = np.linalg.inv(M)

    # Siatka współrzędnych obrazu wynikowego
    ys, xs = np.mgrid[0:h, 0:w]
    ones = np.ones_like(xs)
    coords = np.stack([xs.ravel(), ys.ravel(), ones.ravel()], axis=0).astype(np.float64)

    # Transformacja odwrotna
    src_coords = M_inv @ coords
    src_x = src_coords[0] / src_coords[2]
    src_y = src_coords[1] / src_coords[2]

    # Zaokrąglenie do indeksów całkowitych
    src_x = np.round(src_x).astype(np.int32).reshape(h, w)
    src_y = np.round(src_y).astype(np.int32).reshape(h, w)

    # Maska pikseli w granicach obrazu
    valid = (src_x >= 0) & (src_x < w) & (src_y >= 0) & (src_y < h)

    if is_color:
        output = np.zeros((h, w, 3), dtype=np.uint8)
        output[valid] = img[src_y[valid], src_x[valid]]
    else:
        output = np.zeros((h, w), dtype=np.uint8)
        output[valid] = img[src_y[valid], src_x[valid]]

    return output

def translate(img, tx, ty):
    """Przesunięcie (translacja) o (tx, ty) pikseli."""
    M = np.array([
        [1, 0, tx],
        [0, 1, ty],
        [0, 0,  1]
    ], dtype=np.float64)
    return _apply_transform(img, M)

def rotate(img, angle_deg):
    """Obrót o angle_deg stopni względem środka obrazu."""
    h, w = img.shape[:2]
    cx, cy = w / 2, h / 2
    angle_rad = np.deg2rad(angle_deg)
    cos_a = np.cos(angle_rad)
    sin_a = np.sin(angle_rad)

    # Macierz obrotu względem środka
    T1 = np.array([[1, 0, -cx], [0, 1, -cy], [0, 0, 1]], dtype=np.float64)
    R  = np.array([[cos_a, -sin_a, 0], [sin_a, cos_a, 0], [0, 0, 1]], dtype=np.float64)
    T2 = np.array([[1, 0,  cx], [0, 1,  cy], [0, 0, 1]], dtype=np.float64)

    M = T2 @ R @ T1
    return _apply_transform(img, M)

def scale(img, sx, sy):
    """Skalowanie o współczynnikach sx (poziomo) i sy (pionowo)."""
    M = np.array([
        [sx,  0, 0],
        [ 0, sy, 0],
        [ 0,  0, 1]
    ], dtype=np.float64)
    return _apply_transform(img, M)

def shear(img, shx, shy):
    """Pochylenie (shear) o współczynnikach shx i shy."""
    M = np.array([
        [1,   shx, 0],
        [shy,   1, 0],
        [0,     0, 1]
    ], dtype=np.float64)
    return _apply_transform(img, M)

def flip(img, mode):
    """
    Odbicie symetryczne.
    mode: 'horizontal' (względem OY), 'vertical' (względem OX), 'both'
    """
    if mode == 'horizontal':
        return img[:, ::-1].copy()
    elif mode == 'vertical':
        return img[::-1, :].copy()
    elif mode == 'both':
        return img[::-1, ::-1].copy()


# ============================================================
# LAB 06 – Filtracja nieliniowa (na ocenę 5.0)
# ============================================================

def nonlinear_filter(gray_img, filter_type='median', kernel_size=3):
    """
    Filtracja nieliniowa z duplikacją krawędzi i dowolnym rozmiarem maski.
    filter_type : 'median', 'min', 'max'
    kernel_size : nieparzysty int (3, 5, 7, ...)
    Spełnia wymagania na ocenę 5.0.
    """
    if kernel_size % 2 == 0:
        raise ValueError("Rozmiar maski musi być nieparzysty (3, 5, 7, ...)!")

    pad = kernel_size // 2

    # Duplikacja krawędzi (mode='edge' kopiuje wartości brzegowe)
    padded = np.pad(gray_img, pad, mode='edge')

    h, w = gray_img.shape
    output = np.zeros_like(gray_img)

    for i in range(h):
        for j in range(w):
            window = padded[i:i + kernel_size, j:j + kernel_size].flatten()
            if filter_type == 'median':
                output[i, j] = np.median(window)
            elif filter_type == 'min':
                output[i, j] = np.min(window)
            elif filter_type == 'max':
                output[i, j] = np.max(window)

    return output