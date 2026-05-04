import numpy as np
from PIL import Image, ImageTk

# ============================================================
# Rysowanie histogramu jako obraz NumPy
# ============================================================

def draw_histogram_image(hist_data, width=512, height=256, color=(70, 130, 180)):
    """
    Tworzy obraz histogramu jako tablicę NumPy (RGB).
    hist_data : tablica 256 wartości (wynik compute_histogram)
    color     : kolor słupków w formacie RGB
    """
    canvas = np.ones((height, width, 3), dtype=np.uint8) * 245  # Jasne tło

    # Normalizacja do wysokości canvas
    h_max = hist_data.max()
    if h_max == 0:
        return canvas

    bar_width = width // 256

    for i, val in enumerate(hist_data):
        bar_h = int((val / h_max) * (height - 10))
        x_start = i * bar_width
        x_end = x_start + bar_width
        if bar_h > 0:
            canvas[height - bar_h:height, x_start:x_end] = color

    # Linia bazowa
    canvas[height - 1, :] = [50, 50, 50]
    return canvas


# ============================================================
# Konwersja obrazu NumPy -> format Tkinter
# ============================================================

def numpy_to_photoimage(img_np, max_size=(800, 600)):
    """
    Konwertuje tablicę NumPy (BGR lub grayscale) na ImageTk.PhotoImage.
    Automatycznie skaluje obraz do max_size.
    """
    if len(img_np.shape) == 3:
        # BGR -> RGB
        img_rgb = img_np[:, :, ::-1]
        img_pil = Image.fromarray(img_rgb.astype(np.uint8))
    else:
        img_pil = Image.fromarray(img_np.astype(np.uint8))

    img_pil.thumbnail(max_size, Image.LANCZOS)
    return ImageTk.PhotoImage(img_pil)


# ============================================================
# Walidacja danych wejściowych
# ============================================================

def validate_threshold(value_str, min_val=0, max_val=255):
    """
    Sprawdza czy podana wartość jest poprawnym progiem (int w zakresie 0-255).
    Zwraca (True, int) lub (False, komunikat_błędu).
    """
    try:
        val = int(value_str)
        if not (min_val <= val <= max_val):
            return False, f"Wartość musi być w zakresie {min_val}-{max_val}!"
        return True, val
    except ValueError:
        return False, "Podaj liczbę całkowitą!"

def validate_kernel_size(value_str):
    """
    Sprawdza czy podana wartość jest poprawnym rozmiarem maski (nieparzysty int >= 3).
    Zwraca (True, int) lub (False, komunikat_błędu).
    """
    try:
        val = int(value_str)
        if val < 3:
            return False, "Rozmiar maski musi być >= 3!"
        if val % 2 == 0:
            return False, "Rozmiar maski musi być nieparzysty (3, 5, 7, ...)!"
        return True, val
    except ValueError:
        return False, "Podaj liczbę całkowitą!"