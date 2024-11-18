#include <iostream>
using namespace std;
/*
Zadanie 2
Napisz program (z klasą) obliczający sumę liczb nieparzystych z przedziału <x,y>. Wartości x i y podaje użytkownik.*/
class zadanie2{
    public:
        int x,y;
        void pobranie()
        {
            cout << "Podaj wartość x: ";
            cin >> x;
            cout << "Podaj wartość y: ";
            cin >> y;
        }
        void warunek()
        {
            if((x%2!=0)&&(y%2!=0)) 
            {
                int c = x + y;
                cout <<"Suma liczb nieparzystych: "<<c;
            }
            else{
                cout << "Podaj poprawne liczby: ";
            }
        }
};
int main() {
    zadanie2 zad;
    zad.pobranie();
    zad.warunek();
    return 0;
}
