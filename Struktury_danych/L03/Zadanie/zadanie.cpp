#include <iostream>
#include <cstdlib>
#include <ctime> //potrzebne do pauzy
const int size = 4; 
void zeruj(int tab[size][size]) //podpunkt 1
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            tab[i][j] = 0;
        }
    }
}

void wyswielt(int tab[size][size]) //podpunkt 2
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            std::cout<<tab[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}
void random_wypelnij(int tab[size][size]) //podpunkt 3 
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            tab[i][j] = rand() % 9 + 1 ;
        }
    }
}
bool czy_pusta(int tab[size][size])
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(tab[i][j]>0)
            {
                return false;
            }
        }
    }
    return true;
}
void wojna(int t1[size][size],int t2[size][size],int &punkty1,int &punkty2,int &runda)
{
    std::cout<<"Runda: "<<runda << " : "<<std::endl;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(t1[i][j]>t2[i][j])
            {
                t2[i][j]=0;
                t1[i][j]++;
                punkty1++; // p= 0  p -
            }
            else if(t1[i][j] < t2[i][j])
            {
                t1[i][j]=0;
                t2[i][j]++;
                punkty2++;
            }
            else
            {
                t1[i][j] =0;
                t2[i][j] =0;
            }
        }
    }
    std::cout<<"Punkty[Gracz_1]: "<<punkty1<<"\nPunkty[Gracz_2]: "<<punkty2<<std::endl;
    std::cout<<"Tablica_1: "<<std::endl;
    wyswielt(t1);
    std::cout<<"Tablica_2: "<<std::endl;
    wyswielt(t2);
    runda++; 
    
}
int main()
{
    srand(time(0));
    int t1[size][size],t2[size][size];
    int punkty1 =0,punkty2=0,runda=1,wybor;
    std::cout<<"Wojna[tablice 4x4]: "<<std::endl;
    while(true)
    {
        std::cout<<"Menu: "<<std::endl;
        std::cout<<"1.Wezuruj obie tablice"<<std::endl;
        std::cout<<"2.Wyswietl obiet tablice"<<std::endl;
        std::cout<<"3.Wypelnij obie tablice losowymi liczbami"<<std::endl;
        std::cout<<"4.Wojna(1 runda)"<<std::endl;
        std::cout<<"0.Wyjscie"<<std::endl;
        std::cout<<"Twoj wybor: ";
        std::cin >>wybor;
    
    switch(wybor)
    {
        case 1:
            std::cout<<"Zerowanie tablic: "<<std::endl;
            zeruj(t1);
            zeruj(t2);
            punkty1 =0;
            punkty2 =0;
            runda =1;
            std::cout<<"Tablice wyzerowane";
            break;
        case 2:
            std::cout<<"Wyswietlanie tablic: ";
            std::cout<<"Tablica 1: "<<std::endl;
            wyswielt(t1);
            std::cout<<"Tablica 2: "<<std::endl;
            wyswielt(t2);
            break;
        case 3:
            std::cout<<"Wypelnianie tablic losowymi liczbami: ";
            random_wypelnij(t1);
            random_wypelnij(t2);
            std::cout<<"Tablica numer1: "<<std::endl;
            wyswielt(t1);
            std::cout<<"Tablica numer2: "<<std::endl;
            wyswielt(t2);
            break;
      case 4:  
                std::cout<<"Wojna!"<<std::endl;  
                if(czy_pusta(t1) || czy_pusta(t2))  
                {  
                    std::cout<<"Koniec gry!"<<std::endl;  
                    std::cout<<"Wynik koncowy: "<<std::endl;  
                    std::cout<<"Gracz nr1: "<<punkty1<<" punktow"<<std::endl;  
                    std::cout<<"Gracz nr2: "<<punkty2<<" punktow"<<std::endl;  
                      
                    if(punkty1>punkty2)  
                    {  
                        std::cout<<"Wygral gracz numer 1!!!"<<std::endl;  
                    }  
                    else if(punkty2>punkty1)  
                    {  
                        std::cout<<"Wygral gracz numer 2!!!"<<std::endl;  
                    }  
                    else   
                    {  
                        std::cout<<"Remis!"<<std::endl;  
                    }  
                }  
                else
                {  
                    wojna(t1,t2,punkty1,punkty2,runda);  
                }  
                break  ;
        case 0:
            std::cout<<"Do zobaczenia!";
            return 0;
        default:
            std::cout<<"Zla opcja, wybierz inna!";
            break;
        }
    }
    return 0;
}