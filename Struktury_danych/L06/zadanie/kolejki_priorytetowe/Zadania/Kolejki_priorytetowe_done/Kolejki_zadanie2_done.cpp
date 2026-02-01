#include <iostream>
#include <queue>
/*
Ćwiczenie 2 
Praktyczne użycie metod empty() oraz size(). 
Napisz program, który: 
1. Tworzy pustą kolejkę priorytetową typu int. 
2. Sprawdza, czy kolejka jest pusta i wyświetla odpowiedni komunikat. 
3. Dodaje do kolejki trzy elementy. 
4. Wyświetla liczbę elementów w kolejce. 
5. Usuwa wszystkie elementy w pętli, kontrolując warunek zakończenia za pomocą empty().
*/
int main()
{
    std::priority_queue <int> kolejka;
    if(kolejka.empty()==true)
    {
        std::cout<<"Kolejka jest pusta"<<std::endl;
    }
    kolejka.push(9);
    kolejka.push(6);
    kolejka.push(7);
    std::cout<<"Kolejka ma: "<<kolejka.size()<<" elementy!"<<std::endl;
    while (!kolejka.empty())
    {
        std::cout<<"Usunieto element: "<<kolejka.top()<<std::endl;
        kolejka.pop();
    }
    return 0;
}