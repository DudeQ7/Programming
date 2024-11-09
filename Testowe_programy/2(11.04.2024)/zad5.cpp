#include <iostream>
using namespace std;
/*
IF Ćwiczenie 5
Zadanie 2
Napisz program, w którym user poda liczbę, a program wyświetli:
- czy liczba jest parzysta / nieparzysta  done
- czy jest dodatnia/ujemna/równa 0 done
- czy jest z zakresu od -5 do 5*/
class zadanie5{
    public:
        int liczba;
    void wprowadzenie(){
        cout << "Podaj wartosc liczby numer 1: ";
        cin >> liczba;
    }
    void dzialania(){
        if(liczba %2 ==0)
        {
            cout << "Podana liczba jest parzysta"<<endl;
        }
        else 
        {
            cout << "Podana liczba jest nie parzysta"<<endl;
        }
        if(liczba >0)
        {
            cout << "Podana liczba jest ujmena"<<endl;
        }
        else if(liczba<0)
        {
            cout << "Podana liczba jest ujemna"<<endl;
        }
        else
        {
            cout << "Podana liczba jest rowna 0: "<<endl;
        }
        if(liczba >= -5 && liczba <=5)
        {
            cout << "Liczba nalezy do zakresu od -5 do 5 "<<endl;
        }
        else 
        {
            cout << "Liczba nie nalezy do zakresu od -5 do 5 "<<endl;
        }
    }
};
int main() {
    zadanie5 zad ;
    zad.wprowadzenie();
    zad.dzialania(); 
    return 0;
}
