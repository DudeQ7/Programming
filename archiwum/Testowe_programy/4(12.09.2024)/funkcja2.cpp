#include <iostream>
/*
Napisz funkcję funkcja_2 z parametrami typu float(a1,a2,a3,a4), która zwróci zmienną typu float o wartości 0.3 *a1 + 0.5*a2 +1.4*a3 +a4*/
using namespace std;
class zadanie2
{
    public:
        float a1=0,a2=0,a3=0,a4=0,zmienna = 0.3 *a1 + 0.5*a2 +1.4*a3 +a4;

    void funkcja2()
    {
        cout <<"Podaj wartosc a1: " << a1 << endl;
        cin >>a1;
        cout <<"Podaj wartosc a2: " << a2 << endl;
        cin >>a2;
        cout <<"Podaj wartosc a3: " << a3 << endl;
        cin >>a3;
        cout <<"Podaj wartosc a4: " << a4 << endl;
        cin >>a4;
        cout <<zmienna;
    }
};
int main() {
    zadanie2 zad;
    zad.funkcja2();
        return 0;
}
