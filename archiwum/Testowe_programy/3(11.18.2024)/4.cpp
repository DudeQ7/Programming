#include <iostream>
/*
Zadanie 4
Napisz program z klasą wypisujący liczby całkowite parzyste od liczby podanej przez użytkownika malejąco aż do 0.
*/
using namespace std;
class zadanie4{
    public:
        int x;
        void pobranie()
        {
            cout << "Podaj liczbe: ";
            cin >> x;
            int n =0;
                if(x%2==0)
                {
                    for(int i=0;x>i;x-=2)
                    {
                    cout<<"Liczba numer: "<<n++<<" = "<<x<<endl;
                    }
                }
                else
                {
                    cout <<"liczba nie jest parzysta";
                }
                
        }
};
using namespace std;

int main() {
    zadanie4 zad;
    zad.pobranie();
    return 0;
}
