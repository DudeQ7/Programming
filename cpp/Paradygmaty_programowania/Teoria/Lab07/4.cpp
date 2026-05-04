// Ukrywanie metody zamiast nadpisywania

// często oczekuje się „obu” metod, a tymczasem metoda z klasy pochodnej

// ukrywa nazwę odziedziczoną.

#include <iostream>

using namespace std;
 
class Bazowa

{

public:

    void pokaz(int x)

    {

        cout << "Bazowa: " << x << endl;

    }

};
 
class Pochodna : public Bazowa

{

public:

    void pokaz(double x)

    {

        cout << "Pochodna: " << x << endl;

    }

};
 
int main()

{

    Pochodna p;

    p.pokaz(5);     // wywola wersje z klasy pochodnej po konwersji

}
 