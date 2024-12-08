#include <iostream>
using namespace std;

class liczbaPierwsza {
public:
    int liczba;
    void sprawdz() 
    {
        cout << "Podaj liczbe dodatnia: ";
        cin >> liczba;
        int dzielniki = 0; 
        if (liczba == 0 || liczba == 1) {
            cout << liczba << " = nie jest liczba pierwsza\n";
        } else {
            for (int i = 1; i <= liczba; i++) {
                if (liczba % i == 0) {
                    dzielniki++;
                }
            }
            if (dzielniki == 2) {
                cout << liczba << " = liczba pierwsza\n";
                cout << "to liczba, ktora dzieli sie przez 1 i przez sama siebie\n";
            } else {
                cout << liczba << " = nie jest liczba pierwsza\n";
            }
        }
    }
};

int main() {
    liczbaPierwsza zad;
    zad.sprawdz();
    return 0;
}
