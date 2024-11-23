#include <iostream>
/*
Napisz program  "zadanie2.cpp", w którym użytkownik podaje 2 wartości:
int a1 i int a2 a program wyświetl na ekranie:
- czy obie wartości są dodatnie/ujemne/równe 0 done
- czy obie wartości są parzyste/nieparzyste
*/
using namespace std;
class zadanie2{
    public:
        int a1,a2; 
            void pobranie()
            {
                cout << "Podaj wartosc a: ";
                cin >> a1;
                cout << "Podaj wartosc b: ";
                cin >> a2;
            }
            void dzialanie()
            {
                if((a1 >0) && (a2 >0))
                {
                    cout << "Obie liczby sa dodatnie"<<endl;
                }
                else if((a1 < 0) && (a2 < 0))
                {
                    cout << "Obie liczby sa ujemne"<<endl;

                }
                else
                {
                    cout << "Obie liczby sa rowne 0"<<endl;
                }
                if((a1 %2 ==0)  && (a2 % 2 ==0))
                {
                    cout << "Obie wartosci sa parzyste"<<endl;
                }
                else if((a1%2==0)&&(a2%2!=0)||(a1%2!=0)&&(a2%2==0))
                {
                    cout << "Jedna z liczb jest parzysta. Jedna z liczb jest"<<endl;
                }
                else
                {
                    cout <<"Zadna wartosc nie jest parzysta lub nieparzysta "<<endl;
                }
                
            }
};
int main() {
    zadanie2 zad;
    zad.pobranie();
    zad.dzialanie();
    return 0;
}
