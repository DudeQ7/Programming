#include <iostream>
#include <queue>
#include <list>
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
             <<"3   Zwroc rower: usuniecie z listy po nazwisku"
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
            std::cout<<"Dodano do kolejki: "<<nazwisko;
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