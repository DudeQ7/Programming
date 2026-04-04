#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
int main()
{
    int choice=0;
    int n = 0;
    std::cout <<"Ile liczb chcesz wprowadzic: ";
    std::cin>>n;
    std::vector<int>numbers(n);
    for(int i=0; i<n; i++)
        {
            std::cout<<"Podaj liczbe["<<i+1<<"/"<<n<<"]: ";
            std::cin>> numbers[i];
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
            for(int j=0; j<numbers.size(); j++)
            {
                std::cout<<"Liczby: "<<numbers[j]<<std::endl;
                suma+=numbers[j];
            }
            double srednia= suma / numbers.size();
            std::system("cls");
            std::cout<<"\nSuma to: "<<suma<<std::endl;
            std::cout<<"Srednia to: "<<srednia<<std::endl;
            std::system("pause");
            break;
        }   
        case 2:
        {
            double max = *std::max_element(numbers.begin(),numbers.end()); //https://stackoverflow.com/questions/9874802/how-can-i-get-the-maximum-or-minimum-value-in-a-vector
            double  min= *std::min_element(numbers.begin(),numbers.end());
            std::system("cls");
            std::cout<<"Wartosc maksimum: "<<max<<std::endl;
            std::cout<<"Wartosc minimum: "<<min<<std::endl;
            std::system("pause");
            break;
        }   
        case 3:
        {
            int parzyste=0,ujemne=0,nieparzyste=0;
            std::system("cls");
            for(int i=0; i<numbers.size(); i++)
            {
                if(numbers[i]>0)
                {
                    std::cout<<numbers[i]<<"Jest dodatnie";
                }
                else if(numbers[i]<0)
                {
                    std::cout<<numbers[i]<<"Jest ujemne";
                }
                else
                {
                    std::cout<<numbers[i]<<"Jest zerem";
                }
                if(numbers[i]%2==0)
                {
                    //parzyste 
                    std::cout<<numbers[i]<<" jest parzyste!"<<std::endl;
                }
                else
                {
                    std::cout<<numbers[i]<<" jest nieparzyste!"<<std::endl;
                }
            }
            std::system("pause");
            break;
        }   
        case 4:
        {
            int liczba=0,ilosc_wystapien=0;
            std::cout<<"Podaj liczbe,ktora chcesz wyszukac: ";
            std::cin>>liczba;
            std::system("cls");
            for(int i=0; i<numbers.size(); i++)
            {
                if(numbers[i]==liczba)
                {
                    ilosc_wystapien++;
                }
            }
            if(ilosc_wystapien>0)
            {
                std::cout<<liczba<<" wystepuje: "<<ilosc_wystapien<<" razy!";
            }
            else
            {
                std::cout<<liczba<<" nie wystepuje ani razu";
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
                int wew_wybor=0;
                std::cout<<"Program ma wyswietlic liczby mniejsze od: ";
                std::cin>>wew_wybor;
                system("cls");
                 for(int i=0; i<numbers.size(); i++)
                {
                    if(numbers[i]<wew_wybor)
                    {
                        std::cout<<"Liczby mniejsze od: "<<wew_wybor<<numbers[i];
                    }
                }
                system("pause");
                break;
                }
                case 2:
                {
                int wew_wybor=0;
                std::cout<<"Program ma wyswietlic liczby wieksze od: ";
                std::cin>>wew_wybor;
                system("cls");
                 for(int i=0; i<numbers.size(); i++)
                {
                    if(numbers[i]>wew_wybor)
                    {
                        std::cout<<"Liczby wieksze od: "<<wew_wybor<<numbers[i];
                    }
                }
                system("pause");
                break;
                }
                case 3:
                {
                 int wew_wybor=0;
                std::cout<<"Program ma wyswietlic liczby rowne od: ";
                std::cin>>wew_wybor;
                system("cls");
                 for(int i=0; i<numbers.size(); i++)
                {
                    if(numbers[i]==wew_wybor)
                    {
                        std::cout<<"Liczby rowne od: "<<wew_wybor<<numbers[i];
                    }
                }
                system("pause");
                break;
                }
                case 4:
                {
                int dolny_zakres=0,gorny_zakres=0;
                system("cls");
                std::cout<<"Podaj liczbe z dolnego zakresu: ";
                std::cin>>dolny_zakres;
                std::cout<<"Podaj liczbe z gornego zakresu: ";
                std::cin>>gorny_zakres;
                system("cls");
                for(int i=0; i<numbers.size(); i++)
                {
                    if((numbers[i]>dolny_zakres)&&(numbers[i]<gorny_zakres))
                    {
                        std::cout<<numbers[i];
                    }
                    else
                    {
                        std::cout<<"Brak liczb z tego zakresu!!!";
                    }
                }
                system("pause");
                break;
                }
                case 5:
                {
                int linczik = 0;
                system("cls");
                std::cout<<"Podaj wartosc  liczby , ktora chcesz sprawdzic: ";
                std::cin>>linczik;
                system("cls");
                for(int i=0; i<numbers.size(); i++)
                {
                    if(linczik)
                    {
                        std::cout<<numbers[i]<<"\n";
                        linczik++;
                    }
                }
                if(linczik==0)
                {
                    std::cout<<"Brak liczb spelniajacych warunek";
                }
                system("pause");
                break;
                }
                case 6:
                {
                    int rozny=0,wystapienia=0;;
                    std::cout<<"Podaj wartosc roznej liczby , ktora chcesz sprawdzic: ";
                    std::cin>>rozny;
                    system("cls");
                    for(int i=0; i<numbers.size(); i++)
                    {
                        if(rozny)
                        {
                            std::cout<<numbers[i];
                            rozny++;

                        }
                    }
                    if(wystapienia==0)
                    {
                         std::cout<<"Nie wystepuja takie liczby!";
                    }
                    system("pause");
                break;
                }
                case 7:
                std::cout<<"Przerwano dzialanie programu!!!!";
                break;
            default:
                std::cout<<"Podales liczbe spoza zakresu!";
                break;
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
            sort(numbers.begin(),numbers.end());
            system("cls");
            //https://www.geeksforgeeks.org/cpp/sorting-a-vector-in-c/
            for(auto i:numbers)
            {
                std::cout<<"Posortowane liczby: "<<i<<std::endl;
            }
            system("pause");
            }
            else if(wybor_sortowania==2)
            {
            sort(numbers.begin(),numbers.end(),std::greater<int>());
            system("cls");
            //https://www.geeksforgeeks.org/cpp/sorting-a-vector-in-c/
            for(auto i:numbers)
            {
                std::cout<<"Posortowane liczby: "<<i<<std::endl;
            }
            system("pause");
            }
            else
            {
                std::cout<<"Podales wartosc spoza zakresu!";
            }
            
            break;
        }   
        case 7:
        {
            //https://www.geeksforgeeks.org/cpp/stdreverse-in-c/
            std::reverse(numbers.begin(),numbers.end());
            system("cls");
            for(int i: numbers)
            {
                std::cout<<"Odwrocony wektor: "<<i<<std::endl;
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
      
        }
    } 
    while (choice!=0);
    
}