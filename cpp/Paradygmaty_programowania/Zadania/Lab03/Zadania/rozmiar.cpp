#include <iostream>
#include <limits>
//wyswietlenie rozmiaru tych zmiennych 
enum   Level
{
    Low,
    Medium,
    High
};

int main()
{
    std::cout<<"Rozmiary typow danych wypisane w kolejnosci: "<<std::endl;
    std::cout<<"Zakres unsigned short:"<<"\nMin: "<<std::numeric_limits<unsigned short>::min()<<"\nMax: "<<std::numeric_limits<unsigned short>::max()<<std::endl;
    std::cout<<"Rozmiar zmiennej unsigned short: "<<sizeof(unsigned short)<<std::endl<<std::endl;
     std::cout<<"Zakres int:"<<"\nMin: "<<std::numeric_limits<int>::min()<<"\nMax: "<<std::numeric_limits<int>::max()<<std::endl;
    std::cout<<"Rozmiar zmiennej int: "<<sizeof(int)<<std::endl<<std::endl;
     std::cout<<"Zakres float"<<"\nMin: "<<std::numeric_limits<float>::min()<<"\nMax: "<<std::numeric_limits<float>::max()<<std::endl;
    std::cout<<"Rozmiar zmiennej float: "<<sizeof(float)<<std::endl<<std::endl;
     std::cout<<"Zakres long"<<"\nMin: "<<std::numeric_limits<long>::min()<<"\nMax: "<<std::numeric_limits<long>::max()<<std::endl;
    std::cout<<"Rozmiar zmiennej long: "<<sizeof(long)<<std::endl<<std::endl;
     std::cout<<"Zakres signed int"<<"\nMin: "<<std::numeric_limits<signed int>::min()<<"\nMax: "<<std::numeric_limits<signed int>::max()<<std::endl;
    std::cout<<"Rozmiar zmiennej signed int: "<<sizeof(signed int)<<std::endl<<std::endl;
    std::cout<<"Rozmiar zmiennej enum: "<<sizeof(Level)<<std::endl<<std::endl;
     std::cout<<"Zakres long long"<<"\nMin: "<<std::numeric_limits<long long>::min()<<"\nMax: "<<std::numeric_limits<long long>::max()<<std::endl;
    std::cout<<"Rozmiar zmiennej long long: "<<sizeof(long long )<<std::endl<<std::endl;
     std::cout<<"Zakres zmiennej double"<<"\nMin: "<<std::numeric_limits<double>::min()<<"\nMax: "<<std::numeric_limits<double>::max()<<std::endl;
    std::cout<<"Rozmiar zmiennej double: "<<sizeof(double)<<std::endl;
    return 0;
}