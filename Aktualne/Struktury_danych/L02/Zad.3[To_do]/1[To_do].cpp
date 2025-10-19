#include <iostream> 
int n,i=0 ;
int main()
{
    
    std::cout<<"Podaj wartosc liczb n, mniejszej od 100: ";
    std::cin>> n;
    int tablica[n];
    do
    {
        std::cout<<"Element numer "<<i<<" o wartosci: "<<n<<"\nZostal dodany do tablicy!";
        i++;
    }
    while (n<100);
    return 0;
}