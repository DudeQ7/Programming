#include <iostream>
using namespace std;
/*
Zadanie 2
Napisz program z klasą sumujący wartości ciągu n liczb podawanych przez użytkownika. Ilość liczb podaje użytkownik jako pierwszą wartość. Musi być to wartość dodatnia (użyj pętli). Wyświetl ilość podanych liczb, ich średnią oraz ilość podanych poprawnie i niepoprawnie liczb (nie dodatnich).
metody:
pobierz() - pobiera wartość n, n>0,
wypelnij() - pobiera wartości od użytkownika, liczy sumę oraz ilość poprawnych i błędnych wartości
wyswietl() - oblicza srednie, wyświetla średnie i sumy,
*/
class zadanie2
{
    public:
        int n;
            void pobierz()
            {
                cout << "Podaj wartosc n: ";
                cin >> n;
                if(n>0)
                {
                    cout << "Podales poprawna liczbe";
                }
                else
                {
                    cout << "Podales niepoprawna liczbe. Wpisz ponownie.";
                }
                
            }
            void wypelnij()
            {
                int suma = 0 , poprawne = 0 , niepoprawne = 0,liczba = 0; ;
                for (int i = 0; i <n; i++)
                {
                     
                    cout << "Podaj liczbe nr: "<<liczba<<" :"<<endl;
                    liczba++;

                }

            }
};
using namespace std;

int main() {
    zadanie2 zad;
        zad.pobierz();
        zad.wypelnij();
    return 0;
}
