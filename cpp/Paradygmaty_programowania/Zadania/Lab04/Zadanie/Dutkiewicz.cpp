#include <iostream>
#include <list>
#include <stdlib.h>
#include <algorithm>
int main()
{
    int choice=0,n = 0;
    std::cout <<"Ile liczb chcesz wprowadzic: ";
    std::cin>>n;
    if(n<=0)
    {
        std::cout<<"Liczbe elementow musi byc wieksza od 0!!!";
        return 0;
    }
    int *tablica = new int[n];
    std::list<int> lista;
    for(int i=0; i<n; i++)
        {
            std::cout<<"Podaj liczbe["<<i+1<<"/"<<n<<"]: ";
            std::cin>> tablica[i];
            lista.push_back(tablica[i]);
        }
    do
    {
        std::cout<<"\nMenu: "<<"\n1.Suma i srednia"<<"\n2.Min i Max"<<"\n3.Liczby dodatnie ujemne,parzyste i nie parzyste"<<"\n4.Wyszukanie konkretnej wartosci"<<"\n5.Policzenie liczby elementow spelniajacych dany warunek[submenu]"<<"\n6.Posortowanie danych"<<"\n7.Odwrocenie kolejnosci elementow"<<"\n0.Koniec dzialania programu"<<"\nTwoj wybor: ";
        std::cin>>choice;
        
        switch (choice)
        {
        case 1:
        {
            //suma i srednia
            //suma
            double suma=0;
            for(int j=0; j<n; j++)
            {
                std::cout<<"Liczby: "<<tablica[j]<<std::endl;
                suma+=tablica[j];
            }
            double srednia= suma / n;
            std::system("cls");
            std::cout<<"\nSuma to: "<<suma<<std::endl;
            std::cout<<"Srednia to: "<<srednia<<std::endl;
            std::system("pause");
            break;
        }   
        case 2:
        {
            double max = tablica[0],min =tablica[0];
            for(int i =1; i<n;i++)
            {
                if(tablica[i]>max)
                {
                    max = tablica[i];
                }
                if(tablica[i]<min)
                {
                    min = tablica[i];
                }
            }
            std::system("cls");
            std::cout<<"Wartosc maksimum: "<<max<<std::endl;
            std::cout<<"Wartosc minimum: "<<min<<std::endl;
            std::system("pause");
            break;
        }   
        case 3:
        {
            system("cls");
            std::cout<<"Liczby dodatnie: "<<std::endl;
            for(int i=0; i<n; i++)
            {
                if(tablica[i]>0)
                {
                    std::cout<<tablica[i]<<" ";
                }
            }
            std::cout<<"\nLiczby ujemne: "<<std::endl;
            for(int i=0; i<n; i++)
            {
                if(tablica[i]<0)
                {
                    std::cout<<tablica[i]<<" ";
                }
            }
            std::cout<<"\nLiczby parzyste: "<<std::endl;
            for(int i=0; i<n; i++)
            {
                if(tablica[i]%2==0)
                {
                    std::cout<<tablica[i]<<" ";
                }
            }
            std::cout<<"\nLiczby nieparzyste: "<<std::endl;
            for(int i=0; i<n; i++)
            {
                if(tablica[i]%2!=0)
                {
                    std::cout<<tablica[i]<<" ";
                }
            }
            std::cout<<"\n";
            system("pause");
            break;
        }   
        case 4:
        {
            int liczba=0,ilosc_wystapien=0;
            std::cout<<"Podaj liczbe,ktora chcesz wyszukac: ";
            std::cin>>liczba;
            std::system("cls");
            for(int i=0; i<n; i++)
            {
                if(tablica[i]==liczba)
                {
                    ilosc_wystapien++;
                }
            }
            if(ilosc_wystapien>0)
            {
                std::cout<<liczba<<" wystepuje: "<<ilosc_wystapien<<" razy!"<<std::endl;
            }
            else
            {
                std::cout<<liczba<<" nie wystepuje ani razu"<<std::endl;
            }
            std::system("pause");
            break;
        }   
        case 5:
        {   
            int sub_menu =0;
            std::cout<<"Submenu: "<<"\n1.Mniejsze od"<<"\n2.Wieksze od"<<"\n3.Rowne"<<"\n4.Z zakresu od do "<<"\n5.Spoza zakresu od do "<<"\n6.Rozne od"<<"\n7.Przerwij dzialanie programu"<<"\nTwoj wybor: ";
            std::cin>>sub_menu;
            switch (sub_menu)
            {
                case 1:
                {
                system("cls");
                int wew_wybor=0,licznik=0;
                std::cout<<"Mniejsze od: ";
                std::cin>>wew_wybor;
                system("cls");
                 for(int i=0; i<n; i++)
                {
                    if(tablica[i]<wew_wybor)
                    {
                        licznik++;
                    }
                }
                std::cout<<"liczba elementow mniejszych od: "<<wew_wybor<<" to: "<<licznik<<std::endl;
                system("pause");
                break;
                }
                case 2:
                {
                system("cls");
                int wew_wybor=0,licznik=0;
                std::cout<<"Wieksze od: ";
                std::cin>>wew_wybor;
                system("cls");
                 for(int i=0; i<n; i++)
                {
                    if(tablica[i]>wew_wybor)
                    {
                        licznik++;
                    }
                }
                std::cout<<"Liczba elementow wiekszych od: "<<wew_wybor<<" to: "<<licznik<<std::endl;
                system("pause");
                break;
                }
                case 3:
                {
                system("cls");
                 int wew_wybor=0,powtorzenia=0;
                std::cout<<"Rowne od: ";
                std::cin>>wew_wybor;
                system("cls");
                 for(int i=0; i<n; i++)
                {
                    if(tablica[i]==wew_wybor)
                    {
                        powtorzenia++;
                    }
                }
                std::cout<<"Liczba elementow rownych: "<<wew_wybor<<" to: "<<powtorzenia<<std::endl;
                system("pause");
                break;
                }
                case 4:
                {
                int dolny_zakres=0,gorny_zakres=0,licznik=0;
                system("cls");
                std::cout<<"Podaj liczbe z dolnego zakresu: ";
                std::cin>>dolny_zakres;
                std::cout<<"Podaj liczbe z gornego zakresu: ";
                std::cin>>gorny_zakres;
                system("cls");
                for(int i=0; i<n; i++)
                {
                    if((tablica[i]>=dolny_zakres)&&(tablica[i]<=gorny_zakres))
                    {
                        licznik++;
                    }
                }
                std::cout<<"Ilosc liczba, ktora zawiera sie w zakresie od: "<<dolny_zakres<<" do: "<<gorny_zakres<<" to: "<<licznik<<std::endl;
                system("pause");
                break;
                }
                case 5:
                {
                system("cls");
                int dol=0,gora=0,powtorzenia=0;
                std::cout<<"Podaj wartosc dolnego zakresu: ";
                std::cin>>dol;
                std::cout<<"Podaj wartosc gornego zakresu: ";
                std::cin>>gora;
                system("cls");
                for(int i=0; i<n; i++)
                {
                    if(tablica[i]<dol || tablica[i]>gora)
                    {
                        powtorzenia++;
                    }
                }
                std::cout<<"Ilosc liczb spoza zakresu: "<<dol<<" do: "<<gora<<" to: "<<powtorzenia<<std::endl;
                system("pause");
                break;
                }
                case 6:
                {
                    system("cls");
                    int rozny=0,wystapienia=0;
                    std::cout<<"Rozne od: ";
                    std::cin>>rozny;
                    system("cls");
                    for(int i=0; i<n; i++)
                    {
                        if(tablica[i]!=rozny)
                        {
                            wystapienia++;
                        }
                    }
                    std::cout<<"Liczba elementow roznych od: "<<rozny<<" to: "<<wystapienia<<std::endl;
                    system("pause");
                break;
                }
                case 7:
                {
                std::cout<<"Przerwano dzialanie programu!!!!";
                break;
                }
            default:
            {
                system("cls");
                std::cout<<"Podales liczbe spoza zakresu!";
                break;
            }
            }
            //policzenie liczby elementów spełniających wybrany warunek
            //mniejsze od ,wieksze od , rowne , z zakresu od do, spoza zakresu od do ,
            //rozne od 
            break;
        }   
        case 6:
        {
            int wybor_sortowania=0;
            std::cout<<"Czy chcesz sortowanie Rosnace(1) czy malejace(2): ";
            std::cin>>wybor_sortowania;
            if(wybor_sortowania==1)
            {
                std::sort(tablica,tablica+n);
            }
            else if(wybor_sortowania==2)
            {
                std::sort(tablica,tablica+n,std::greater<int>());
            }
            else
            {
                std::cout<<"Wybrales liczbe spoza zakresu!!!!";
                break;
            }
            system("cls");
            for(int i=0; i<n; i++)
            {
                std::cout<<"Posortowano: "<<tablica[i]<<std::endl;
            }
            system("pause");
            break;
        }   
        case 7:
        {
            std::reverse(tablica,tablica+n);
            system("cls");
            for(int i=0; i<n; i++)
            {
                std::cout<<"Odwrocona: "<<tablica[i]<<std::endl;
            }
            system("pause");
            break;
        }   
        case 0:
        {
            std::cout<<"Przerwano dzialanie programu!";
            break;
        }   
        default:
        {
            std::cout<<"Liczba spoza zakresu!!!";
            break;
        }
        if(choice!=0)
        {
            system("cls");
        }
        }
    } 
    while (choice!=0);
    delete[] tablica; //zwolnienie pamieci
    return 0; 
}