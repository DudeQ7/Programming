#include <iostream>
#include <queue>
int main()
{
    std::priority_queue <int> kolejka;
    if(kolejka.empty()==true)
    {
        std::cout<<"Twoja kolejka jest pusta! ";
    }
    kolejka.push(10);
    kolejka.push(7);
    if(kolejka.empty()==false)
    {
        std::cout<<"\nTwoja kolejka nie jest pusta!"<<std::endl;
        std::cout<<"Liczba na stosie to: "<<kolejka.top();
    }
    return 0; 
}