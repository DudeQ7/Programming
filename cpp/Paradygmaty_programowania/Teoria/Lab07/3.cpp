
// private nie jest dziedziczone jako dostępne

// klasa pochodna dziedziczy część stanu klasy bazowej, 

// ale nie ma bezpośredniego dostępu do elementów prywatnych
 
#include <iostream>

using namespace std;
 
class Bazowa

{

protected:

    int x = 42;

};
 
class Pochodna : public Bazowa

{

public:

    void pokaz()

    {

        cout << x << endl; // dozwolone

    }

};
 
int main()

{

    Pochodna p;

    p.pokaz();

}
 