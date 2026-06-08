# Instrukcja - Przechwytywanie Screenów do Robot Framework Horizon

## Cel
Przechwycić 3 screenshoty wyników kalkulatora dla testów automatycznych framework'a ImageHorizonLibrary.

## Wymagane screenshoty

### 1. Wynik dodawania: 7 + 7 = 14
- **Nazwa pliku:** `wynik_14.png`
- **Lokalizacja:** `images/wynik_14.png`
- **Kroki:**
  1. Otwórz kalkulator Windows (calc.exe)
  2. Zmaksymalizuj okno
  3. Naciśnij: `7` → `+` → `7` → `=`
  4. Zrób screenshot pokazujący WYNIK **14** na ekranie kalkulatora
  5. Zapisz screenshot jako `wynik_14.png` w folderze `images/`

### 2. Wynik odejmowania: 7 - 7 = 0
- **Nazwa pliku:** `wynik_0.png`
- **Lokalizacja:** `images/wynik_0.png`
- **Kroki:**
  1. Otwórz kalkulator Windows (calc.exe)
  2. Zmaksymalizuj okno
  3. Naciśnij: `7` → `-` → `7` → `=`
  4. Zrób screenshot pokazujący WYNIK **0** na ekranie kalkulatora
  5. Zapisz screenshot jako `wynik_0.png` w folderze `images/`

### 3. Wynik mnożenia: 7 * 7 = 49
- **Nazwa pliku:** `wynik_49.png`
- **Lokalizacja:** `images/wynik_49.png`
- **Kroki:**
  1. Otwórz kalkulator Windows (calc.exe)
  2. Zmaksymalizuj okno
  3. Naciśnij: `7` → `*` → `7` → `=`
  4. Zrób screenshot pokazujący WYNIK **49** na ekranie kalkulatora
  5. Zapisz screenshot jako `wynik_49.png` w folderze `images/`

## Ważne notatki

- ✅ Kalkulator MUSI być **zmaksymalizowany** (całe okno na całym ekranie)
- ✅ Screenshot powinien zawierać **wyłącznie okno kalkulatora**
- ✅ Wynik musi być **wyraźnie widoczny** w polu wynikowym kalkulatora
- ✅ Nazwa pliku musi być **dokładnie** taka jak podana
- ✅ Format: **PNG** (nie JPG, nie BMP)
- ✅ Pliki umieść w folderze: `C:\Users\DudeQ\Documents\Programming\Python\Robot_framework\Testowanie_oprogramowania\Zadanie_3\Horizon\images\`

## Status testów

### Aktualnie działające (z walidacją):
- ✅ **Dzielenie:** 7 / 7 = 1 (walidacja: przycisk_1.png)

### Po dodaniu screenów będą walidowane:
- 🔜 **Dodawanie:** 7 + 7 = 14 (walidacja: wynik_14.png)
- 🔜 **Odejmowanie:** 7 - 7 = 0 (walidacja: wynik_0.png)
- 🔜 **Mnożenie:** 7 * 7 = 49 (walidacja: wynik_49.png)

## Jak uruchomić testy

```bash
cd "C:\Users\DudeQ\Documents\Programming\Python\Robot_framework\Testowanie_oprogramowania\Zadanie_3\Horizon"
python run_tests.py
```

## Konfiguracja ImageHorizon

- **Confidence Level:** 0.58 (musi być co najmniej 0.58)
- **Library:** ImageHorizonLibrary
- **Sleep po operacji:** 5s zaraz po starcie, 2s po równości

---

**Autor:** Bot AI
**Data:** 2026-06-08
**Status:** Oczekuje na dodanie screenów wyników
