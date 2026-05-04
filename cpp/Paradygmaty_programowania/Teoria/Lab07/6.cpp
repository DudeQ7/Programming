// Obiekt klasy pochodnej może zostać „ucięty” przy kopiowaniu do klasy bazowej
// - przekazanie przez wartość może „obciąć” część pochodną obiektu.
#include <iostream>
using namespace std;
 
class Bazowa
{
public:
    virtual void pokaz()
    {
        cout << "Bazowa" << endl;
    }
};
 
class Pochodna : public Bazowa
{
public:
    void pokaz() override
    {
        cout << "Pochodna" << endl;
    }
};
 
void test(Bazowa b)
{
    b.pokaz();
}
 
int main()
{
    Pochodna p;
    test(p); // object slicing
}