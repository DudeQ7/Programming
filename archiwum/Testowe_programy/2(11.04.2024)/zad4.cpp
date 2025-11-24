#include <iostream>
/*
IF Ćwiczenie 4
Napisz program, w ktorym user podaje wartość zmiennej int zmienna_1
Wyświetl na ekranie, czy zmienna_1 jest:
- dodatnia / ujemna/ rowna 0 done
- jest parzysta  done
- jest podzielna bez reszty przez 7 done
- jest wieksza od 0 i mniejsza od 10*/
using namespace std;
class zadanie4{
public: //pozwala wykorzystac zmienne w calym programie
    int zmienna_1;
    void wprowadzenie()
    {
        cout << "Podaj wartosc zmiennej numer 1: "<<endl;
        cin >> zmienna_1;
    }
    void warunki()
    {
        if(zmienna_1 % 2 == 0)
        {
            cout << "Podana liczba jest parzysta"<<endl;
        }
        else
        { 
            cout << "Podana liczba jest nieparzysta"<<endl;
        }
        if(zmienna_1 >0)
        {
            cout << "Podana liczba jest dodatnia: "<<endl;
        }
        else if (zmienna_1 < 0)
        {
            cout << "Podana liczba jest niedodatnia"<<endl;
        }
        else
        {
            cout << "Podana liczba jest rowna 0"<<endl;
        }
        if(zmienna_1 %7 == 0)
        {
            cout << "Podana liczba jest podzielna bez reszty przez 7"<<endl;
        }
        else
        {
            cout << "Podana liczba nie jest podzielna bez reszty przez 7 "<<endl;
        }
        if(zmienna_1 > 0 && zmienna_1 <10)
        {
            cout <<"Podana liczba jest wieksza od 0 i jest mniejsza od 10"<<endl;
        }
        else
        {
            cout << "Podana liczba nie jest  wieksza od 0 i nie jest mniejsza od 10"<<endl;
        }
    }
};
int main() {
    zadanie4 zad;
    zad.wprowadzenie();
    zad.warunki();
}
