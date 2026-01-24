#include <iostream>
#include <queue>
int main()
{
    std::priority_queue <int> kolejka;
    kolejka.push(10);
    kolejka.push(25);
    kolejka.push(50);
    kolejka.pop();
    std::cout<<kolejka.top();
    return 0;
}