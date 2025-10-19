#include <iostream>
int main()
{
    int tablica4[30];
    unsigned int a,b; //user input
    std::cout <<"Podaj wartosc a[dodatnia liczba]: ";
    std::cin >> a;
    std::cout<<"Podaj wartosc b[dodatnia liczba]: ";
    std::cin >> b;
    //tablica4[0]=a;
    //potencjalny blad
    int last=a+b;
    for (int i=0; i<=30; i++)
    {   
        if(i==0)
        {
            std::cout<<"Element tablicy numer: "<<i<<" to: "<<a<<std::endl;
        }
        else
        {
            std::cout<<"Element tablicy numer: "<<i<<" to: "<<last<<std::endl;
            last+=b;

        }
    }
return 0;
}
