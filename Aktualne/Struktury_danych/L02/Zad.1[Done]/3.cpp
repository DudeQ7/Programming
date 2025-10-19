#include <iostream>
float tablica1[10] ={0,1,2,3,4,5,6,7,8,9}; //mozliwy blad ze wzgledu na typ danych int a nie flota 
float tablica2[10]={1,2,3,4,5,6,7,8,9}; //^
float tablica3[10];
int main()
{
    for(int i =0; i<10; i++)
    {
        tablica3[i] = (tablica1[i]/tablica2[i]);
        std::cout<<"Element tablicy numer: "<<i<<" to: "<<tablica3[i]<<std::endl;

    }
    
    return 0;
}