#include <iostream>
#include <stdint.h>
#include <typeinfo>
/*
Uwzględnij co najmniej: 
short, unsigned short, int, unsigned int, long, long long, float, double, long double. 
Porównaj wyniki na różnych kompilatorach lub systemach. Kiedy wyniki są inne ?
*/
int moja_zmienna=0;
int main()
{
    std::cout<<"Nazwa typu: "<<typeid(moja_zmienna).name()<<std::endl;
    std::cout<<"Rozmiar w bajtach typu: "<<std::endl;
    std::cout<<"Czy typ jest ze znakiem:"<<std::endl;   
    std::cout<<"Wartosc minimalna typu: "<<std::endl;      
    std::cout<<"Wartosc maksymalna typu:"<<std::endl;         
    return 0;
}