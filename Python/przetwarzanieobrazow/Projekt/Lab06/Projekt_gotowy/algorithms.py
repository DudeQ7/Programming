import numpy as np
#lab01 - kanaly rg
def split_channels(img):
    b = img[:, :, 0]
    g = img[:, :, 1]
    r = img[:, :, 2]
    return b, g, r
def get_channel_view(img, channel):
    b, g, r = split_channels(img)
    zero = np.zeros_like(b)
    if channel == 'r':
        return np.stack([zero, zero, r], axis=2)
    elif channel == 'g':
        return np.stack([zero, g, zero], axis=2)
    elif channel == 'b':
        return np.stack([b, zero, zero], axis=2)
def create_color_grid():
    img = np.zeros((400, 400, 3), dtype=np.uint8)
    img[0:200, 0:200] = [128, 128, 128]
    img[0:200, 200:400] = [255, 0, 255]
    img[200:400, 0:200] = [0, 255, 255]
    img[200:400, 200:400] = [255, 0, 0]
    return img
def get_rgb_collage(img):
    b, g, r = split_channels(img)
    zero = np.zeros_like(b)
    r_view = np.stack([zero, zero, r], axis=2)
    g_view = np.stack([zero, g, zero], axis=2)
    b_view = np.stack([b, zero, zero], axis=2)
    top = np.hstack([img, r_view])
    bottom = np.hstack([g_view, b_view])
    return np.vstack([top, bottom])
def to_grayscale(img, method='yuv'):
    b = img[:, :, 0].astype(np.float32)
    g = img[:, :, 1].astype(np.float32)
    r = img[:, :, 2].astype(np.float32)
    if method == 'avg':
        gray = (r + g + b) / 3.0
    else:
        gray = 0.299 * r + 0.587 * g + 0.114 * b
    return gray.clip(0, 255).astype(np.uint8)
def convert_to_yuv(img):
    img_f = img.astype(np.float32)
    b = img_f[:, :, 0]
    g = img_f[:, :, 1]
    r = img_f[:, :, 2]
    y = 0.299 * r + 0.587 * g + 0.114 * b
    u = 0.493 * (b - y)
    v = 0.877 * (r - y)
    yuv = np.stack([y, u + 128, v + 128], axis=2)
    return yuv.clip(0, 255).astype(np.uint8)
def convert_to_hsv(img):
    img_f = img.astype(np.float32) / 255.0
    b = img_f[:, :, 0]
    g = img_f[:, :, 1]
    r = img_f[:, :, 2]
    cmax = np.max(img_f, axis=2)
    cmin = np.min(img_f, axis=2)
    delta = cmax - cmin
    v = cmax
    s = np.where(cmax != 0, delta / cmax, 0.0)
    h = np.zeros_like(cmax)
    mask_r = (cmax == r) & (delta != 0)
    mask_g = (cmax == g) & (delta != 0)
    mask_b = (cmax == b) & (delta != 0)
    h[mask_r] = (60 * ((g[mask_r] - b[mask_r]) / delta[mask_r])) % 360
    h[mask_g] = 60 * ((b[mask_g] - r[mask_g]) / delta[mask_g] + 2)
    h[mask_b] = 60 * ((r[mask_b] - g[mask_b]) / delta[mask_b] + 4)
    h_norm = (h / 360.0 * 255).astype(np.uint8)
    s_norm = (s * 255).astype(np.uint8)
    v_norm = (v * 255).astype(np.uint8)
    return np.stack([h_norm, s_norm, v_norm], axis=2)
def compute_histogram(gray_img):
    return np.bincount(gray_img.flatten(), minlength=256)
def normalize_histogram(hist):
    h_min = hist.min()
    h_max = hist.max()
    if h_max == h_min:
        return np.zeros_like(hist, dtype=np.float32)
    return (hist - h_min) / (h_max - h_min)
def binarize_manual(gray_img, threshold):
    result = np.zeros_like(gray_img)
    result[gray_img >= threshold] = 255
    return result
def binarize_auto(gray_img):
    hist = compute_histogram(gray_img)
    threshold = int(np.argmax(hist))
    result = binarize_manual(gray_img, threshold)
    return result, threshold
