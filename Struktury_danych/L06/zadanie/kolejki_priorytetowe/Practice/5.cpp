#include <iostream>
#include <queue>
int main()
{
    std::priority_queue <int> kolejka; 
    kolejka.push(5);
    kolejka.push(10);
    kolejka.push(15);
    kolejka.push(20);
    kolejka.push(25);
    std::cout<<"Rozmiar kolejki to: "<<kolejka.size();
    return 0;
}