#include <iostream>
#include <queue>
#include <vector>
/*
Ćwiczenie 3 
Zastosowanie własnego kryterium porządkowania. 
Zadeklaruj kolejkę priorytetową, w której: 
1. Element o najmniejszej wartości ma najwyższy priorytet. 
2. Wstaw do niej co najmniej sześć liczb całkowitych. 
3. Wyświetl wszystkie elementy w kolejności ich usuwania z kolejki. 
Wskazówka: Zastosuj greater<int> jako trzeci parametr szablonu. 
*/
int main()
{

std::priority_queue<int, std::vector<int>, std::greater<int>> kolejka; 
    kolejka.push(1);
    kolejka.push(2);
    kolejka.push(3);
    kolejka.push(4);
    kolejka.push(5);
    kolejka.push(6);
    kolejka.push(7);
    kolejka.push(8);
    kolejka.push(9);
    kolejka.push(10);
    while(!kolejka.empty())
    {
        std::cout<<"Element o wartosci: "<<kolejka.top()<<" zostal usuniety"<<std::endl;
        kolejka.pop();
    }
    return 0;
}