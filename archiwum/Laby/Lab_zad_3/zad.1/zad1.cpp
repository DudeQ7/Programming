#include <iostream>
using namespace std;

/*
Zadanie 1:
Napisz klasę zawierającą metody:
pobierz() - metoda pobiera wartości 2 zmiennych x i y. Obie zmienne muszą być dodatnie i żadna nie może być większa od 30. Użyj pętli.
wyswietl() - metoda ma narysować prostokąt o wymiarach x i y. Do rysowania użyj dwóch pętli for.
Ten sam kod wykorzystalem , przy zad.7 z chatu
*/


class Zadanie1 {
public:
    int x, y;

    // Pobranie wartości od użytkownika
    void pobierz() {
        do {
            cout << "Podaj wartosc x (1-30):[pionowo] ";
            cin >> x;
            cout << "Podaj wartosc y (1-30):[poziomo] ";
            cin >> y;

            if (x <= 0 || x > 30 || y <= 0 || y > 30) {
                cout << "Niepoprawne dane. Wartosc x i y musza byc dodatnie i nie wieksze niz 30.\n";
            }
        } while (x <= 0 || x > 30 || y <= 0 || y > 30); // Powtarzaj aż do poprawnych danych
    }

    // Wyświetlenie prostokąta
    void wyswietl() {
        for (int i = 0; i < x; i++) {      // Pętla dla wierszy
            for (int j = 0; j < y; j++) { // Pętla dla kolumn
                cout << "#";
            }
            cout << endl; // Nowa linia po każdym wierszu
        }
    }
};

int main() {
    Zadanie1 zad;
    zad.pobierz();
    zad.wyswietl();
    return 0;
}
