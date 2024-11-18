#include <iostream>
using namespace std;
/*
Zadanie 3
Napisz program z klasą, który wyświetli wszystkie liczby z przedziału od 50 do 100 podzielne przez dowolną liczbę k, która podaje użytkownik. Przekształć program tak aby przedział liczb również podawał użytkownik.*/
class zadanie3
{
    public:
        int k;
        int p1,p2;
        void pobranie()
        {
            cout << "Podaj liczbe przez jaka ma sie dzielic przedzial: ";
            cin >> k;
            cout << "Podaj pierwsza liczbe przedzialu: ";
            cin >> p1;
            cout <<"Podaj druga liczbe przedzialu: ";
            cin >> p2;
        }
        void dzialanie()
        {
           for(int i=0; i>p1&&i<p2; i++)
           {
            
                cout <<"liczba "<<" "<< i << " "<<endl;
            
           } 
        }
};
int main() {
    zadanie3 zad;
    zad.pobranie();
    zad.dzialanie();
    return 0;
}
