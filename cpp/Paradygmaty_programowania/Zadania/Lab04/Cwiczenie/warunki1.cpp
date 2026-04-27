#include <iostream>
int main()
{
    int u_input =0;
    std::cout<<"Podaj liczbe calkowita: ";
    std::cin>>u_input;
    if(u_input >0)
    {
        std::cout<<"Liczb jest dodatnia";
    }
    else if(u_input ==0)
    {
        std::cout<<"Liczba jest rowna 0 ";
    }
    else
    {
        std::cout<<"Liczba jest ujemna";
    }
    if(u_input %2 ==0)
    {
        std::cout<<"Liczba jest parzysta";
    }
    else
    {
        std::cout<<"Liczba jest nie parzysta";
    }
    
    return 0;
}