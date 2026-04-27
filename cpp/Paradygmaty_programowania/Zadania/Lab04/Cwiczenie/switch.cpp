#include <iostream>
int main()
{
    int dzien_tygodnia =0;
    std::cout<<"Podaj dzien tygodnia(1-7): ";
    std::cin>>dzien_tygodnia;
    switch (dzien_tygodnia)
    {
    case 1:
        std::cout<<"Poniedzialek"<<std::endl;
        std::cout<<"dzien roboczy"<<std::endl;
        break;
     case 2:
        std::cout<<"Wtorek"<<std::endl;
        std::cout<<"dzien roboczy"<<std::endl;
        break;
     case 3:
        std::cout<<"Sroda"<<std::endl;
        std::cout<<"dzien roboczy"<<std::endl;
        break;
     case 4:
        std::cout<<"Czwartek"<<std::endl;
        std::cout<<"dzien roboczy"<<std::endl;
        break;
     case 5:
        std::cout<<"Piatek"<<std::endl;
        std::cout<<"dzien roboczy"<<std::endl;
        break;
     case 6: 
        std::cout<<"Sobota"<<std::endl;
        std::cout<<"Dzien nie roboczy"<<std::endl;
        break;
    case 7: 
        std::cout<<"Niedziela"<<std::endl;
        std::cout<<"Dzien nie roboczy"<<std::endl;
        break;
    default:
        std::cout<<"Liczba spoza zakresu";
        break;
    }
    return 0; 
}