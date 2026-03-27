#include <iostream>
//wyswietlenie rozmiaru tych zmiennych 
int     test_zmienna0;
float   test_zmienna1;
long long test_zmienna2;
double  test_zmienna3;
long    test_zmienna4;
signed int  test_zmienna5;
unsigned short  test_zmienna6;
//enum    test_zmienna7;

int main()
{
    std::cout<<"Rozmiar zmiennej int: "<<sizeof(test_zmienna0)<<std::endl;
    std::cout<<"Rozmiar zmiennej float: "<<sizeof(test_zmienna1)<<std::endl;
    std::cout<<"Rozmiar zmiennej long long: "<<sizeof(test_zmienna2)<<std::endl;
    std::cout<<"Rozmiar zmiennej double: "<<sizeof(test_zmienna3)<<std::endl;
    std::cout<<"Rozmiar zmiennej long: "<<sizeof(test_zmienna4)<<std::endl;
    std::cout<<"Rozmiar zmiennej signed int: "<<sizeof(test_zmienna5)<<std::endl;
    std::cout<<"Rozmiar zmiennej unsigned short: "<<sizeof(test_zmienna6)<<std::endl;
    //std::cout<<"Rozmiar zmiennej enum: "<<sizeof(test_zmienna7)<<std::endl;
 
    return 0;
}