#include <iostream>
#include <stack>
int main()
{
    std::stack <int> stosik;
    int u_input;
    //user ma podawac liczbe dopoki nie poda 0, ktory zakonczy ciag
    std::cout<<"Podaj liczbe[0 konczy wprowadzanie]: "<<std::endl; //legenda by user w trakcie wprowadzania danych, wiedzial jaki zakres spowoduje blad 
    do
    { 
        std::cout<<"Podaj liczbe:" ;
        std::cin>>u_input;
        if(u_input!=0) //walidacja przed przekazaniem liczb na stos
        {
            stosik.push(u_input);
        }
    }
    while (u_input!=0);    
    if(stosik.empty()) //sprawdzenie czy przypadkiem stos nie jest pusty 
    {
        std::cout<<"Stos jest pusty!!!"<<std::endl;
    }
    std::cout<<"Na stosie znajduja sie "<<stosik.size()<<" elementy!!!"<<std::endl;
    //sprawdzenie logiki czy liczby w kolejce sa ustawione w dobrym prozadku
    bool grow = true; //domyslnie zakladamy ze kolejka jest ustawiona w porzadku rosnacym
    int last = stosik.top(); // zapisujemy najwyzszy element ze stosu w zmiennej pomocniczej 
    stosik.pop(); //usuwamy ten element ze szczytu
    while(!stosik.empty()) 
    {
        int next = stosik.top();
            if(next>=last) //check , czy wartosc sie odwrocila
            {
                grow = false;
                break; //przerwanie while'a
            }
            last = next;
            stosik.pop(); //usuwamy ten element ze stosu
    }
    if(grow) //grow = true
    {
        std::cout<<"Liczby sa ustawione w porzadku rosnacym!";

    }
    else //grow = false
    {
        std::cout<<"Liczby sa ustawione w porzadku malejacym!";
    }
    return 0;
}