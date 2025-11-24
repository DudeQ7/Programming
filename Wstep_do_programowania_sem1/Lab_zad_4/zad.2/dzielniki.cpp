#include <iostream>
using namespace std;
/*
    Napisz klasę dzielniki Liczby, zawierającą metodę wyswietl(), która wyświetli wszystkie dzielniki całkowite
    podanej liczby. Użyj pętli do while.
    Przyklad - wyswietl dla liczby 20:
    1,2,4,5,10,20
*/
class dzielniki_liczby
{
    public:
        int liczba,i=1,c=(liczba%i); //i ma wartosc 1 , zeby nie bylo dzielenia przez 0
        void wyswietl()
        { 
            cout << "Podaj liczbe: ";
            cin>>liczba;
            cout << "Dzielniki liczby to: ";
            do 
            {
                if(liczba%i==0)
                {               
                    cout <<i<<" , ";
                }
            i++;
            } 
            while (i<=liczba);
        }         
};
using namespace std;
int main() {
    dzielniki_liczby zad;
    zad.wyswietl();
    return 0;
}
