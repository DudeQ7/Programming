// Wywołanie metody wirtualnej w konstruktorze nie działa 
// „polimorficznie” jak zwykle się tego oczekuje
// w konstruktorze klasy bazowej działa wersja bazowa, a nie pochodna.
 
#include <iostream>

using namespace std;
 
class Bazowa

{

public:

    Bazowa()

    {

        pokaz();

    }
 
    virtual void pokaz()

    {

        cout << "Bazowa::pokaz()" << endl;

    }

};
 
class Pochodna : public Bazowa

{

public:

    void pokaz() override

    {

        cout << "Pochodna::pokaz()" << endl;

    }

};
 
int main()

{

    Pochodna p;

}
 