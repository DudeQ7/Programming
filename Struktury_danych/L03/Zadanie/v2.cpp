#include <iostream>
#include <cstdlib> //rand
#include <ctime>
#include <stdlib.h> //dla system("cls");
const int rozmiar = 4; //stala z deklaracja rozmiaru naszej tablicy 4 x 4 
void zeruj(int tab[rozmiar][rozmiar]) //funkcja ktora bedzie wykorzystywana do zerowania
{
    for(int i=0; i<rozmiar; i++)
    {
        for(int j=0; j<rozmiar; j++) //podwojnie zagniezdzona by indeksy i i j sie zyzerowaly int tab[i][j]
        {
            tab[i][j]=0; 
        }
    }
}
void wyswielt(int tab[rozmiar][rozmiar])
{
    for(int i=0; i<rozmiar; i++)
    {
        for(int j=0; j<rozmiar; j++)
        {
            std::cout<<tab[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}
void random_fill(int tab[rozmiar][rozmiar])
{
    for(int i=0; i<rozmiar; i++)
    {
        for(int j=0; j<rozmiar; j++)
        {
            tab[i][j] = rand() % 9 +1 ; // zakres 1-8 +1 
        }
    }
}
bool empty(int tab[rozmiar][rozmiar])
{
    for(int i=0; i<rozmiar; i++)
    {
        for(int j=0; j<rozmiar; j++)
        {
            if(tab[i][j]>0)
            {
                return false;
            }
        }
    }
    return true;
}

void przemieszczenie(int tab[rozmiar][rozmiar])
{
    int wartosci[rozmiar * rozmiar]; //tablica 4 x4 
    int ile_razy=0; // wartosc > 0 
    for(int i=0; i<rozmiar; i++)
    {
        for(int j=0; j<rozmiar; j++)
        {
            if(tab[i][j]>0)
            {
                wartosci[ile_razy]=tab[i][j]; 
                ile_razy++;
            }
        }
    }
    //skopiowana funkcja z zerowania 
     for(int i=0; i<rozmiar; i++)
    {
        for(int j=0; j<rozmiar; j++) //podwojnie zagniezdzona by indeksy i i j sie zyzerowaly int tab[i][j]
        {
            tab[i][j]=0; 
        }
    }
    //losowe rozstawienie liczb spowrotem
    for(int x=0; x<ile_razy; x++)
    {
        int i,j; //deklaracja zmiennych by moc je wykorzystac potem
        do
        {
            i = rand()%rozmiar;
            j = rand()%rozmiar;
        }
        while(tab[i][j]!=0);
        tab[i][j]=wartosci[x]; // przypisanie wartosci
    }
}
void wojna(int t1[rozmiar][rozmiar],int t2[rozmiar][rozmiar],int &punkty1,int &punkty2,int &runda) //przekazywanie wartosci przez referencje by zapisaly sie wartosci 
{
    std::cout<<"Punkty gracza numer1: "<<punkty1<<std::endl;
    std::cout<<"Punkty gracza numer2: "<<punkty2<<std::endl;
        for(int x=0; x<rozmiar; x++)
        {
            for(int y=0; y<rozmiar; y++)
            {
                if(t1[x][y]> t2[x][y])
                {
                    t2[x][y] = 0;
                    t1[x][y] ++;
                    punkty1 ++;
                }
                else if(t1[x][y]<t2[x][y])
                {
                    t1[x][y]=0;
                    t2[x][y]++;
                    punkty2++;
                }
                else
                {
                    t2[x][y]=0;
                    t1[x][y]=0;
                }
            }
        }
        //przemieszczenie dla wartosci > 0 
        przemieszczenie(t1);
        przemieszczenie(t2);
        std::cout<<"\nWynik:";
        std::cout<<"\nPunkty gracza numer1: "<<punkty1<<std::endl;
        std::cout<<"Punkty gracza numer2: "<<punkty2<<std::endl;
        std::cout<<"Tablica numer1: \n"; wyswielt(t1);
        std::cout<<"Tablica numer2: \n"; wyswielt(t2); 
        runda++;


}
int main()
{
    //test
    srand(time(0));
    int t1[rozmiar][rozmiar]={0}, 
    t2[rozmiar][rozmiar]={0},u_input,punkty1=0,punkty2=0,runda=0; //deklaracja tablic , zerowwanie tablic by pierwsze wyswietl sie nie krzaczylo 
    
    do
    {
        std::cout<<"\n\nMenu: "<<"\n1.Wezuruj obie tablice"<<"\n2.Wyswietl obiet tablice"<<"\n3.Wypelnij obie tablice losowymi liczbami"<<"\n4.Wojna(1 runda)"<<"\n5.Wyswielt aktualny wynik i wygrywajacego"<<"\n0.Wyjscie"<<std::endl;
        std::cout<<"Co chcesz zrobic:(0 przerywa ): ";
        std::cin>>u_input;
        switch(u_input)
        {
            case 1:
            std::cout<<"T1(przed zerowaniem): \n";
            wyswielt(t1);
            std::cout<<"T2(przed zerowaniem): \n";
            wyswielt(t2);
            zeruj(t1);
            zeruj(t2);
            std::cout<<"\nT1(po zerowaniu): \n";
            wyswielt(t1);
            std::cout<<"T2(po zerowaniu): \n";
            wyswielt(t2);
            break;

            case 2:
            std::cout<<"Tablica numer1: \n";
            wyswielt(t1);
            std::cout<<"Tablica numer2: \n";
            wyswielt(t2);
            break;

            case 3:
            std::cout<<"Przed wypelnieniem T1: \n";
            wyswielt(t1);
            std::cout<<"Przed wypelnieniem T2: \n";
            wyswielt(t2);
            random_fill(t1);
            random_fill(t2);
            std::cout<<"\nPo wypelnieniu T1: \n";
            wyswielt(t1);
            std::cout<<"Po wypelnieniu T2: \n";
            wyswielt(t2);
            break;
            case 4:
               // wojna(t1,t2,punkty1,punkty2,runda); template
                std::cout<<"Runda numer: "<<runda<<std::endl;
                if(empty(t1)||empty(t2))
                {
                    std::cout<<"Koniec gry!"<<std::endl;
                    std::cout<<"Wynik koncowy: "<<std::endl;
                    std::cout<<"Gracz nr1 zdobyl: "<<punkty1<<" punktow"<<std::endl;
                    std::cout<<"Gracz nr2 zdobyl: "<<punkty2<<" punktow"<<std::endl;
                    if(punkty1>punkty2)
                    {
                        std::cout<<"Wygral gracz nr:1!"<<"\nGratulacje!!!!";
                    }
                    else if(punkty2>punkty1)
                    {
                        std::cout<<"Wygral gracz nr:2!"<<"\nGratulacje!!!!";
                    }
                    else
                    {
                        std::cout<<"Remis!";
                    }

                }
                else
                {
                    wojna(t1,t2,punkty1,punkty2,runda);
                }
            break;
            case 5: 
            system("cls"); //logika by bylo latwiej zobaczyc aktualne punkty
            std::cout<<"Aktualny wynik dla rundy numer: "<<runda<<"\n";
            std::cout<<"Gracz numer1: "<<punkty1<<std::endl;
            std::cout<<"Gracz numer2: "<<punkty2<<std::endl;
            if(punkty1>punkty2)
            {
                std::cout<<"Aktualnie wygrywa gracz1!";
            }
            else if(punkty2>punkty1)
            {
                std::cout<<"Aktualnie wygrywa gracz2!";
            }
            else
            {
                std::cout<<"Aktualnie jest remis!";
            }
            break;
            case 0:
            std::cout << "Dziekuje za gre! \nDo zobaczenia.";
            break;
            default:
            std::cout<<"Blad wejscia\n Koniec Gry";
            break;
        }
    
        
    }
    while(u_input!=0);
    return 0;
}