def binarize_multi(gray_img, threshold1, threshold2):
    result = np.zeros_like(gray_img)
    result[(gray_img >= threshold1) & (gray_img < threshold2)] = 128
    result[gray_img >= threshold2] = 255
    return result
def subtract_images(img1_gray, img2_gray):
    a = img1_gray.astype(np.int16)
    b = img2_gray.astype(np.int16)
    result = np.abs(a - b)
    return result.clip(0, 255).astype(np.uint8)
def detect_edges(gray_img, direction='horizontal'):
    if direction == 'horizontal':
        shifted = np.roll(gray_img, 1, axis=1)
        shifted[:, 0] = gray_img[:, 0]  
    elif direction == 'vertical':
        shifted = np.roll(gray_img, 1, axis=0)
        shifted[0, :] = gray_img[0, :]
    elif direction == 'diagonal':
        shifted = np.roll(gray_img, 1, axis=1)
        shifted = np.roll(shifted, 1, axis=0)
        shifted[0, :] = gray_img[0, :]
        shifted[:, 0] = gray_img[:, 0]
    else:
        raise ValueError(f"Nieznany kierunek: {direction}")
    return subtract_images(gray_img, shifted)
def combine_edges(edge1, edge2):
    result = edge1.astype(np.int16) + edge2.astype(np.int16)
    return result.clip(0, 255).astype(np.uint8)
def _apply_transform(img, M):
    h, w = img.shape[:2]
    is_color = len(img.shape) == 3
    M_inv = np.linalg.inv(M)
    ys, xs = np.mgrid[0:h, 0:w]
    ones = np.ones_like(xs)
    coords = np.stack([xs.ravel(), ys.ravel(), ones.ravel()], axis=0).astype(np.float64)
    src_coords = M_inv @ coords
    src_x = src_coords[0] / src_coords[2]
    src_y = src_coords[1] / src_coords[2]
    src_x = np.round(src_x).astype(np.int32).reshape(h, w)
    src_y = np.round(src_y).astype(np.int32).reshape(h, w)
    valid = (src_x >= 0) & (src_x < w) & (src_y >= 0) & (src_y < h)
    if is_color:
        output = np.zeros((h, w, 3), dtype=np.uint8)
        output[valid] = img[src_y[valid], src_x[valid]]
    else:
        output = np.zeros((h, w), dtype=np.uint8)
        output[valid] = img[src_y[valid], src_x[valid]]
    return output
def translate(img, tx, ty):
    M = np.array([
        [1, 0, tx],
        [0, 1, ty],
        [0, 0,  1]
    ], dtype=np.float64)
    return _apply_transform(img, M)
def rotate(img, angle_deg):
    h, w = img.shape[:2]
    cx, cy = w / 2, h / 2
    angle_rad = np.deg2rad(angle_deg)
    cos_a = np.cos(angle_rad)
    sin_a = np.sin(angle_rad)
    T1 = np.array([[1, 0, -cx], [0, 1, -cy], [0, 0, 1]], dtype=np.float64)
    R  = np.array([[cos_a, -sin_a, 0], [sin_a, cos_a, 0], [0, 0, 1]], dtype=np.float64)
    T2 = np.array([[1, 0,  cx], [0, 1,  cy], [0, 0, 1]], dtype=np.float64)
    M = T2 @ R @ T1
    return _apply_transform(img, M)
def scale(img, sx, sy):
    M = np.array([
        [sx,  0, 0],
        [ 0, sy, 0],
        [ 0,  0, 1]
    ], dtype=np.float64)
    return _apply_transform(img, M)
def shear(img, shx, shy):
    M = np.array([
        [1,   shx, 0],
        [shy,   1, 0],
        [0,     0, 1]
    ], dtype=np.float64)
    return _apply_transform(img, M)
def flip(img, mode):
    if mode == 'horizontal':
        return img[:, ::-1].copy()
    elif mode == 'vertical':
        return img[::-1, :].copy()
    elif mode == 'both':
        return img[::-1, ::-1].copy()
def nonlinear_filter(gray_img, filter_type='median', kernel_size=3):
    if kernel_size % 2 == 0:
        raise ValueError("Rozmiar maski musi być nieparzysty (3, 5, 7, ...)!")
    pad = kernel_size // 2
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