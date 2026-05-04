// Bez virtual wywoła się metoda klasy bazowej

// bo samo nadpisanie metody nie wystarcza do polimorfizmu dynamicznego.
 
#include <iostream>

using namespace std;
 
class Zwierze

{

public:

    void dzwiek()

    {

        cout << "Zwierze wydaje dzwiek" << endl;

    }

};
 
class Pies : public Zwierze

{

public:

    void dzwiek()

    {

        cout << "Hau hau" << endl;

    }

};
 
int main()

{

    Pies p;

    Zwierze* wsk = &p;

    wsk->dzwiek(); // wypisze: Zwierze wydaje dzwiek

}
