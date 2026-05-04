import cv2 as cv
import numpy as np
import tkinter as tk
from tkinter import filedialog, messagebox, simpledialog
from PIL import Image, ImageTk
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
    M = np.array([[1, 0, tx], [0, 1, ty], [0, 0, 1]], dtype=np.float64)
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
    M = np.array([[sx, 0, 0], [0, sy, 0], [0, 0, 1]], dtype=np.float64)
    return _apply_transform(img, M)

def shear(img, shx, shy):
    M = np.array([[1, shx, 0], [shy, 1, 0], [0, 0, 1]], dtype=np.float64)
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
def draw_histogram_image(hist_data, width=512, height=256, color=(70, 130, 180)):
    canvas = np.ones((height, width, 3), dtype=np.uint8) * 245
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
    canvas[height - 1, :] = [50, 50, 50]
    return canvas

def numpy_to_photoimage(img_np, max_size=(800, 600)):
    if len(img_np.shape) == 3:
        img_rgb = img_np[:, :, ::-1]
        img_pil = Image.fromarray(img_rgb.astype(np.uint8))
    else:
        img_pil = Image.fromarray(img_np.astype(np.uint8))
    img_pil.thumbnail(max_size, Image.LANCZOS)
    return ImageTk.PhotoImage(img_pil)

def validate_threshold(value_str, min_val=0, max_val=255):
    try:
        val = int(value_str)
        if not (min_val <= val <= max_val):
            return False, f"Wartość musi być w zakresie {min_val}-{max_val}!"
        return True, val
    except ValueError:
        return False, "Podaj liczbę całkowitą!"

def validate_kernel_size(value_str):
    try:
        val = int(value_str)
        if val < 3:
            return False, "Rozmiar maski musi być >= 3!"
        if val % 2 == 0:
            return False, "Rozmiar maski musi być nieparzysty (3, 5, 7, ...)!"
        return True, val
    except ValueError:
        return False, "Podaj liczbę całkowitą!"
