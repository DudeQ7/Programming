#include <iostream>
#include <stack>
int main()
{
    std::stack <int> stosik;
    int u_input,poprzedni_top,aktualny_top;
    do
    {   
        poprzedni_top=u_input;
        std::cout<<"Podaj liczbe: "; //user ma podawac liczbe dopoki nie poda 0, ktory zakonczy ciag
        std::cin>>u_input;
        if(u_input!=0)
        {

        aktualny_top=u_input;
        stosik.push(u_input); //umieszczenie liczby na stosie stosu
        }
        else
        {
            std::cout<<"error: ";
        }
        if(aktualny_top>poprzedni_top)
        {
            std::cout<<"Liczby na stosie sa ustawione w kolejnosci rosnacej";
        }
    } 
    while (u_input!=0);    
    std::cout<<"Aktualna liczba na szczycie stosu to: "<<stosik.top()<<std::endl;
    std::cout<<"Na stosie znajduje sie "<<stosik.size()<<" liczb."<<std::endl;
    return 0;
}