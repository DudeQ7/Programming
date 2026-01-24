#include <iostream>
#include <queue>
int main()
{
    std::priority_queue <int> kolejka;
    kolejka.push(10);
    kolejka.push(40);
    std::cout<<kolejka.top();
    return 0; 
}