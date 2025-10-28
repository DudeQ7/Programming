#include <iostream>
/*
Zadanie 2
Stwórz tablicę o wymiarach 5x5 wypełnioną zerami.
Wyświetl tablicę.
Uzupełnij automatycznie tablicę wartością 1 po przekątnych (używając pętli) i wyświetl
10001
01010
00100
01010
10001
*/
int main()
{
    int tablica[5][5];
    for(int i=0; i<5;i++)
    {
        for(int j=0; j<5; j++)
        {
            std::cout<<"Przed uzupelnieniem: "<<std::endl;
            std::cout<<"Indeks numero: "<<i<<" to: "<<tablica[i][j]<<std::endl;
        }
    }
    for(int i=0; i <5; i++)
    {
        for(int j=0; j<5; j++)
        {
            std::cout<<"Po uzupelnieniu: "<<std::endl;
            tablica[i][j] = [1
        }
    }
    return 0;
}