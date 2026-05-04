import cv2 as cv
import numpy as np
import tkinter as tk
from tkinter import filedialog, messagebox, simpledialog
#sudo pacman -S tk  necessary dla Linuxas
from algorithms import (
    # Lab 01
    get_rgb_collage, get_channel_view, create_color_grid,
    # Lab 02
    to_grayscale, convert_to_yuv, convert_to_hsv,
    compute_histogram, normalize_histogram,
    # Lab 03
    binarize_manual, binarize_auto, binarize_multi,
    # Lab 04
    subtract_images, detect_edges, combine_edges,
    # Lab 05
    translate, rotate, scale, shear, flip,
    # Lab 06
    nonlinear_filter
)
from utils import draw_histogram_image, numpy_to_photoimage, validate_threshold, validate_kernel_size


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
        # ---- SIDEBAR ----
        sidebar = tk.Frame(self.root, bg="#181825", width=260)
        sidebar.pack(side="left", fill="y")
        sidebar.pack_propagate(False)

        tk.Label(
            sidebar, text="POC Projekt", bg="#181825", fg="#cdd6f4",
            font=("Segoe UI", 14, "bold")
        ).pack(pady=(20, 5))
        tk.Label(
            sidebar, text="Przetwarzanie Obrazów", bg="#181825", fg="#6c7086",
            font=("Segoe UI", 9)
        ).pack(pady=(0, 20))

        # Przyciski pliku
        self._section(sidebar, "PLIK")
        self._btn(sidebar, "📂  Wczytaj obraz",  self.load_image)
        self._btn(sidebar, "💾  Zapisz wynik",   self.save_image)
        self._btn(sidebar, "🔄  Resetuj obraz",  self.reset_image)

        # Lab 01
        self._section(sidebar, "LAB 01 – RGB")
        self._btn(sidebar, "Kolaż kanałów R/G/B",    self.lab01_collage)
        self._btn(sidebar, "Tylko kanał R",           lambda: self.lab01_channel('r'))
        self._btn(sidebar, "Tylko kanał G",           lambda: self.lab01_channel('g'))
        self._btn(sidebar, "Tylko kanał B",           lambda: self.lab01_channel('b'))
        self._btn(sidebar, "Własny obraz kolorów",    self.lab01_color_grid)

        # Lab 02
        self._section(sidebar, "LAB 02 – Modele barw")
        self._btn(sidebar, "Konwersja YUV",           self.lab02_yuv)
        self._btn(sidebar, "Konwersja HSV",           self.lab02_hsv)
        self._btn(sidebar, "Szarość (YUV)",           lambda: self.lab02_gray('yuv'))
        self._btn(sidebar, "Szarość (Średnia)",       lambda: self.lab02_gray('avg'))
        self._btn(sidebar, "Histogram (szarość)",     self.lab02_histogram)

        # Lab 03
        self._section(sidebar, "LAB 03 – Binaryzacja")
        self._btn(sidebar, "Próg ręczny",             self.lab03_manual)
        self._btn(sidebar, "Próg automatyczny",       self.lab03_auto)
        self._btn(sidebar, "Multiprogowanie",         self.lab03_multi)

        # Lab 04
        self._section(sidebar, "LAB 04 – Krawędzie")
        self._btn(sidebar, "Krawędzie poziome",       lambda: self.lab04_edges('horizontal'))
        self._btn(sidebar, "Krawędzie pionowe",       lambda: self.lab04_edges('vertical'))
        self._btn(sidebar, "Krawędzie ukośne",        lambda: self.lab04_edges('diagonal'))
        self._btn(sidebar, "Wszystkie krawędzie",     self.lab04_all_edges)
        self._btn(sidebar, "Odejmij dwa obrazy",      self.lab04_subtract)

        # Lab 05
        self._section(sidebar, "LAB 05 – Geometria")
        self._btn(sidebar, "Translacja",              self.lab05_translate)
        self._btn(sidebar, "Obrót",                   self.lab05_rotate)
        self._btn(sidebar, "Skalowanie",              self.lab05_scale)
        self._btn(sidebar, "Pochylenie (Shear)",      self.lab05_shear)
        self._btn(sidebar, "Odbicie poziome",         lambda: self.lab05_flip('horizontal'))
        self._btn(sidebar, "Odbicie pionowe",         lambda: self.lab05_flip('vertical'))
        self._btn(sidebar, "Odbicie środkowe",        lambda: self.lab05_flip('both'))

        # Lab 06
        self._section(sidebar, "LAB 06 – Filtracja nieliniowa")
        self._btn(sidebar, "Filtr medianowy",         lambda: self.lab06_filter('median'))
        self._btn(sidebar, "Filtr minimum",           lambda: self.lab06_filter('min'))
        self._btn(sidebar, "Filtr maksimum",          lambda: self.lab06_filter('max'))

        # ---- MAIN AREA ----
        main_frame = tk.Frame(self.root, bg="#1e1e2e")
        main_frame.pack(side="right", fill="both", expand=True)

        # Pasek statusu (na górze)
        self.status_var = tk.StringVar(value="Wczytaj obraz, aby rozpocząć.")
        status_bar = tk.Label(
            main_frame, textvariable=self.status_var,
            bg="#313244", fg="#a6e3a1", font=("Segoe UI", 9),
            anchor="w", padx=10
        )
        status_bar.pack(side="top", fill="x")

        # Obszar podglądu obrazu
        self.canvas_label = tk.Label(
            main_frame,
            text="Wczytaj obraz, aby rozpocząć...",
            bg="#1e1e2e", fg="#6c7086",
            font=("Segoe UI", 14)
        )
        self.canvas_label.pack(fill="both", expand=True, padx=20, pady=20)

    def _section(self, parent, title):
        tk.Label(
            parent, text=title, bg="#181825", fg="#89b4fa",
            font=("Segoe UI", 8, "bold"), anchor="w", padx=20
        ).pack(fill="x", pady=(12, 2))

    def _btn(self, parent, text, command):
        btn = tk.Button(
            parent, text=text, command=command,
            bg="#313244", fg="#cdd6f4", relief="flat",
            font=("Segoe UI", 9), anchor="w", padx=20, pady=6,
            activebackground="#45475a", activeforeground="#cdd6f4",
            cursor="hand2"
        )
        btn.pack(fill="x", padx=10, pady=1)
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
        path = filedialog.askopenfilename(
            title="Wybierz obraz",
            filetypes=[("Obrazy", "*.png *.jpg *.jpeg *.bmp *.tiff"), ("Wszystkie", "*.*")]
        )
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
        path = filedialog.asksaveasfilename(
            defaultextension=".png",
            filetypes=[("PNG", "*.png"), ("JPEG", "*.jpg"), ("BMP", "*.bmp")]
        )
        if path:
            cv.imwrite(path, self.processed_img)
            self._set_status(f"Zapisano: {path}")
            messagebox.showinfo("Sukces", f"Obraz zapisany:\n{path}")

    def reset_image(self):
        if not self._require_image(): return
        self._show(self.original_img)
        self._set_status("Obraz zresetowany do oryginału.")

    # ------------------------------------------------------------------ #
    #  LAB 01 – RGB                                                        #
    # ------------------------------------------------------------------ #

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
        self._set_status("Lab 01: Własny obraz kolorów (szary, magenta, żółty, niebieski)")

    # ------------------------------------------------------------------ #
    #  LAB 02 – Modele barw, histogram                                     #
    # ------------------------------------------------------------------ #

    def lab02_yuv(self):
        if not self._require_image(): return
        result = convert_to_yuv(self.original_img)
        self._show(result)
        self._set_status("Lab 02: Konwersja YUV (znormalizowana)")

    def lab02_hsv(self):
        if not self._require_image(): return
        result = convert_to_hsv(self.original_img)
        self._show(result)
        self._set_status("Lab 02: Konwersja HSV (znormalizowana)")

    def lab02_gray(self, method):
        if not self._require_image(): return
        result = to_grayscale(self.original_img, method=method)
        self._show(result)
        label = "YUV (0.299R+0.587G+0.114B)" if method == 'yuv' else "Średnia (R+G+B)/3"
        self._set_status(f"Lab 02: Skala szarości – metoda {label}")

    def lab02_histogram(self):
        if not self._require_image(): return
        gray = to_grayscale(self.original_img, method='yuv')
        hist = compute_histogram(gray)
        hist_img = draw_histogram_image(hist)
        self._show(hist_img)
        self._set_status("Lab 02: Histogram (skala szarości YUV)")

    # ------------------------------------------------------------------ #
    #  LAB 03 – Binaryzacja                                                #
    # ------------------------------------------------------------------ #

    def lab03_manual(self):
        if not self._require_image(): return
        val = simpledialog.askstring("Próg binaryzacji", "Podaj próg (0-255):", parent=self.root)
        if val is None: return
        ok, result = validate_threshold(val)
        if not ok:
            messagebox.showerror("Błąd", result)
            return
        gray = to_grayscale(self.original_img, method='yuv')
        binary = binarize_manual(gray, result)
        self._show(binary)
        self._set_status(f"Lab 03: Binaryzacja ręczna – próg = {result}")

    def lab03_auto(self):
        if not self._require_image(): return
        gray = to_grayscale(self.original_img, method='yuv')
        binary, threshold = binarize_auto(gray)
        self._show(binary)
        self._set_status(f"Lab 03: Binaryzacja automatyczna – próg z histogramu = {threshold}")

    def lab03_multi(self):
        if not self._require_image(): return
        val1 = simpledialog.askstring("Multiprogowanie", "Podaj pierwszy próg (0-255):", parent=self.root)
        if val1 is None: return
        val2 = simpledialog.askstring("Multiprogowanie", "Podaj drugi próg (0-255):", parent=self.root)
        if val2 is None: return
        ok1, t1 = validate_threshold(val1)
        ok2, t2 = validate_threshold(val2)
        if not ok1:
            messagebox.showerror("Błąd", t1); return
        if not ok2:
            messagebox.showerror("Błąd", t2); return
        if t1 >= t2:
            messagebox.showerror("Błąd", "Pierwszy próg musi być mniejszy od drugiego!"); return
        gray = to_grayscale(self.original_img, method='yuv')
        result = binarize_multi(gray, t1, t2)
        self._show(result)
        self._set_status(f"Lab 03: Multiprogowanie – próg1={t1}, próg2={t2}")

    # ------------------------------------------------------------------ #
    #  LAB 04 – Wykrywanie krawędzi                                        #
    # ------------------------------------------------------------------ #

    def lab04_edges(self, direction):
        if not self._require_image(): return
        gray = to_grayscale(self.original_img, method='yuv')
        result = detect_edges(gray, direction=direction)
        self._show(result)
        labels = {'horizontal': 'poziome', 'vertical': 'pionowe', 'diagonal': 'ukośne'}
        self._set_status(f"Lab 04: Krawędzie {labels[direction]}")

    def lab04_all_edges(self):
        if not self._require_image(): return
        gray = to_grayscale(self.original_img, method='yuv')
        eh = detect_edges(gray, 'horizontal')
        ev = detect_edges(gray, 'vertical')
        ed = detect_edges(gray, 'diagonal')
        combined = combine_edges(combine_edges(eh, ev), ed)
        self._show(combined)
        self._set_status("Lab 04: Wszystkie krawędzie (poziome + pionowe + ukośne)")

    def lab04_subtract(self):
        if not self._require_image(): return
        path = filedialog.askopenfilename(
            title="Wybierz drugi obraz do odjęcia",
            filetypes=[("Obrazy", "*.png *.jpg *.jpeg *.bmp")]
        )
        if not path: return
        img2 = cv.imread(path)
        if img2 is None:
            messagebox.showerror("Błąd", "Nie udało się wczytać drugiego obrazu!"); return

        # Dopasowanie rozmiarów
        h, w = self.original_img.shape[:2]
        img2_resized = img2[:h, :w] if img2.shape[0] >= h and img2.shape[1] >= w else img2

        gray1 = to_grayscale(self.original_img, method='yuv')
        gray2 = to_grayscale(img2_resized, method='yuv')

        # Dopasowanie wymiarów po konwersji
        min_h = min(gray1.shape[0], gray2.shape[0])
        min_w = min(gray1.shape[1], gray2.shape[1])
        result = subtract_images(gray1[:min_h, :min_w], gray2[:min_h, :min_w])
        self._show(result)
        self._set_status("Lab 04: Odejmowanie dwóch obrazów")

    # ------------------------------------------------------------------ #
    #  LAB 05 – Operacje geometryczne                                      #
    # ------------------------------------------------------------------ #

    def lab05_translate(self):
        if not self._require_image(): return
        tx = simpledialog.askstring("Translacja", "Przesunięcie X (piksele):", parent=self.root)
        ty = simpledialog.askstring("Translacja", "Przesunięcie Y (piksele):", parent=self.root)
        if tx is None or ty is None: return
        try:
            tx, ty = int(tx), int(ty)
        except ValueError:
            messagebox.showerror("Błąd", "Podaj liczby całkowite!"); return
        result = translate(self.original_img, tx, ty)
        self._show(result)
        self._set_status(f"Lab 05: Translacja – tx={tx}, ty={ty}")

    def lab05_rotate(self):
        if not self._require_image(): return
        val = simpledialog.askstring("Obrót", "Kąt obrotu (stopnie):", parent=self.root)
        if val is None: return
        try:
            angle = float(val)
        except ValueError:
            messagebox.showerror("Błąd", "Podaj liczbę!"); return
        result = rotate(self.original_img, angle)
        self._show(result)
        self._set_status(f"Lab 05: Obrót – kąt={angle}°")

    def lab05_scale(self):
        if not self._require_image(): return
        sx = simpledialog.askstring("Skalowanie", "Współczynnik X (np. 1.5):", parent=self.root)
        sy = simpledialog.askstring("Skalowanie", "Współczynnik Y (np. 1.5):", parent=self.root)
        if sx is None or sy is None: return
        try:
            sx, sy = float(sx), float(sy)
        except ValueError:
            messagebox.showerror("Błąd", "Podaj liczby!"); return
        result = scale(self.original_img, sx, sy)
        self._show(result)
        self._set_status(f"Lab 05: Skalowanie – sx={sx}, sy={sy}")

    def lab05_shear(self):
        if not self._require_image(): return
        shx = simpledialog.askstring("Pochylenie", "Współczynnik shear X (np. 0.3):", parent=self.root)
        shy = simpledialog.askstring("Pochylenie", "Współczynnik shear Y (np. 0.0):", parent=self.root)
        if shx is None or shy is None: return
        try:
            shx, shy = float(shx), float(shy)
        except ValueError:
            messagebox.showerror("Błąd", "Podaj liczby!"); return
        result = shear(self.original_img, shx, shy)
        self._show(result)
        self._set_status(f"Lab 05: Pochylenie – shx={shx}, shy={shy}")

    def lab05_flip(self, mode):
        if not self._require_image(): return
        result = flip(self.original_img, mode)
        self._show(result)
        labels = {'horizontal': 'poziome (OY)', 'vertical': 'pionowe (OX)', 'both': 'środkowe'}
        self._set_status(f"Lab 05: Odbicie {labels[mode]}")

    # ------------------------------------------------------------------ #
    #  LAB 06 – Filtracja nieliniowa                                       #
    # ------------------------------------------------------------------ #

    def lab06_filter(self, filter_type):
        if not self._require_image(): return
        val = simpledialog.askstring(
            "Rozmiar maski",
            "Podaj rozmiar maski (nieparzysty, np. 3, 5, 7):",
            parent=self.root
        )
        if val is None: return
        ok, kernel = validate_kernel_size(val)
        if not ok:
            messagebox.showerror("Błąd", kernel); return

        gray = to_grayscale(self.original_img, method='yuv')

        self._set_status(f"Lab 06: Trwa filtracja {filter_type} {kernel}x{kernel}... Proszę czekać.")
        self.root.update()

        result = nonlinear_filter(gray, filter_type=filter_type, kernel_size=kernel)
        self._show(result)
        labels = {'median': 'medianowa', 'min': 'minimum', 'max': 'maksimum'}
        self._set_status(f"Lab 06: Filtracja {labels[filter_type]} – maska {kernel}x{kernel}")


# ------------------------------------------------------------------ #
#  URUCHOMIENIE APLIKACJI                                              #
# ------------------------------------------------------------------ #

if __name__ == "__main__":
    root = tk.Tk()
    app = App(root)
    root.mainloop()