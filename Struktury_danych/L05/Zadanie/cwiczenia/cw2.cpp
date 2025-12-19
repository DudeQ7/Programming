#include <iostream>
#include <queue>
std::queue <std::string> kolejka_0;
int main()
{
    std::string zdanie;
    int start_liczba;
    for(int i =0; i<5; i++)
    {
    std::cout<<"Podaj zdanie nr: "<<i<<": ";
    std::cin >> zdanie;
    kolejka_0.push(zdanie);
    }
    start_liczba = kolejka_0.size();
    for(int j=0; j<5; j++)
    {
        if(!kolejka_0.empty())
        {
            std::cout<<"Aktualne zdanie na szczycie kolejki to: "<<kolejka_0.front()<<std::endl;
            std::cout<<"Zdanie nr: "<<j<<" zostalo usuniete!"<<std::endl;
            kolejka_0.pop();
        }
        else
        {
            std::cout<<"Kolejka jest pusta!!!";
        }
        
    }
    std::cout<<"Finalnie bylo: "<<start_liczba<<" elementow!!!";
    return 0;
}