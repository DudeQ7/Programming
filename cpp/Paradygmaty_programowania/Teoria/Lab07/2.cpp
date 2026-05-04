 
// Z virtual wywoĹ‚a siÄ™ metoda klasy pochodnej

// to jest klasyczny przykĹ‚ad polimorfizmu dynamicznego
 
#include <iostream>

using namespace std;
 
class Zwierze

{

public:

    virtual void dzwiek()

    {

        cout << "Zwierze wydaje dzwiek" << endl;

    }

};
 
class Pies : public Zwierze

{

public:

    void dzwiek() override

    {

        cout << "Hau hau" << endl;

    }

};
 
int main()

{

    Pies p;

    Zwierze* wsk = &p;

    wsk->dzwiek(); // wypisze: Hau hau

}
 