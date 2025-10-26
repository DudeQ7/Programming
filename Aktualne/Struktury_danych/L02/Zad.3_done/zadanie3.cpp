#include <iostream> 
int main()
{
    int n;
    std::cout<<"Podaj wartosc liczb n(n mniejsze od 100) "; //legenda by user w trakcie wprowadzania danych, wiedzial jaki zakres spowoduje blad 
    std::cin>> n;
    if((n<=0)||(n>=100)) //walidacja danych
    {
        std::cout<<"Podana liczba jest z nieprawidlowego zakresu!";
        return 1; // zakonczenie programu
    }
    int tablica[100]; // tablica gotowa do przechowywania wszystkich elementow z polecenia
    std::cout<<"Wprowadz n: "<<n<<" liczb: "<<std::endl;
    for(int i=0; i<n; i++) //for do zapisanie danych od usera do tablicy
    {
        std::cout<<"Element ["<<i<<"]:"; 
        std::cin>>tablica[i]; 
    }
    int min1 = tablica[0]; // startowa wartosc dla minimum , ktora bedziemy dalej porownywac
    int max1=tablica[0];
    //rozwiazanie numer 1 , porownanie par liczb:

    for(int i=0; i<n; i++) //for do porownywania czy mamy nowe max lub min
    {
        if(tablica[i]<min1)
        {
            min1 = tablica[i]; //nowe minimum
        }
        if(tablica[i]>max1) // przypadek dla nowego maximum
        {
            max1 = tablica[i];
        }
    }
        std::cout<<"Rozwiazanie numer_1: \n"<<"Max: "<<max1<<"\nMin: "<<min1;
    //rozwiazanie numer 2 porownanie parami:
int min2,max2; 
int start =0; //startowa wartosc
if(n%2 ==0) //sprawdzenie czy n'ka od usera jest parzysta, inaczej nie ma pary
{
    //porownanie pierwszej pary liczb i inicjalizacja min/max
    if(tablica[0]<tablica[1]) 
    {
        min2 = tablica[0]; 
        max2=tablica[1];
    }
    else
    {
        min2=tablica[1];
        max2=tablica[0];
    }
    start =2; //porownalismy pierwsza pare liczb , dlatego dajemy zmiennej start od razu wartosc 2 
}
else //przypadek gdy sa rowne 
{
    min2 = max2=tablica[0];
    start =1 ; // ustawienie startu by przeszedl do kolejnej liczby
}

for(int i=start; i+1<n; i+=2)
{
    int local_min,local_max;
    if(tablica[i]<tablica[i+1]) //jesli aktualny indeks tablicy jest mniejszy od kolejnego indeksu
    {
        local_min = tablica[i];
        local_max = tablica[i+1];
    }
    else
    {
        local_min = tablica[i+1];
        local_max = tablica[i];
    }
    if(local_min<min2)
    {
        min2 = local_min;
    }
    if(local_max>max2)
    {
        max2 = local_max;
    }   
}
std::cout<<"\nRozwiazanie numer_2: \n"<<"Max: "<<max2<<"\nMin: "<<min2;
    return 0;
}