class App:
    def __init__(self, root):
        self.root = root
        self.root.title("Przetwarzanie Obrazów Cyfrowych – POC Projekt")
        self.root.geometry("1200x800")
        self.root.configure(bg="#1e1e2e")
        self.original_img = None  
        self.processed_img = None 
        self._tk_img = None        
        self._build_ui()

    def _build_ui(self):
        slider_frame = tk.Frame(self.root, bg="#14121a", width=48)
        slider_frame.pack(side="left", fill="y")
        slider_frame.pack_propagate(False)

        sidebar_outer = tk.Frame(self.root, bg="#181825", width=260)
        sidebar_outer.pack(side="left", fill="y")
        sidebar_outer.pack_propagate(False)
        sidebar_canvas = tk.Canvas(sidebar_outer, bg="#181825", bd=0, highlightthickness=0, width=260)
        sidebar_canvas.pack(side="left", fill="both", expand=True)
        menu_frame = tk.Frame(sidebar_canvas, bg="#181825")
        sidebar_canvas.create_window((0,0), window=menu_frame, anchor='nw')
        def _update_scrollregion(event):
            sidebar_canvas.configure(scrollregion=sidebar_canvas.bbox("all"))
        menu_frame.bind("<Configure>", _update_scrollregion)
        sidebar = menu_frame
        self._sidebar_canvas = sidebar_canvas

        tk.Label(sidebar, text="POC Projekt", bg="#181825", fg="#cdd6f4", font=("Segoe UI", 14, "bold")).pack(pady=(20, 5))
        tk.Label(sidebar, text="Przetwarzanie Obrazów", bg="#181825", fg="#6c7086", font=("Segoe UI", 9)).pack(pady=(0, 20))

        self._section(sidebar, "PLIK")
        self._btn(sidebar, "📂  Wczytaj obraz",  self.load_image)
        self._btn(sidebar, "💾  Zapisz wynik",   self.save_image)
        self._btn(sidebar, "🔄  Resetuj obraz",  self.reset_image)

        self._section(sidebar, "LAB 01 – RGB")
        self._btn(sidebar, "Kolaż kanałów R/G/B",    self.lab01_collage)
        self._btn(sidebar, "Tylko kanał R",           lambda: self.lab01_channel('r'))
        self._btn(sidebar, "Tylko kanał G",           lambda: self.lab01_channel('g'))
        self._btn(sidebar, "Tylko kanał B",           lambda: self.lab01_channel('b'))
        self._btn(sidebar, "Własny obraz kolorów",    self.lab01_color_grid)

        self._section(sidebar, "LAB 02 – Modele barw")
        self._btn(sidebar, "Konwersja YUV",           self.lab02_yuv)
        self._btn(sidebar, "Konwersja HSV",           self.lab02_hsv)
        self._btn(sidebar, "Szarość (YUV)",           lambda: self.lab02_gray('yuv'))
        self._btn(sidebar, "Szarość (Średnia)",       lambda: self.lab02_gray('avg'))
        self._btn(sidebar, "Histogram (szarość)",     self.lab02_histogram)

        self._section(sidebar, "LAB 03 – Binaryzacja")
        self._btn(sidebar, "Próg ręczny",             self.lab03_manual)
        self._btn(sidebar, "Próg automatyczny",       self.lab03_auto)
        self._btn(sidebar, "Multiprogowanie",         self.lab03_multi)

        self._section(sidebar, "LAB 04 – Krawędzie")
        self._btn(sidebar, "Krawędzie poziome",       lambda: self.lab04_edges('horizontal'))
        self._btn(sidebar, "Krawędzie pionowe",       lambda: self.lab04_edges('vertical'))
        self._btn(sidebar, "Krawędzie ukośne",        lambda: self.lab04_edges('diagonal'))
        self._btn(sidebar, "Wszystkie krawędzie",     self.lab04_all_edges)
        self._btn(sidebar, "Odejmij dwa obrazy",      self.lab04_subtract)

        self._section(sidebar, "LAB 05 – Geometria")
        self._btn(sidebar, "Translacja",              self.lab05_translate)
        self._btn(sidebar, "Obrót",                   self.lab05_rotate)
        self._btn(sidebar, "Skalowanie",              self.lab05_scale)
        self._btn(sidebar, "Pochylenie (Shear)",      self.lab05_shear)
        self._btn(sidebar, "Odbicie poziome",         lambda: self.lab05_flip('horizontal'))
        self._btn(sidebar, "Odbicie pionowe",         lambda: self.lab05_flip('vertical'))
        self._btn(sidebar, "Odbicie środkowe",        lambda: self.lab05_flip('both'))

        self._section(sidebar, "LAB 06 – Filtracja nieliniowa")
        self._btn(sidebar, "Filtr medianowy",         lambda: self.lab06_filter('median'))
        self._btn(sidebar, "Filtr minimum",           lambda: self.lab06_filter('min'))
        self._btn(sidebar, "Filtr maksimum",          lambda: self.lab06_filter('max'))

        if not hasattr(self, "_buttons"):
            self._buttons = []
        slider_label = tk.Label(slider_frame, text="Suwak", bg="#14121a", fg="#cdd6f4", font=("Segoe UI", 9))
        slider_label.pack(pady=(8,0))
        def on_slider(val):
            try:
                frac = float(val) / 100.0
            except Exception:
                frac = 0.0
            try:
                self._sidebar_canvas.yview_moveto(frac)
            except Exception:
                pass
            if len(self._buttons) > 0:
                idx = int(round(frac * (len(self._buttons) - 1)))
                for i, b in enumerate(self._buttons):
                    b.config(bg="#313244" if i != idx else "#6c6ef0")
        slider = tk.Scale(slider_frame, from_=0, to=100, orient="vertical", command=on_slider, bg="#14121a", fg="#cdd6f4", troughcolor="#45475a", bd=0, highlightthickness=0, length=700)
        slider.set(0)
        slider.pack(fill="y", padx=6, pady=10, expand=True)

        main_frame = tk.Frame(self.root, bg="#1e1e2e")
        main_frame.pack(side="right", fill="both", expand=True)

        self.status_var = tk.StringVar(value="Wczytaj obraz, aby rozpocząć.")
        status_bar = tk.Label(main_frame, textvariable=self.status_var, bg="#313244", fg="#a6e3a1", font=("Segoe UI", 9), anchor="w", padx=10)
        status_bar.pack(side="top", fill="x")

        self.canvas_label = tk.Label(main_frame, text="Wczytaj obraz, aby rozpocząć...", bg="#1e1e2e", fg="#6c7086", font=("Segoe UI", 14))
        self.canvas_label.pack(fill="both", expand=True, padx=20, pady=20)

    def _section(self, parent, title):
        tk.Label(parent, text=title, bg="#181825", fg="#89b4fa", font=("Segoe UI", 8, "bold"), anchor="w", padx=20).pack(fill="x", pady=(12, 2))

    def _btn(self, parent, text, command):
        if not hasattr(self, "_buttons"):
            self._buttons = []
        btn = tk.Button(parent, text=text, command=command, bg="#313244", fg="#cdd6f4", relief="flat", font=("Segoe UI", 9), anchor="w", padx=20, pady=6, activebackground="#45475a", activeforeground="#cdd6f4", cursor="hand2")
        btn._cmd = command
        btn.pack(fill="x", padx=10, pady=1)
        self._buttons.append(btn)

    def _show(self, img_np):
        self.processed_img = img_np
        self._tk_img = numpy_to_photoimage(img_np, max_size=(900, 700))
        self.canvas_label.config(image=self._tk_img, text="")

    def _set_status(self, msg):
        self.status_var.set(msg)

    def _require_image(self):
        if self.original_img is None:
            messagebox.showwarning("Brak obrazu", "Najpierw wczytaj obraz!")
            return False
        return True

    def load_image(self):
        path = filedialog.askopenfilename(title="Wybierz obraz", filetypes=[("Obrazy", "*.png *.jpg *.jpeg *.bmp *.tiff"), ("Wszystkie", "*.*")])
        if path:
            self.original_img = cv.imread(path)
            if self.original_img is None:
                messagebox.showerror("Błąd", "Nie udało się wczytać obrazu!")
                return
            self.processed_img = self.original_img.copy()
            self._show(self.original_img)
            self._set_status(f"Wczytano: {path}  |  Rozmiar: {self.original_img.shape[1]}x{self.original_img.shape[0]}")

    def save_image(self):
        if not self._require_image(): return
        path = filedialog.asksaveasfilename(defaultextension=".png", filetypes=[("PNG", "*.png"), ("JPEG", "*.jpg"), ("BMP", "*.bmp")])
        if path:
            cv.imwrite(path, self.processed_img)
            self._set_status(f"Zapisano: {path}")
            messagebox.showinfo("Sukces", f"Obraz zapisany:\n{path}")

    def reset_image(self):
        if not self._require_image(): return
        self._show(self.original_img)
        self._set_status("Obraz zresetowany do oryginału.")

    def lab01_collage(self):
        if not self._require_image(): return
        result = get_rgb_collage(self.original_img)
        self._show(result)
        self._set_status("Lab 01: Kolaż kanałów R/G/B")

    def lab01_channel(self, ch):
        if not self._require_image(): return
        result = get_channel_view(self.original_img, ch)
        self._show(result)
        self._set_status(f"Lab 01: Kanał {ch.upper()}")

    def lab01_color_grid(self):
        result = create_color_grid()
        self._show(result)
        self._set_status("Lab 01: Własny obraz kolorów")

    def lab02_yuv(self):
        if not self._require_image(): return
        result = convert_to_yuv(self.original_img)
        self._show(result)
        self._set_status("Lab 02: Konwersja YUV")

    def lab02_hsv(self):
        if not self._require_image(): return
        result = convert_to_hsv(self.original_img)
        self._show(result)
        self._set_status("Lab 02: Konwersja HSV")

    def lab02_gray(self, method):
        if not self._require_image(): return
        result = to_grayscale(self.original_img, method=method)
        self._show(result)
        label = "YUV" if method == 'yuv' else "Średnia"
        self._set_status(f"Lab 02: Skala szarości – {label}")

    def lab02_histogram(self):
        if not self._require_image(): return
        gray = to_grayscale(self.original_img, method='yuv')
        hist = compute_histogram(gray)
        hist_img = draw_histogram_image(hist)
        self._show(hist_img)
        self._set_status("Lab 02: Histogram")

    def lab03_manual(self):
        if not self._require_image(): return
        val = simpledialog.askstring("Próg binaryzacji", "Podaj próg (0-255):", parent=self.root)
        if val is None: return
        ok, result = validate_threshold(val)
        if not ok:
            messagebox.showerror("Błąd", result); return
        gray = to_grayscale(self.original_img, method='yuv')
        binary = binarize_manual(gray, result)
        self._show(binary)
        self._set_status(f"Lab 03: Binaryzacja ręczna – próg = {result}")

    def lab03_auto(self):
        if not self._require_image(): return
        gray = to_grayscale(self.original_img, method='yuv')
        binary, threshold = binarize_auto(gray)
        self._show(binary)
        self._set_status(f"Lab 03: Binaryzacja automatyczna (próg {threshold})")

    def lab03_multi(self):
        if not self._require_image(): return
        val1 = simpledialog.askstring("Multiprogowanie", "Podaj pierwszy próg (0-255):", parent=self.root)
        if val1 is None: return
        val2 = simpledialog.askstring("Multiprogowanie", "Podaj drugi próg (0-255):", parent=self.root)
        if val2 is None: return
        ok1, t1 = validate_threshold(val1)
        ok2, t2 = validate_threshold(val2)
        if not (ok1 and ok2): messagebox.showerror("Błąd", "Nieprawidłowe progi!"); return
        if t1 >= t2: messagebox.showerror("Błąd", "Próg 1 musi być mniejszy od 2!"); return
        gray = to_grayscale(self.original_img, method='yuv')
        result = binarize_multi(gray, t1, t2)
        self._show(result)
        self._set_status(f"Lab 03: Multiprogowanie ({t1}, {t2})")

    def lab04_edges(self, direction):
        if not self._require_image(): return
        gray = to_grayscale(self.original_img, method='yuv')
        result = detect_edges(gray, direction=direction)
        self._show(result)
        self._set_status(f"Lab 04: Krawędzie {direction}")

    def lab04_all_edges(self):
        if not self._require_image(): return
        gray = to_grayscale(self.original_img, method='yuv')
        eh = detect_edges(gray, 'horizontal')
        ev = detect_edges(gray, 'vertical')
        ed = detect_edges(gray, 'diagonal')
        combined = combine_edges(combine_edges(eh, ev), ed)
        self._show(combined)
        self._set_status("Lab 04: Wszystkie krawędzie")

    def lab04_subtract(self):
        if not self._require_image(): return
        path = filedialog.askopenfilename(title="Wybierz drugi obraz", filetypes=[("Obrazy", "*.png *.jpg *.jpeg *.bmp")])
        if not path: return
        img2 = cv.imread(path)
        if img2 is None: return
        h, w = self.original_img.shape[:2]
        gray1 = to_grayscale(self.original_img, method='yuv')
        gray2 = to_grayscale(cv.resize(img2, (w, h)), method='yuv')
        result = subtract_images(gray1, gray2)
        self._show(result)
        self._set_status("Lab 04: Odejmowanie obrazów")

    def lab05_translate(self):
        if not self._require_image(): return
        tx = simpledialog.askinteger("Translacja", "Przesunięcie X:", parent=self.root)
        ty = simpledialog.askinteger("Translacja", "Przesunięcie Y:", parent=self.root)
        if tx is None or ty is None: return
        result = translate(self.original_img, tx, ty)
        self._show(result)
        self._set_status(f"Lab 05: Translacja ({tx}, {ty})")

    def lab05_rotate(self):
        if not self._require_image(): return
        val = simpledialog.askfloat("Obrót", "Kąt (stopnie):", parent=self.root)
        if val is None: return
        result = rotate(self.original_img, val)
        self._show(result)
        self._set_status(f"Lab 05: Obrót {val}°")

    def lab05_scale(self):
        if not self._require_image(): return
        sx = simpledialog.askfloat("Skalowanie", "Skala X:", parent=self.root)
        sy = simpledialog.askfloat("Skalowanie", "Skala Y:", parent=self.root)
        if sx is None or sy is None: return
        result = scale(self.original_img, sx, sy)
        self._show(result)

    def lab05_shear(self):
        if not self._require_image(): return
        shx = simpledialog.askfloat("Shear", "Shear X:", parent=self.root)
        shy = simpledialog.askfloat("Shear", "Shear Y:", parent=self.root)
        if shx is None or shy is None: return
        result = shear(self.original_img, shx, shy)
        self._show(result)

    def lab05_flip(self, mode):
        if not self._require_image(): return
        result = flip(self.original_img, mode)
        self._show(result)

    def lab06_filter(self, filter_type):
        if not self._require_image(): return
        val = simpledialog.askstring("Maska", "Rozmiar (nieparzysty >= 3):", parent=self.root)
        if val is None: return
        ok, kernel = validate_kernel_size(val)
        if not ok: messagebox.showerror("Błąd", kernel); return
        gray = to_grayscale(self.original_img, method='yuv')
        self._set_status("Trwa filtracja... Proszę czekać.")
        self.root.update()
        result = nonlinear_filter(gray, filter_type, kernel)
        self._show(result)
        self._set_status(f"Lab 06: Filtr {filter_type} {kernel}x{kernel}")

if __name__ == "__main__":
    root = tk.Tk()
    app = App(root)
    root.mainloop()