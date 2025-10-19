#include <iostream>
#include <stack>
std::stack<std::string>slowko; //error
std::string u_slowo;
int main()
{
    std::cout<<"Podaj slowo: ";
    std::cin>>u_slowo;
    slowko.push(u_slowo); // danie slowa uzytkownika na szczyt stosu
    std::cout<<"Twoje slowo to: "<<u_slowo<<std::endl;
    std::cout<<"Aktualny element, ktory jest na szczycie stosu to: "<<slowko.top()<<std::endl;
    return 0;
}