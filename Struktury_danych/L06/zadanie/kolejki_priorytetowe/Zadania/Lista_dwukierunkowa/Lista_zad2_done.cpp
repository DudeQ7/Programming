#include <iostream>
#include <deque>
/*
Ćwiczenie 2 
Zastosowanie metody at() oraz zrozumienie kontroli zakresu. 
1. Utwórz kontener deque<int> o rozmiarze 10. 
2. Wypełnij go wartościami od 0 do 9. 
3. Wyświetl wszystkie elementy, korzystając z metody at(). 
4. Spróbuj odwołać się do elementu spoza zakresu i obsłuż wyjątek out_of_range.
*/

int main()
{
    std::deque <int> k1;
//max_size 
    for (int i = 0; i < 10; i++)
    {
        k1.push_back(i);
        std::cout<<"Element petli: "<<i<<" to element o wartosci: "<<k1.at(i)<<std::endl;
    }
    try
    {
        std::cout<<"Wyjatek out of range: "<<k1.at(100);
    }
    catch(const std::out_of_range& e)
    {
       std::cout<<"\nBlad: "<<e.what()<<std::endl;
    }

    return 0;
}