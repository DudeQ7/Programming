#include <iostream>
#include <stack>
int main()
{
    std::stack<char>slowko; 
    std::string u_slowo;
    std::cout<<"Podaj slowo: ";
    std::cin>>u_slowo;
    //for do dania pojedynczych elementow jakie elementy na stos
    for(char c:u_slowo)
    {
        slowko.push(c);        
    }
    std::cout<<"Twoje slowo to : "<<u_slowo<<std::endl;  
    std::cout<<"Odwrocone slowo to: "<<std::endl;
    while(!slowko.empty())
    {
        std::cout<<slowko.top(); //odczytanie elementu ze szczytu stosiku
        slowko.pop(); //usuniecie odczytanego elementu
    }

return 0;
}