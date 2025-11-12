#include <iostream>
/*
    Napisz klasę obliczNWD, zawierającą metodę podajLiczby – gdzie należy wprowadzić dwie liczby całkowite i
dodatnie, oraz metodę obliczNWD - która wyświetli największy wspólny dzielnik tych dwóch liczb trywialną
metodą Euklidesa. Użyj pętli while.
    Przyklad:
    NWD dla liczb 6 i 8 wynosi 2  
*/
/*
https://www.matemaks.pl/algorytm-euklidesa.html
Aby obliczyć NWD(a,b), wykonujemy kolejno następujące kroki:
    Dzielimy z resztą liczbę a przez liczbę b
        jeżeli reszta jest równa 0, to NWD(a,b)=b
        jeżeli reszta jest różna od 0, to przypisujemy liczbie a wartość liczby b, liczbie b wartość otrzymanej reszty, a następnie wykonujemy ponownie punkt 1.

*/
using namespace std;
class obliczNWD
{
    public: 
        int liczba_1,liczba_2;
            void podajLiczby()
            {
                cout<<"Podaj wartosc liczby nr1: ";
                cin >> liczba_1;
                cout <<"Podaj wartosc liczby nr2: ";
                cin >> liczba_2;
                
                if((liczba_1>0)&&(liczba_2>0))
                {
                    cout << "Podales poprawne liczby!";
                }
                else
                {
                    cout << "Podales nieprawidlowe liczby!";
                }
            }
            void oblicz_NWD()
            {
                int a = liczba_1,b = liczba_2;
              while(b != 0)  
              {                
                int liczba = b;
                b = a%b; 
                a = liczba;     
              }            
                    cout <<"\nNWD dla liczb to: "<<a<<endl;

            }
};
int main() {
    obliczNWD zad;
    zad.podajLiczby();
    zad.oblicz_NWD();
    return 0;
}
