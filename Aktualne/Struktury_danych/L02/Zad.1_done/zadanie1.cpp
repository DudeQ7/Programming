// //1.1
// #include <iostream>
// #include <stack>
// int main()
// {
//     int tablica1[10] ={0,1,2,3,4,5,6,7,8,9};
//     for(int i=0; i<10; i++)
//     {
//         std::cout<<"Element tablicy numer: "<<i<<" to: "<<tablica1[i]<<std::endl;
//     }
//     return 0;
// }

//1.2
// #include <iostream>
// int main()
// {
//     int tablica2[10]={1,2,3,4,5,6,7,8,9};
//     for(int i=0; i<10; i++)
//     {
//          std::cout<<"Element tablicy numer: "<<i<<" to: "<<tablica2[i]<<std::endl;
//     }
//     return 0;
// }

//1.3
// #include <iostream>
// float tablica1[10] ={0,1,2,3,4,5,6,7,8,9}; 
// float tablica2[10]={1,2,3,4,5,6,7,8,9};  // z int'em sa errory
// float tablica3[10];
// int main()
// {
//     for(int i =0; i<10; i++)
//     {
//         if(tablica2[i]!= 0) //walidacja danych 
//         {
//             tablica3[i] = (tablica1[i]/tablica2[i]);

//         }   
//         else
//         {
//             tablica3[i]= 0;
//         }
//         std::cout<<"Element tablicy numer: "<<i<<" to: "<<tablica3[i]<<std::endl;
//     }
//     return 0;
// }

//1.4
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
