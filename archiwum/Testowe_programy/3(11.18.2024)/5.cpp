#include <iostream>
#include <cmath>
using namespace std;
/*
Napisz program  wyświetlający n kolejnych potęg liczby 2. Wartość n podaje użytkownik, musi to być liczba naturalna większa od 0.
*/
class zadanie5
{
    public:
        int n ;
    void pobranie()
    {
        cout << "Podaj wartosc n: ";
        cin >> n;
    }
    void dzialanie()
    {
        
        int liczba = 0;
        while (liczba<=n)
        {
            int wartosc = pow(2, liczba);
           cout <<"Potega liczby numer: "<<liczba<<" jest rowna: "<<wartosc<<endl;
           liczba++;
        }
    }   
};
int main()
{
  zadanie5 zad;
  zad.pobranie();
  zad.dzialanie();  
    return 0;
}
