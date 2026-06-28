import pytest
from playwright.sync_api import Page


# ── helpers ──────────────────────────────────────────────────────────────────

PRZYCISKI = {
    "0": "#btn-0", "1": "#btn-1", "2": "#btn-2", "3": "#btn-3",
    "4": "#btn-4", "5": "#btn-5", "6": "#btn-6", "7": "#btn-7",
    "8": "#btn-8", "9": "#btn-9", ".": "#btn-dot",
    "+": "#btn-add", "-": "#btn-sub", "*": "#btn-mul", "/": "#btn-div",
    "=": "#btn-eq",  "AC": "#btn-ac", "+/-": "#btn-sign", "%": "#btn-pct",
}


def nacisnij(page: Page, *klawisze: str) -> None:
    for k in klawisze:
        page.locator(PRZYCISKI[k]).click()


def wynik(page: Page) -> str:
    return page.locator("#display").input_value()


# ── dodawanie ─────────────────────────────────────────────────────────────────

class TestDodawanie:
    def test_dodawanie_jednocyfrowe(self, page: Page):
        """3 + 4 = 7"""
        nacisnij(page, "3", "+", "4", "=")
        assert wynik(page) == "7"

    def test_dodawanie_wielocyfrowe(self, page: Page):
        """12 + 34 = 46"""
        nacisnij(page, "1", "2", "+", "3", "4", "=")
        assert wynik(page) == "46"

    def test_dodawanie_z_zerem(self, page: Page):
        """0 + 9 = 9"""
        nacisnij(page, "0", "+", "9", "=")
        assert wynik(page) == "9"

    def test_dodawanie_duzych_liczb(self, page: Page):
        """999 + 1 = 1000"""
        nacisnij(page, "9", "9", "9", "+", "1", "=")
        assert wynik(page) == "1000"


# ── odejmowanie ───────────────────────────────────────────────────────────────

class TestOdejmowanie:
    def test_odejmowanie_podstawowe(self, page: Page):
        """9 - 3 = 6"""
        nacisnij(page, "9", "-", "3", "=")
        assert wynik(page) == "6"

    def test_odejmowanie_wynik_zero(self, page: Page):
        """7 - 7 = 0"""
        nacisnij(page, "7", "-", "7", "=")
        assert wynik(page) == "0"

    def test_odejmowanie_wynik_ujemny(self, page: Page):
        """3 - 8 = -5"""
        nacisnij(page, "3", "-", "8", "=")
        assert wynik(page) == "-5"

    def test_odejmowanie_wielocyfrowe(self, page: Page):
        """100 - 45 = 55"""
        nacisnij(page, "1", "0", "0", "-", "4", "5", "=")
        assert wynik(page) == "55"


# ── mnożenie ──────────────────────────────────────────────────────────────────

class TestMnozenie:
    def test_mnozenie_podstawowe(self, page: Page):
        """6 × 7 = 42"""
        nacisnij(page, "6", "*", "7", "=")
        assert wynik(page) == "42"

    def test_mnozenie_przez_zero(self, page: Page):
        """5 × 0 = 0"""
        nacisnij(page, "5", "*", "0", "=")
        assert wynik(page) == "0"

    def test_mnozenie_przez_jeden(self, page: Page):
        """8 × 1 = 8"""
        nacisnij(page, "8", "*", "1", "=")
        assert wynik(page) == "8"

    def test_mnozenie_wielocyfrowe(self, page: Page):
        """12 × 12 = 144"""
        nacisnij(page, "1", "2", "*", "1", "2", "=")
        assert wynik(page) == "144"


# ── dzielenie ─────────────────────────────────────────────────────────────────

class TestDzielenie:
    def test_dzielenie_podstawowe(self, page: Page):
        """8 ÷ 2 = 4"""
        nacisnij(page, "8", "/", "2", "=")
        assert wynik(page) == "4"

    def test_dzielenie_daje_ulamek(self, page: Page):
        """1 ÷ 4 = 0.25"""
        nacisnij(page, "1", "/", "4", "=")
        assert wynik(page) == "0.25"

    def test_dzielenie_przez_jeden(self, page: Page):
        """9 ÷ 1 = 9"""
        nacisnij(page, "9", "/", "1", "=")
        assert wynik(page) == "9"

    def test_dzielenie_przez_zero(self, page: Page):
        """5 ÷ 0 → wyświetla 'Błąd'"""
        nacisnij(page, "5", "/", "0", "=")
        assert wynik(page) == "Błąd"


# ── liczby ujemne / negacja ───────────────────────────────────────────────────

class TestLiczbyUjemne:
    def test_negacja_liczby_dodatniej(self, page: Page):
        """5 → +/- = -5"""
        nacisnij(page, "5", "+/-")
        assert wynik(page) == "-5"

    def test_negacja_dwukrotna_wraca_do_dodatniej(self, page: Page):
        """5 → +/- → +/- = 5"""
        nacisnij(page, "5", "+/-", "+/-")
        assert wynik(page) == "5"

    def test_dodawanie_z_liczba_ujemna(self, page: Page):
        """(-3) + 8 = 5"""
        nacisnij(page, "3", "+/-", "+", "8", "=")
        assert wynik(page) == "5"

    def test_mnozenie_dwoch_liczb_ujemnych(self, page: Page):
        """(-4) × (-3) = 12"""
        nacisnij(page, "4", "+/-", "*", "3", "+/-", "=")
        assert wynik(page) == "12"

    def test_odejmowanie_od_liczby_ujemnej(self, page: Page):
        """(-5) - 3 = -8"""
        nacisnij(page, "5", "+/-", "-", "3", "=")
        assert wynik(page) == "-8"
