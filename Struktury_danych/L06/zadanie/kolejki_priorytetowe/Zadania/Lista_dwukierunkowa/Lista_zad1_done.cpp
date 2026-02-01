#include <iostream>
#include <deque>
/*
Zapoznanie się z kontenerem deque i jego podstawowymi metodami. 
Napisz program w C++, który: 
1. Utworzy pusty kontener deque<int>. 
2. Doda trzy elementy na koniec kontenera (push_back). 
3. Doda jeden element na początek kontenera (push_front). 
4. Wyświetli pierwszy i ostatni element listy (front, back). 
5. Wyświetli aktualny rozmiar kontenera (size)
*/
int main()
{
    std::deque <int> k1;
    k1.push_back(5);
    k1.push_back(6);
    k1.push_back(7);
    k1.push_front(3);
    std::cout<<"Pierwszy element listy: "<<k1.front()<<std::endl;
    std::cout<<"Ostatni element listy: "<<k1.back()<<std::endl;
    std::cout<<"Aktualny rozmiar kontenera: "<<k1.size()<<std::endl;
    return 0;
}