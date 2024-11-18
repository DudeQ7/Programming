#include <iostream>
using namespace std;
/*
Napisz program, który pobierze od użytkownika zmienną a1, jeżeli wartość a1 będzie poza zakresem od 1 do 11 metoda poprosi
o ponowne podanie wartosci.
 
Zadanie 2
Napisz program (z klasą) obliczający sumę liczb nieparzystych z przedziału <x,y>. Wartości x i y podaje użytkownik.
 
Zadanie 3
Napisz program z klasą, który wyświetli wszystkie liczby z przedziału od 50 do 100 podzielne przez dowolną liczbę k, która podaje użytkownik. Przekształć program tak aby przedział liczb również podawał użytkownik.
 
Zadanie 4
Napisz program z klasą wypisujący liczby całkowite parzyste od liczby podanej przez użytkownika malejąco aż do 0.*/
class zadanie1{
    public:
        int a1;
   
    void zakres()
    {
        do
        {
            cout << "Podaj wartosc a1: ";
            cin>>a1;
        }
        while(a1<1&&a1>11);      
            cout << "Good value: ";  
    }
};
using namespace std;

int main() {
        zadanie1 zad;
        zad.zakres();
    return 0;
}
