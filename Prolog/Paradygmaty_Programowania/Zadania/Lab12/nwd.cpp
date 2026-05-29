#include <iostream>
int NWD(int a ,int b)
{
    while(a!=b)
    {
        if(a>b)
        {
            a = a - b ;
        }
        else
        {
            b = b - a ;
        }
    }
    return a;
}
int main()
{
    int a,b;
    std::cout<<"Podaj liczbe numer_1: ";
    std::cin>>a;
    std::cout<<"Podaj liczbe numer_2: ";
    std::cin>>b;
    std::cout<<"\nNWD liczb "<<a<<" i "<<b<<" to: "<<NWD(a,b)<<std::endl;
    return 0 ; 
}
