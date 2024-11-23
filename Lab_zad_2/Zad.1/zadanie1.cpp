#include <iostream>
using namespace std;

/*
Napisz program "zadanie1.cpp"
Program ma wyswietlić menu: (void menu)
1- dodawanie done
2- odejmowanie done 
3- dzielenie done 
4- mnozenie done 
5- modulo done
Nastepnie ma pobrać wartość (nr dzialania) do zmiennej int menu

Jeżeli menu jest równe 1, to program ma poprosic o podanie 2 zmiennych, a nastepnie wyswietlić wynik ich dodawania.
Tak samo dla menu równego 2,3,4 i 5.
Pamiętaj - nie mozna dzielić przez 0. (modulo też)
Każde działanie ma być osobną metodą.
Wszystkie działania (poza modulo) na zmiennych float.
*/
class zadanie1 
{
    public:
    int menu;
        void wybor()
        {
            cout <<"Wybierz dane dzialanie: "<<endl<< "1- dodawanie"<<endl<<"2- odejmowanie"<<endl<<"3- dzielenie"<<endl<<"4- mnozenie"<<endl<<"5- modulo"<<endl;
            cin >> menu; 
                switch(menu)
                {
                    case 1:
                    {

                   
                        float a ,b;
                        cout <<"Podaj wartosc zmiennej numer 1: ";
                        cin >> a;
                        cout <<"Podaj wartosc zmiennej numer 2: ";
                        cin >> b;
                        float c=a+b;
                        cout <<"Wynik dodawania to: "<<c ;
                        break;
                    }
                    case 2:
                    {
                        float a ,b;
                        cout <<"Podaj wartosc zmiennej numer 1: ";
                        cin >> a;
                        cout <<"Podaj wartosc zmiennej numer 2: ";
                        cin >> b;
                        float c=a-b;
                        cout <<"Wynik odejmowania to: "<<c;
                        break;
                    }
                    case 3:
                    {
                        float a ,b;
                        cout <<"Podaj wartosc zmiennej numer 1: ";
                        cin >> a;
                        cout <<"Podaj wartosc zmiennej numer 2: ";
                        cin >> b;
                            if(b == 0 )
                            {
                                cout <<"Nie mozna dzielic przez 0";
                            }
                            else
                            {
                                float c = a /b;
                                cout << "Wynik dzielenia to : "<<c;
                            }
                        break;
                    }
                    case 4:
                    {
                        float a ,b;
                        cout <<"Podaj wartosc zmiennej numer 1: ";
                        cin >> a;
                        cout <<"Podaj wartosc zmiennej numer 2: ";
                        cin >> b;
                        float c = a * b ;
                        cout << "Wynik mnozenia to: "<<c;
                        break;
                    }
                    case 5:
                    {
                        int a ,b;
                        cout <<"Podaj wartosc zmiennej numer 1: ";
                        cin >> a;
                        cout <<"Podaj wartosc zmiennej numer 2: ";
                        cin >> b;
                            if(b==0)
                            {
                                cout << "Nie mozna dzielic przez 0";
                            }
                            else
                            {
                                int c = a %b;
                                cout << "Wynik dzielenia z modulo: "<<c;
                            }
                    }

                }
        }
};

int main() {
    zadanie1 zad;
    zad.wybor();
    return 0;
}
