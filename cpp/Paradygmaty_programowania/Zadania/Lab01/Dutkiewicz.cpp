#include <iostream>
//podprogram
double obliczCene(int ilosc,double cena_jednostkowa)
{
    return ilosc * cena_jednostkowa; //instrukcja przypisywania i wyrazenie zlozone
}
//procedura 
void sayhi()
{
    std::cout<<"----Automat z napojami----"<<std::endl;
}
int main()
{
    //Sekwencja:
    sayhi( );
    int wybor=0;
    int ilosc = 0;
    double cena = 1.50;
    std::cout<<"Dostepne automaty: "<<std::endl;
    //iteracja 
    for(int i=1; i<=5; i++)
    {
        std::cout<<i<<std::endl;
    }
    ///instrukcja warunkowa i wyprowadzania danych 
    std::cout<<"Co wybierasz cola(0) czy pepsi(1): ";
    std::cin>>wybor;
    //wybor instrukcja warunkowa/zlozona
    if(wybor ==0 ||wybor ==1)
    {
        std::cout<<"Ile sztuk chcesz kupic?  ";
        std::cin>>ilosc;
        //podprogram
        double doZaplaty = obliczCene(ilosc,cena);
    //instruckaj warunkowa zlozona
    if(wybor==0)
    {
        std::cout<<"Wybrales cole!";
    }
    else if(wybor==1)
    {
        std::cout<<"wybrales pepsi!";
    }
    else
    {
        std::cout<<"Podales liczbe spoza zakresu";
    }
    std::cout<<"\nDo zaplaty: "<<doZaplaty<<" zl"<<std::endl;
    }
    else
    {//instrukcja wyboru (alternatywa dla blednego inputu)
        std::cout<<"Blad Podales liczbe spoza zakresu"<<std::endl;
    }
    return 0; //koniec sekwencji w mainie
}