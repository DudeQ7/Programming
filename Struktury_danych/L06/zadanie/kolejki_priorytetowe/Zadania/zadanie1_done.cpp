#include <iostream>
#include <queue>
/*
Ćwiczenie 1 
Zapoznanie się z podstawowym interfejsem kolejki priorytetowej. 
Utwórz program w C++, który: 
1. Zadeklaruje kolejkę priorytetową liczb całkowitych (domyślne porządkowanie). 
2. Wstawi do niej pięć dowolnych liczb. 
3. Wyświetli element o najwyższym priorytecie za pomocą top(). 
4. Usunie jeden element z kolejki i ponownie wyświetli aktualny element najwyższego priorytetu
*/
int main()
{
    int pom = 0;
    std::priority_queue <int> kolejka;
    kolejka.push(3);
    kolejka.push(4);
    kolejka.push(5);
    kolejka.push(6);
    kolejka.push(7);
    for(int i=0; i<5; i++)
    {
        pom = kolejka.top();
        if(kolejka.top() > pom)
        {
            pom = kolejka.top();
        }        
    }
std::cout<<"Najwieksza liczba przed usunieciem to: "<<kolejka.top()<<std::endl;
kolejka.pop();       
for(int i=0; i<5; i++)
{
    if(kolejka.top()> pom)
    {
        pom = kolejka.top();
    }
}
    std::cout<<"Najwieksza liczb po usunieciu elementu to: "<<kolejka.top()<<std::endl;

    return 0; 
}