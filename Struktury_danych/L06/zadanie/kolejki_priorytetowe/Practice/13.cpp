#include <iostream>
#include <queue>
int main()
{
    std::priority_queue<int>kolejka;
    int tab[5]={1,2,5,4,3};
    for(int i=0; i<5;i++)
    {
        kolejka.push(tab[i]);
    }
    for(int i=0; i<5; i++)
    {
        tab[i]=kolejka.top();
        kolejka.pop();
    }
    std::cout<<tab[0];
    return 0; 
}