#include <iostream>
using namespace std;
/*
Napisz program  "zadanie3.cpp", w którym użytkownik podaje 3 zmienne całkowite nieujemne, a program (używając IF) wyświetli:
- która wartość jest największa
- czy da się z takich długości odcinków zbudować trójkąt (czyli czy najdłuży < suma pozostałych)
*/
class Trojkat{
    public:
        int a,b,c;
        Trojkat(){
            cout <<"Podaj wartosc zmiennej a: ";
            cin >> a; 
            cout <<"\nPodaj wartosc zmiennej b: ";
            cin >> b;
            cout <<"\nPodaj wartosc zmiennej c: ";
            cin >> c;
        }
        void najwieksza(){
            if(a>=b&&a>=c)
            {
                cout<<"a jest najwieksze";
            }
            else if(b>=c)
            {
                cout<<"b jest najwieksze";
            }
            else
            {
                cout<<"c jest najwieksze";
            }
        }
        void triangle()
        {
            /*
            warunki potrzebne a + b>c , 
            */
            cout <<"\n";
            if(a + b>c && a+c >b&& b+c >a)
            {
                cout << "Mozna zbudowac trojkata: ";
            }
            else
            {
                cout <<"Nie mozna zbudowac trojkat: ";
            }
        }
};

int main() {
    Trojkat trojkat;
    trojkat.najwieksza();
    trojkat.triangle();
    return 0;
}
