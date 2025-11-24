#include <iostream>
using namespace std;
/*
Zadanie 2
Napisz program z klasą sumujący  
pobierz() - pobiera wartość n, n>0, done
wypelnij() - pobiera wartości od użytkownika, liczy sumę oraz ilość poprawnych i błędnych wartości done
wyswietl() - oblicza srednie, wyświetla średnie i sumy done 
*/
class zadanie2
{
    public:
        int n,suma=0, poprawne = 0 , niepoprawne = 0,liczba = 0 ;

            void pobierz()
            {
                cout << "Podaj wartosc n: ";
                cin >> n; //warunek sprawdzajacy poprawnosc danych wejsciowych jest w linii 52
            }
            void wypelnij()
            {
                for (int i = 1; i <=n; i++)
                {
                    cout << "Podaj liczbe nr: "<<i<<" = ";
                    cin >> liczba;
                    suma+=liczba;
                        if(liczba>=0)
                        {
                            poprawne++;   
                        }
                        else
                        {
                            niepoprawne++;
                        }       
                }
            }
            void wyswietl()
            {
                //liczy sredniem, wyswietla sumy i srednie
                double srednia = suma /n;
                cout << "Srednia: " << srednia << endl;
                cout << "Suma liczb: " << suma << endl;
                cout << "Liczba poprawnych wartosci: " << poprawne << endl;
                cout << "Liczba niepoprawnych wartosci: " << niepoprawne << endl;
            }
};
using namespace std;

int main() {
    zadanie2 zad;
        zad.pobierz();
        if(zad.n >0) // ten check ma za zadanie sprawdzic by w przypadku liczby ujemnej nie komunikat wygladal w ten sposob(linia 75)
        {          
            zad.wypelnij();
            zad.wyswietl();
        }
        else if(zad.n==0)
        {
            cout << "Podales wartosc rowna 0. Wpisz ponownie."<<endl;
        }
        else
        {
            cout << "Podales wartosc ujemna. Wpisz ponownie."<<endl;
        }
    return 0;
}
  /*
                    Podaj wartosc n: -3
                    Podales wartosc ujemna. Wpisz ponownie.
                    Srednia: 0
                    Suma liczb: 0
                    Liczba poprawnych wartosci: 0
                    Liczba niepoprawnych wartosci: 0
                    */
        