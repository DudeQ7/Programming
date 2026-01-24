#include <queue>
#include <iostream>
int main()
{
    int tab[5] ={1,2,3,4,5};
    std::priority_queue <int> kolejka(tab, tab+5); //rosnaco 
    std::cout<<kolejka.top(); 
}