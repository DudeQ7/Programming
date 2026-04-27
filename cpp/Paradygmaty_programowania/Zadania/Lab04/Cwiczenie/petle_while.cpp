#include <iostream>
int main()
{
    int u_input=0,suma=0,liczba_argumentow=0;
    while(u_input!=0)
    {
        std::cout<<"Podaj liczbe: ";
        std::cin>>u_input;
        suma+=u_input;
        liczba_argumentow++;
    }
    std::cout<<"Suma to: "<<suma;
    std::cout<<"Srednia arytmetyczna to: "<<suma/liczba_argumentow;
    return 0;
}