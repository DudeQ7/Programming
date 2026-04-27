#include <iostream> 
#include <cmath>
int main()
{
    int suma =0;
    double kwadrat =0;
    for(int i =1; i<=20; i++)
    {
        suma+=i;
        kwadrat+= pow(i,i);
        if(i%2==0)
        {
            std::cout<<"Parzysta liczba to: "<<i<<std::endl;
        }
    }
    std::cout<<"\nSuma jest rowna: "<<suma<<std::endl;
    std::cout<<"Suma kwadratow jest rowna: "<<kwadrat<<std::endl;

    return 0;
}