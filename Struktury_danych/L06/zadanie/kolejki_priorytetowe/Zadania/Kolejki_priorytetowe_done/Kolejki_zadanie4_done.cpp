#include <iostream>
#include <string>
#include <queue>
#include <vector>
/*
Ćwiczenie 4 
Praca ze złożonymi danymi. 
1. Zdefiniuj strukturę Zadanie, zawierającą: 
a. nazwę zadania (string), 
b. priorytet (int). 
2. Utwórz kolejkę priorytetową przechowującą obiekty typu Zadanie, uporządkowaną malejąco 
według priorytetu. 
3. Dodaj kilka zadań o różnych priorytetach. 
4. Wyświetl zadania w kolejności ich realizacji.
*/
struct Zadanie
    {
        std::string nazwa_zadania;
        int priorytet;
        //// Operator porównania - większy priorytet = ważniejsze zgłoszenie
        bool operator<(const Zadanie& other) const
        {
             return priorytet < other.priorytet;
        }
    };
int main()
{
    std::priority_queue<Zadanie> kolejka;
    Zadanie z1;
    z1.nazwa_zadania ="Kanapka";
    z1.priorytet = 1 ;
    kolejka.push(z1);
    Zadanie z2;
    z2.nazwa_zadania = "Praca domowa";
    z2.priorytet = 5;
    kolejka.push(z2);
    Zadanie z3;
    z3.nazwa_zadania = "Segregowanie rzeczy";
    z3.priorytet = 3;
    kolejka.push(z3);
    while(!kolejka.empty())
    {
        Zadanie z = kolejka.top();
        std::cout<<"Zadanie: "<<z.nazwa_zadania<<" ,priorytet: "<<z.priorytet<<std::endl;
        kolejka.pop();
    }
 return 0; 
}