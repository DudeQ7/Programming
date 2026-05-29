#include <iostream>
int main()
{
    int a,b;
    std::cout << "Podaj liczbe numer_1: ";
    std::cin >> a;
    std::cout << "Podaj liczbe numer_2: ";
    std::cin >> b;
    if(a > b)
    {
        std::cout<<"Wieksza liczba to: "<<a;
    }
    else
    {
        std::cout<<"Wieksza liczba to: "<<b;
    }
    return 0;
}