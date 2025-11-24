#include <iostream>
/*
Zadanie 3
Napisz klasę zawierającą:
zmienne typu całkowitego nieujemnego: a,b,c
metody: z1, z2, z3, z4 oraz pobierz
pobierz() - pobiera wartość a (dowolne), b( b musi być większe od a, użyj pętli), c (c musi być różne od 0, użyj pętli) done
z1() -  wyświetla na ekranie liczby parzyste z zakresu od a do b ||done
z2() -  wyświetla na ekranie liczby nieparzyste z zakresu od b do a ||done
z3() - oblicza sumę liczb z zakresu od a do b
z4() - wyświetla liczby z zakresu od a do b podzielne bez reszty przez c, oblicz i wyświetl sumę i średnią wartość tych liczb
*/
using namespace std;
class zadanie3
{
    public:
       unsigned int a=0,b=0,c=0;
       int a1=0,b1=0,c1=0;
       void pobierz()
       {
            cout << "Podaj wartosc a: ";
            cin >> a;            
            do
            {
                cout << "Podaj wartosc b: ";
                cin >> b;
            }
            while(b<=a);
            do
            {
                 cout << "Podaj wartosc c: ";
                cin >> c;
            }
            while(c==0);
       }
       void z1()
       {
            for(int i=a; i<=b; i++)
            {
                cout <<"Liczby parzyste z zakresu: "<<a<<" oraz: "<<b<<endl;
                    if(i%2==0)
                    {
                        cout <<"      Liczby parzyste to: "<<i<<endl;
                    }
            }
       }
       void z2()
       {
        for(int i=b; i>=a; i-- )
        {
            cout<<"Liczby nieparzyste z zakresu: "<<b<<" do: "<<a<<endl;
                if(i%2!=0)
                {
                    cout <<"      Liczby nieparzyste to: "<<i<<endl;
                }
        }
       }
       void z3()
       {
        //z3() - oblicza sumę liczb z zakresu od a do 
            cout <<"Suma liczba z zakresu od: "<<a<<" do: "<<b<<" to: "<<endl;
            int suma = 0,liczba =1;
            for(int i=a; i<=b; i++)
            {
                suma += i;
                cout<<"Suma "<<liczba<<" ,"<<" liczb: " <<i<<" oraz: "<<b<<" to: "<<suma<<endl;
                liczba++;
            }
       }
       void z4()
       {
        //z4() - wyświetla liczby z zakresu od a do b podzielne bez reszty przez c, oblicz i wyświetl sumę i średnią wartość tych liczb
        int suma=0,liczba=0,iteracja = 1;
        cout <<"Liczby z zakresu od: "<<a<<" do: "<<b<<" podzielne bez reszty przez: "<<c<<" :"<<endl;
            for(int i=a; i<=b; i++)
            {
                if(i%c==0)
                {
                    cout <<"Liczba "<<"numer: "<<iteracja<<" to: "<<i<<endl;
                    suma +=i; 
                    liczba++;    
                    iteracja++;  
                }
            }
                if(liczba>0)
                {
                    int srednia = suma /liczba;
                    cout <<"Suma liczb: "<<suma<<endl;
                    cout <<"Srednia liczb: "<<srednia<<endl;
                }
                else
                {
                    cout << "Brak liczb podzielnych przez: "<<c<<" w tym zakresie"<<endl;
                }
                    
       }
};
int main() {
zadanie3 zad;
    zad.pobierz();
    zad.z1();
    zad.z2();
    zad.z3();
    zad.z4();
    return 0;
}
