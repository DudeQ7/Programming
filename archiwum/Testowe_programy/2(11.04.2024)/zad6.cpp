#include <iostream>
using namespace std;
/*
CASE Ćwiczenie 1
Napisz program, w którym użytkownik podaje wartość z zakresu od 1 do 7.
Jeżeli wartość jest poza tym zakresem, program wyswietla "Zła wartość"
Jeżeli wartość jest w zakresie, program wyswietla odpowiadający liczbie dzień tygodnia:
1- poniedzialek
2- wtorek
3- środa
itd
*/
class zadanie6{
public:
    int dzien_tygodnia;
    void zapytanie(){
        cout << "Podaj liczbe z zakresu od 1 do 7: "<<endl;
        cin >> dzien_tygodnia;
    }
    void dzialanie(){
        if(dzien_tygodnia >=1 && dzien_tygodnia <=7)
        {
            cout << "Podana dzien_tygodnia znajduje sie w tym zakresie "<<endl;
            switch(dzien_tygodnia)
            {
                case 1:
                    cout << "Poniedzialek"<<endl;
                    break;
                case 2:
                    cout<<"Wtorek"<<endl;
                    break;
                case 3:
                    cout <<"Sroda"<<endl;
                    break;
                case 4:
                    cout <<"Czwartek"<<endl;
                    break;
                case 5:
                    cout << "Piatek"<<endl;
                    break;
                case 6:
                    cout <<"Sobota"<<endl;
                    break;
                case 7:
                    cout << "Niedziela"<<endl;
                    break;

            }
        }
        else
        {
            cout <<"Podany dzien_tygodnia nie znajduje sie w tym zakresie "<<endl<<"Podaj inna liczbe!";
        }
    }
};


int main() {
    zadanie6 zad ;
    zad.zapytanie();
    zad.dzialanie();
    return 0;
}
