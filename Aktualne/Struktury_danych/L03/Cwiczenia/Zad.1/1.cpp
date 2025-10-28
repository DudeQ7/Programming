// Zad.1
// Stwórz tablicę o wymiarach 4x6.
// Wypełnij ją liczbami losowymi od 0 do 9.
// Wyświetl tablicę.
// Oblicz i wyświetl sumę wartości w każdym wierszu.
#include <iostream>
int main()
{
    int suma;
    int tablica[4][6]={
                        {0,1,2,3,4,5},
                        {6,7,8,9,1,2},
                        {7,7,7,7,7,7},
                        {6,6,6,6,6,6}
                    };
    //pierwszy [] = ile rzedow np. 1,
    //                              2
    //drugi [] =ile wierszy 111111
        for(int i=1; i<=4; i++)
        {
            for(int j=1; j<=6;j++)
            {
            //std::cout<<"Suma wierszu numer: "<<i<<" to: "<<tablica[i][i]+tablica[i+1][i+1]<<std::endl;
       //    int suma = tablica[i] +tablica[j];
                suma=tablica[i][j];
            std::cout<<"Indeks "<<i<<" to: "<<tablica[i][j]<<" Suma to: "<<suma<<std::endl;
            
            
            }
           
        }

    return 0;
}