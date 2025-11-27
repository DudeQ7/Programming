//#include <iostream>
#include <stack>
#include <string>
/*
Steps:
1.Input od usera[dzialanie matematyczne
2.Sprawdzamy te dzialanie , az nie natrafimy na nawias 
3.Oceniamy wyrazenie i dajemy koncowy wniosek czy jest okej czy nie 
*/
// " == stringi, ' = chary
bool czy_okej(char otw,char zam)
{
    return  (otw =='('&&zam==')') ||
            (otw =='['&&zam==']') ||
            (otw =='{'&&zam=='}');
}
int main()
{
std::string wyrazenie;
std::cout<<"Podaj wyrazenie matematyczne: ";
std::cin >> wyrazenie;
std::stack<char> stosiczek;
bool poprawne = true; //domyslnie zakladamy ze wyrazenie jest poprawne.
for(char c:wyrazenie) //mechanika z zad.4 ,for ktory przechodzi przez wszystkie znaki 
{
    // dajemy nawias otwierajacy na stosiczek
    if((c=='(')||(c=='[')||(c=='{'))
    {
        stosiczek.push(c);
    }
    //sprawdzamy czy jest zamkyjacy
    else if((c==')')||(c==']')||(c=='}'))
    {
        if(stosiczek.empty())
        {
            poprawne = false ; // zostal podany nawias zamykajacy a nie otwierajacy
            break; //przerwanie petli
        }
        char top = stosiczek.top(); //zapisujemy aktualny znak ze szczytu stosu by porownac 
            if(!czy_okej(top,c))
            {
                poprawne = false;
                break ; 
            }
            stosiczek.pop(); //usuwamy aktualny element ktory jest na szczycie stosu
    }
}
//po sprawdzeniu calego wyrazenia stos powinien byc empty
if(!stosiczek.empty())
{
    poprawne = false;
}
if(poprawne)
{
    std::cout<<"Great, nawiasy sa poprawnie sparowane!!!"<<std::endl;
}
else
{
    std::cout<<"Nawiasy nie sa poprawnie sparowane :c"<<std::endl;
}
    return 0;
}