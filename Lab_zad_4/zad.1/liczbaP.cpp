#include <iostream>
using namespace std;
/*
Napisz klasę liczbaPierwsza, zawierającą metodę sprawdz(), która wyświetli czy podana liczba całkowita
nieujemna jest liczbą pierwszą. Użyj pętli for
Przyklad - sprawdz dla liczby 7
7 = liczba pierwsza 
to liczba ktora dzieli sie przez 1 i przez sama siebie 
*/
class liczbaPierwsza
{
    public:
        int liczba,n;
        bool czy_pierwsza=true;
        void sprawdz()
        {
            cout << "Podaj liczbe dodatnia: ";
            cin >> liczba;
                if(liczba==0||liczba==1)
                {
                   czy_pierwsza = false;
                }
                    for(int i=2; i<=liczba/2; i++)
                    {
                        if(liczba%i==0)
                        czy_pierwsza =false;
                    }
                    if(czy_pierwsza)
                    {
                        cout<<liczba<<" = liczba pierwsza"<<"\nto liczba ktora dzieli sie przez 1 przez sama siebie "<<endl;
                    }
                    else
                    {
                        cout<<liczba<<" = nie jest liczba pierwsza"<<"\nto nie jest liczba ktora dzieli sie przez 1 przez sama siebie "<<endl;
                    }
        }
};
using namespace std;

int main() {
    liczbaPierwsza zad;
    zad.sprawdz();
    return 0;
}
