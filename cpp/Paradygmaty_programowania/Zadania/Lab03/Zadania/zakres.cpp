#include <iostream> 
unsigned short malaLiczba = 65534;
int main()
{
    std::cout<<"Wartosc zmiennej malaLiczba: "<<malaLiczba<<std::endl; //65334
    malaLiczba+=1;  //65335 max wartosc dla unsigned short
    std::cout<<"Wartosc zmiennej malaLiczba: "<<malaLiczba<<std::endl;
    malaLiczba+=100; //max + 100  = 65635 , przechodzimy przez zakres modulo 2^16 co daje 99
    std::cout<<"Wartosc zmiennej malaLiczba: "<<malaLiczba<<std::endl;
    malaLiczba=-127; //konwersaj z wartosci ujemnych do usngigned nt jest zdefiniowana jako modulo 2^16: -127 mod 65536 = 65536 - 127 = 65409
    std::cout<<"Wartosc zmiennej malaLiczba: "<<malaLiczba<<std::endl;
    return 0;

}