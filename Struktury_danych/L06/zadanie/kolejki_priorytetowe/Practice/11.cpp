#include <iostream>
#include <list>
int main()
{
    std::list <double> lista;
    unsigned int N;
    double war = 999;
    std::cout<<"N to: ";
    std::cin >>N;
    if(N<=lista.max_size())
    {
        lista.assign(N,war);
        std::cout<<"Zawartosc listy";
        for(double x: lista)
        {
            std::cout<<x<<" ";
        }
    }
    else
    {
        std::cout<<"Lista nie pomiesci taiej ilosci elementow";
    }
    return 0;
}