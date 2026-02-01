#include <iostream>
#include <deque>
/*
Ćwiczenie 5 
Praktyczne zastosowanie deque 
Zaimplementuj prostą symulację kolejki dwustronnej: 
1. Program umożliwia: 
a. dodanie elementu na początek, 
b. dodanie elementu na koniec, 
c. usunięcie elementu z początku, 
d. usunięcie elementu z końca, 
e. wyświetlenie całej zawartości kolejki. 
2. Program działa w pętli sterowanej menu tekstowym. 
3. Przed każdą operacją usuwania należy sprawdzić, czy kontener nie jest pusty (empty()). 
*/
int main()
{
    std::deque<int> k1;
    int u_input =-1;
    while(u_input!=0)
    {
        std::cout<<"\n\nMenu:"<<"\n1.Dodanie elementu na poczatek"<<"\n2.Dodanie elementu na koniec"<<"\n3.Usuniecie elemenetu z poczatku"<<"\n4.Usuniecie elementu z konca"<<"\n5.Wyswietlenie calej zawartosci kolejki"<<"\n0.Zakonczenie dzialania programu";
        std::cout<<"\nTwoj wybor: ";
        std::cin>>u_input;
        switch (u_input)
        {
        case 1:
        {
            int wartosc;
            std::cout<<"Podaj wartosc do dodania na poczatek: ";
            std::cin>>wartosc;
            k1.push_front(wartosc);
            std::cout<<"Dodano: "<<wartosc<<" na poczatek!"<<std::endl;
            break;
        }
        case 2:
        {
            int wartosc;
            std::cout<<"POdaj wartosc do dodania na koniec: ";
            std::cin>>wartosc;
            k1.push_back(wartosc);
            std::cout<<"Dodano: "<<wartosc<<" na koniec! "<<std::endl; 
            break;
        }   
        case 3:
        {
            if(!k1.empty())
            {
                std::cout<<"Usunieto element z poczatku: "<<k1.front()<<std::endl;
                k1.pop_front();
            }
            else
            {
                std::cout<<"Struktura jest pusta!";
            }
            break;
        }
        case 4:
        {
            if(!k1.empty())
            {
                std::cout<<"Usunieto element z konca: "<<k1.back()<<std::endl;
                k1.pop_back();
            }
            else
            {
                std::cout<<"Struktura jest pusta!";
            }
            break;
        }
        case 5:
        {
            if(k1.empty())
            {
                std::cout<<"Struktura jest pusta!";

            }
            else
            {
                std::cout<<"Zawartosc kolejki: ";
                for(int i=0; i<k1.size(); i++)
                {
                    std::cout<<k1.at(i)<<" ";
                }
                std::cout<<std::endl;
            }
            break;   
        }
        case 0:
        {
            std::cout<<"Zakonczono dzialanie programu!!!";
            break;
        }
        default:
            std::cout<<"Podales liczbe spoza zakresu";
            break;
        }
    }
    return 0;
}