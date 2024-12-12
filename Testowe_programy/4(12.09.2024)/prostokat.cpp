/*
Napisz funkcję:
1. void prostokat, która pobierze od użytkownika: 
- co obliczyć? (pole/obwód)
- wymagane dane (boki)
- sprawdzi czy dane są poprawne (dodatnie)
- obliczy i wyświetli wynik.
*/
#include <iostream>
#include <string>
using namespace std;
class prostokat
{
 public:
    int a,b; 
    string wybor;
        void prostokat_dz()
        {
            cout <<"Co chcesz dzisiaj obliczyc: pole lub obwod: ";
            cin >> wybor;
            if(wybor=="pole")
            {
                cout<<"Wybrales pole: "<<endl;
                cout <<"Podaj wartosc boku a: ";
                cin >>a;
                cout <<"Podaj wartosc boku b: ";
                cin >> b;
                    if(a>0&&b>0)
                    {
                        cout <<"Pole jest rowne: "<<a*b;
                    }
                    else
                    {
                        cout<<"Podales niepoprawne dane! ";
                    }
            }
            else
            {
                cout<<"Wybrales obwod: "<<endl;
                cout <<"Podaj wartosc boku a: ";
                cin >>a;
                cout <<"Podaj wartosc boku b: ";
                cin >> b;
                   if(a>0&&b>0)
                    {
                        cout <<"Pole jest rowne: "<<a*b;
                    }
                    else
                    {
                        cout<<"Podales niepoprawne dane! ";
                    }
                cout <<"Obwody jest rowny: "<<((2*a)+(2*b));
            }
        }
};

int main() {
    prostokat zad;
    zad.prostokat_dz();
    return 0;
}

 
 
 
