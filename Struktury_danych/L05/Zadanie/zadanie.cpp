#include <iostream>
#include <queue>
#include <list>
#include <fstream>
/*
Umieść plik ze sprawozdaniem (format DOC/DOCX) i plik z kodem programu (CPP).
Nazwij sprawozdanie i kod swoim nazwiskiem (np. kowalski.docx + kowalski.cpp)
Nie korzystaj z typu auto. 
Umieść dodatkowo plik z danymi (kowalski.txt) który uzupełni dane w programie
*/
void screen_clear()
{
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}
struct Wypozyczenie 
{
    std::string nazwisko;
    std::string model;
};
bool porownaj_nazw(const Wypozyczenie&a,const Wypozyczenie&b)
{
    return a.nazwisko < b.nazwisko;
}
int main()
{
    int u_input;
    std::queue<std::string> kolejka; //obsluga kolejki oczekujacych
    std::list<Wypozyczenie>wypozyczenie;
    do
    {
    screen_clear();
    std::cout<<"Wybierz dzialanie:\n"
             <<"1   Dodaj osobe do kolejki oczekujacych (queue<string)\n"
             <<"2   Wypozycz rower pierwszej osobie z kolejki > dodanie do listy (list)\n"
             <<"3   Zwroc rower: usuniecie z listy po nazwisku\n"
             <<"4   Wyswietl kolejke oczekujacych\n"
             <<"5   Wyswietl liste wypozyczonych rowerow\n"
             <<"6   Posortuj liste wypozyczen wg nazwisk\n"
             <<"9   Zakoncz program\n"
             <<"Twoj wybor: ";
    std::cin>>u_input;
    switch(u_input)
    {
        case 1:
        {
            Wypozyczenie wyp;
        std::cout<<"Podaj nazwisko osoby, ktora chce wypozyczyc rower: ";
        std::cin>>wyp.nazwisko;
        kolejka.push(wyp.nazwisko);
        if(!kolejka.empty())
        {
            std::cout<<"Dodano do kolejki: "<<wyp.nazwisko;
        }
        break;
        }
        case 2: 
        {
        if(!kolejka.empty()) 
        {
        std::string first_element = kolejka.front(); //pobranie
        kolejka.pop(); //usuniecie
        Wypozyczenie wyp;
        wyp.nazwisko = first_element;
        wyp.model = "Standard";
        wypozyczenie.push_back(wyp);
        std::cout<<"Wypozyczono rower dla: "<<first_element<<"\n";
        }
        else
        {
            std::cout<<"Twoja kolejka jest pusta!!!";
        }
        break;
        }
        case 3:
        {
            std::string szukane_nazwisko;
            bool znaleziono = false; 
            std::cout<<"Jak nazywa sie osoba ktora zwraca rower: ";
            std::cin>>szukane_nazwisko;
            for (auto it = wypozyczenie.begin(); it != wypozyczenie.end(); ++it)
            {
                if(it->nazwisko == szukane_nazwisko)
                {
                    std::cout<<"Znaleziono wypozyczenie dla: "<<it->nazwisko<<" (model: "<<it->model<<")\n";
                    wypozyczenie.erase(it);
                    std::cout<<"Rower zostal zwrocony";
                    znaleziono = true;
                    break;
                }
            }
            if(!znaleziono)
            {
                std::cout<<"Brak wypozyczenia dla nazwiska: "<<szukane_nazwisko;
            }
            break;
        }
        case 4:
        {
            //lista wypozyczonych rowerow
            std::cout<<"Kolejka oczekujacych osob: \n";
            if(kolejka.empty())
            {
                std::cout<<"Aktualnie nie ma oczekujacych klientow!!!";
            }
            else
            {
                std::queue<std::string> kopia = kolejka;
                int num =1 ;
                while(!kopia.empty())
                {
                    std::cout<<"Osoba numer: "<<num<<" to: "<<kopia.front()<<"\n";
                    kopia.pop();
                    num++;
                }
            }
            break;

        }
        case 5:
        {
            /*
            5. Wyświetl listę wypożyczonych rowerów 
            Cel: prezentacja danych w kontenerze list. 
            • Użycie iteratorów lub pętli for(auto &x : list) 
            • Prezentacja: nazwisko, model, data 
            • Wymagane sprawdzenie: if(list.empty())
            */
           std::cout<<"Lista wypozyczonych rowerow: \n";
           if(wypozyczenie.empty())
           {
            std::cout<<"Lista jest pusta!!!";
           }
           else
           {
            int num=1;
            for(auto it =wypozyczenie.begin(); it != wypozyczenie.end(); ++it)
            {
                        std::cout <<"Rower numer: "<< num <<" wypozyczony dla: " << it->nazwisko<<" to: "   
                      << " (model: " << it->model << ")\n";                num++;
            }
           }
           break;
        }
        case 6:
        {
            if(wypozyczenie.empty())
            {
                std::cout<<"Lista jest pusta!!!";
            }
            else
            {
                wypozyczenie.sort(porownaj_nazw);
                std::cout<<"Lista posortowana wg. nazwisk: ";
               int num =1 ; 
               for(auto it = wypozyczenie.begin(); it != wypozyczenie.end(); ++it)
               {
                std::cout<<"\nNumer: "<<num<<" "<<it->nazwisko<<" model: "<<it->model;
                num++;
               }
            }
            break;
        }
        default:
            std::cout<<"Podales liczbe spoza zakresu!";
            break; 
    };
    if (u_input != 9)
    {
        std::cout<<"\nNacisnij enter by kontynuowac....";
        std::cin.ignore(); 
        std::cin.get();
    }
    }   
     while (u_input!=9);
    return 0; 
}