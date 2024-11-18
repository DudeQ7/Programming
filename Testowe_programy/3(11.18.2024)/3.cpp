#include <iostream>
using namespace std;
/*
Zadanie 3
Napisz program z klasą, który wyświetli wszystkie liczby z przedziału od 50 do 100 podzielne przez dowolną liczbę k, która podaje użytkownik. Przekształć program tak aby przedział liczb również podawał użytkownik.*/
class zadanie3
{
    public:
        int k;
        int p1,p2;
        void pobranie()
        {
            
            cout << "Podaj liczbe przez jaka ma sie dzielic przedzial: ";
            cin >> k;
             cout << "Podaj pierwsza liczbe przedzialu: ";
            cin >> p1;
            cout <<"Podaj druga liczbe przedzialu: ";
            cin >> p2; 
        }
        void dzialanie()
        {
        int n =0;

            cout <<"Liczby podzielne przez "<<k<<" w przedziale od "<<p1<<" do "<<p2<<": "<<endl;  
                for(int i=p1; i<=p2; i++)
                {
                    if(i%k==0)
                    {
                        cout <<"Liczba numer: "<<n<<" jest rowna: "<< i << " "<<endl;
                        n++;
                    }                
                }
        }
};
int main() {
    zadanie3 zad;
    zad.pobranie();
    zad.dzialanie();
    return 0;
}
