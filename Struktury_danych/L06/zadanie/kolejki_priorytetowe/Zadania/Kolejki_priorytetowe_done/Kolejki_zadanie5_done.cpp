#include <iostream>
#include <queue>
#include <string>

/*
Zastosowanie kolejki priorytetowej. 
Zaimplementuj program symulujący system obsługi zgłoszeń technicznych: 
1. Każde zgłoszenie zawiera: identyfikator, opis oraz priorytet. 
2. Program umożliwia: 
a. dodanie nowego zgłoszenia, 
b. obsłużenie zgłoszenia o najwyższym priorytecie, 
c. wyświetlenie liczby oczekujących zgłoszeń. 
3. Program działa w pętli do momentu wybrania opcji zakończenia
*/
struct zgloszenie
{
    std::string identyfikator;
    std::string opis;
    int priorytet;
    // Operator porównania - większy priorytet = ważniejsze zgłoszenie
    bool operator<(const zgloszenie&other) const
    {
        return priorytet < other.priorytet; 
    }
};
int main()
{
    std::priority_queue<zgloszenie> kolejka;
    int u_input = -1 ; //inicjalizacja
    while(u_input!=0)
    {
    std::cout<<"\n\nSystem Obslugi Ticket'ow"<<"\n1.Dodanie nowego zgloszenia"<<std::endl<<"2.Obsluzenie zgloszenia o najwyzszym priorytecie"<<std::endl<<"3.Wyswietlenie liczby oczekujacych zgloszen"<<std::endl<<"0.Zakonczenie dzialania programu"<<std::endl;
    std::cout<<"Twoj wybor: ";
    std::cin>>u_input;
    switch (u_input)
    {
    case 1:
    {
        std::cout<<"Opcja wybrana: Dodanie nowego zgloszenia"<<std::endl;
    zgloszenie z1;
    std::cout<<"Podaj identyfikator: ";
    std::cin.ignore();
    std::getline(std::cin,z1.identyfikator);
    std::cout<<"Podaj opis: ";
    std::getline(std::cin,z1.opis); //poprzednio sie program krzaczyl przy wpisaniu wiecej niz jedno slowo 
    std::cout<<"Podaj priorytet(liczba calkowita): ";
    std::cin>>z1.priorytet;
    kolejka.push(z1);
    std::cout<<"Zgloszenie o identyfikatorze: "<<z1.identyfikator<<" z opisem: "<<z1.opis<<" z priorytetem: "<<z1.priorytet<<" zostalo utworzone";
    break;
    }
    case 2:
    {
        std::cout<<"Opcja wybrana: Obsluzenie zgloszenia o najwyzszym priorytecie"<<std::endl;
    if(kolejka.empty())
    {
        std::cout<<"Brak zgloszen do obslugi"<<std::endl;
    }
    else
    {
        zgloszenie z = kolejka.top();
        std::cout<<"Obslugiwane zgloszenie"<<std::endl;
        std::cout<<" ID: "<<z.identyfikator<<std::endl;
        std::cout<<" Opis: "<<z.opis<<std::endl;
        std::cout<<" Priorytet: "<<z.priorytet<<std::endl;
        kolejka.pop();
        std::cout<<"Zgloszenie zostalo obsluzone"<<std::endl;
    }
    break;
    }
    case 3: 
    {
        std::cout<<"Opcja wybrana: Wyswietlenie liczby oczekujacych zgloszen"<<std::endl;
    std::cout<<"Aktualnie na realizacje oczekuje: "<<kolejka.size()<<" zgloszen"<<std::endl;
    break;
    }
    case 0:
    {
        std::cout<<"Program zakonczyl dzialanie";
        break;
    }
    default:
    {
         std::cout<<"Opcja wybrana: Wybrales opcje spoza zakresu";
    break;
    }
    }
    }
    return 0;
}