#include <iostream>
int main()
{
    int tablica4[30];
    unsigned int a,b; //user input
    std::cout <<"Podaj wartosc a[dodatnia liczba]: ";
    std::cin >> a;
    std::cout<<"Podaj wartosc b[dodatnia liczba]: ";
    std::cin >> b;
    //tablica4[0]=a;
    //potencjalny blad
    for (int i=0; i<30; i++) //petla for odpowiadajaca za logike naszego programu
    {   
        if(i==0)
        {
            tablica4[i]=a; //pierwszy indeks = a 
        }
        else
        { 
            tablica4[i] = tablica4[i-1] + b; //indeks dla danej iteracji = to poprzedni indeks + zmienna b
        }
    }
    for(int i =0; i<30; i++) //petla for odpowiadajaca za wyswietlanie wszystkich tablic w jednym wierszu 
    {
        std::cout<<tablica4[i]<<" ";
    }
    
return 0;
}
