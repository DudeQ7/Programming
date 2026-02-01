#include <iostream>
#include <deque>
/*
Ćwiczenie 3 
Praca z iteratorami begin, end, rbegin, rend. 
1. Utwórz kontener deque<int> i wstaw do niego liczby od 1 do 5. 
2. Wyświetl zawartość kontenera: 
a. w kolejności normalnej (iteratory zwykłe), 
b. w kolejności odwrotnej (iteratory odwrotne). 
3. Wyjaśnij różnicę między end() a rend() na podstawie obserwacji działania programu.
*/
int main()
{
    std::deque<int>k1;
    for(int i=1; i<6;i++)
    {
        k1.push_back(i);
    }
    std::cout<<"Zawartosc kontenera: "<<"\nKolejnosc normalna:"<<std::endl;
    for(std::deque<int>::iterator it =k1.begin(); it!=k1.end();it++)
    {
        std::cout<<"Kolejnosc normalna: "<<*it<<std::endl;
    }
    std::cout<<"Zawartosc kontenera: "<<"\nKolejnosc odwrotna:";
    for (std::deque<int>::reverse_iterator it = k1.rbegin(); it != k1.rend();it++)
    {
        std::cout<<"Kolejnosc odwrotna: "<<*it<<std::endl;
    }
    std::cout<<"\nRoznica polega na tym,ze end wskazuje ostatni element, iteruje w przod, podczas gdy \n rend wskazuje przed pierwszy element i iteruje wstecz";
    return 0;
}