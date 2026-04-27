#include <iostream> 
int main()
{
    int wiek=0,plec =0;
    std::cout<<"Podaj wiek uzytkownika: ";
    std::cin >>wiek;
    std::cout<<"\nWybierz cyfre dla plci, chlopiec =1, dziewczynka = 0";
    std::cin>>plec;
    if(wiek>18&&plec==1)
    {
        std::cout<<"Dorosly chlopiec"<<std::endl;
    }
    else if(wiek >18 && plec==0)
    {
        std::cout<<"Dorosla dziewczynka"<<std::endl;
    }
    else if(wiek<18 && plec ==0)
    {
        std::cout<<"Chlopiec dziecko";
    }
    else 
    {
        std::cout<<"Dziewczynka dziecko";
    }
    return 0; 
}