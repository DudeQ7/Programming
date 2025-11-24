#include <iostream>
using namespace std;
/*
Napisz program z klasą sumujący wartości ciągu n liczb podawanych przez użytkownika. Ilość liczb podaje użytkownik jako pierwszą wartość. 
Musi być to wartość dodatnia (użyj pętli)
wzor na sume ciagu arytmetycznego (S5 = a1 + a5 /2 *5)
zalozmy an=3n+1 a1
*/
class zadanie6
{
    public:
        int n;
        int a1 = 4;
        void pobranie()
        {
            cout << "Podaj ilosc liczb: ";
                if(n>0)
                {
                    cin >> n;
                }  
                else
                {
                    cout << "Wartosc musi byc dodatnia" << endl;
                }
        }
        void dzialanie()
        {
            int i =0;
            while(i<n)
            {
                int dzialanie = ((a1 *3 *i +1) /2) * i     ;
                i++;
                cout << "Wartosc liczby nr " << i << " to: " << dzialanie << endl;
            }
        }
};
int main()
{
    zadanie6 zad;
    zad.pobranie();
    zad.dzialanie();  
    return 0;
}
