#include <iostream>
#include <queue>
int main()
{
std::queue <int> kolejka0;
int start_liczba = 2;
for(int i=0; i<5; i++)
{
    std::cout<<"Element nr: "<<i<<" to: "<<start_liczba<<std::endl;
    kolejka0.push(start_liczba);
    if(i==0)
    {
        std::cout<<"Pierwszy element to: "<<start_liczba<<std::endl;
    }
    else if(i==4)
    {
        std::cout<<"Ostatni element to: "<<start_liczba<<std::endl;
    }
    start_liczba++;
}
std::cout<<"Pora na usuniecie elementow!!!"<<std::endl;
for(int j=0; j<5; j++)
{
    std::cout<<"Aktualna wartosc to: "<<kolejka0.front()<<std::endl;
    std::cout<<"Element nr: "<<j<<" Zostal usuniety!"<<std::endl;
    kolejka0.pop();
}
return 0;
}
