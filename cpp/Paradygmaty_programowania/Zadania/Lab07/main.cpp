#include <iostream>
#include <vector>
#include <string>
#include <limits>
/*
klasa bazowa Pracownik zawiera:
    imię,
    nazwisko,
    identyfikator,
    wirtualną metodę obliczPensje(),
    wirtualną metodę wyswietl(),
• klasy pochodne:
    PracownikEtatowy,
    PracownikGodzinowy,
    PracownikProwizyjny,
• każda klasa pochodna inaczej liczy pensję,
• wszystkie dane wrażliwe są hermetyzowane,
• użytkownik może dodać pracowników, wyświetlić ich dane i policzyć sumę 
wynagrodzeń
*/
class Pracownik
{
    private:
        std::string imie; 
        std::string nazwisko;
        int id; 
    public:
        Pracownik(std::string i,std::string n,int id) : imie(i),nazwisko(n),id(id) {}
        //destruktor
        virtual ~Pracownik() {}
        virtual double obliczPensje() const = 0; 
        virtual void wyswietl() const 
        {
            std::cout<<"ID: "<<id<<" Imie: "<<imie<<" Nazwisko: "<<nazwisko<<std::endl;
        }
};
class PracownikEtatowy: public Pracownik
{
    private:
        double PensjaMiesieczna;
    public:
        PracownikEtatowy(std::string i, std::string n, int id, double pensja) : Pracownik(i,n,id) 
        {
            setPensja(pensja);
        }
        void setPensja(double pensja)
        {
            if(pensja<0)
            {
                std::cout<<"Pensja nie moze byc ujemna!"<<std::endl;
            }
            else
            {
                PensjaMiesieczna = pensja;
            }
        }
        double obliczPensje() const override
        {
            return PensjaMiesieczna;
        }
        void wyswietl() const override
        {
            Pracownik::wyswietl();
            std::cout<<"[Umowa o prace] Pensja: "<<obliczPensje()<<" zl"<<std::endl;
        }
};
class PracownikGodzinowy: public Pracownik
{
    private:
        double stawka;
        int godziny;
    public:
        PracownikGodzinowy(std::string i,std::string n,int id,double s,int g) : Pracownik(i,n,id)
        {
            setstawka(s);
            setgodziny(g);
        }
        void setstawka(double s)
        {
            if(s<0)
            {
                std::cout<<"Stawka nie moze byc ujemna!"<<std::endl;
            }
            else
            {
                stawka =s ;
            }
        }
        void setgodziny(int g)
        {
            if(g<0)
            {
                std::cout<<"Godziny nie moga byc ujemne!"<<std::endl;
            }
            else
            {
                godziny = g; 
            }
        }
        double obliczPensje() const override
        {
            return stawka*godziny;
        }
        void wyswietl() const override
        {
            Pracownik::wyswietl();
            std::cout<<"[Umowa godzinowa] Pensja: "<<obliczPensje()<<" zl"<<std::endl;
        }
};
class PracownikProwizyjny: public Pracownik
{
private:
    double sprzedaz; //0.10 = 10% etc. 
    double prowizja;
public:
    PracownikProwizyjny(std::string i,std::string n,int id,double s,double p): Pracownik(i,n,id)
    {
        setSprzedaz(s);
        setProwizja(p);
    }
    void setSprzedaz(double s)
    {
        if(s<0)
        {
            std::cout<<"Sprzedaz nie moze byc ujemna"<<std::endl;
        }
        else
        {
            sprzedaz = s;
        }
    }
    void setProwizja(double p)
    {
        if(p<0.0 || p>1.0)
        {
            std::cout<<"Prowizja musi byc wartoscia miedzy 0 a 1"<<std::endl;
        }
        else
        {
            prowizja = p;
        }
    }
    double obliczPensje() const override 
    {
        return sprzedaz*prowizja;
    }
    void wyswietl() const override
    {
        Pracownik::wyswietl();
        std::cout<<"[Umowa prowizyjna] Pensja: "<<obliczPensje()<<" zl"<<std::endl;
    }    
};
int main()
{
    std::vector<Pracownik*> kadr;
    bool dziala = true;
    while(dziala)
    {
        std::cout<<"Co chcesz zrobic:\n1. Dodaj pracownika\n2. Wyswietl dane pracownikow\n3. Policz sume wynagrodzen\n4. Wyjscie\nTwoj wybor: ";
        int u_input = 0;
        if(!(std::cin>>u_input)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Nieprawidlowy input. Sprobuj ponownie."<<std::endl;
            continue;
        }
        switch(u_input)
        {
            case 1:
                {
                    std::cout<<"Wybor: Dodaj pracownika"<<std::endl;
                    std::cout<<"Wybierz typ pracownika: 1-Etatowy, 2-Godzinowy, 3-Prowizyjny: ";
                    int typ = 0;
                    if(!(std::cin>>typ)){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout<<"Nieprawidlowy wybor typu."<<std::endl;
                        break;
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    std::string imie, nazwisko;
                    int id;
                    std::cout<<"Podaj imie: ";
                    std::getline(std::cin, imie);
                    std::cout<<"Podaj nazwisko: ";
                    std::getline(std::cin, nazwisko);
                    std::cout<<"Podaj id (liczba): ";
                    if(!(std::cin>>id)){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout<<"Nieprawidlowe id."<<std::endl;
                        break;
                    }

                    if(typ==1){
                        double pensja;
                        std::cout<<"Podaj pensje miesieczna: ";
                        if(!(std::cin>>pensja) || pensja<0){
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout<<"Nieprawidlowa pensja."<<std::endl;
                        } else {
                            kadr.push_back(new PracownikEtatowy(imie,nazwisko,id,pensja));
                            std::cout<<"Dodano pracownika etatowego."<<std::endl;
                        }
                    } else if(typ==2){
                        double stawka; int godziny;
                        std::cout<<"Podaj stawke za godzine: ";
                        if(!(std::cin>>stawka) || stawka<0){
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout<<"Nieprawidlowa stawka."<<std::endl;
                        } else {
                            std::cout<<"Podaj liczbe godzin: ";
                            if(!(std::cin>>godziny) || godziny<0){
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                std::cout<<"Nieprawidlowe godziny."<<std::endl;
                            } else {
                                kadr.push_back(new PracownikGodzinowy(imie,nazwisko,id,stawka,godziny));
                                std::cout<<"Dodano pracownika godzinowego."<<std::endl;
                            }
                        }
                    } else if(typ==3){
                        double sprzedaz, prowizja;
                        std::cout<<"Podaj wartosc sprzedazy: ";
                        if(!(std::cin>>sprzedaz) || sprzedaz<0){
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout<<"Nieprawidlowa wartosc sprzedazy."<<std::endl;
                        } else {
                            std::cout<<"Podaj prowizje (0.0 - 1.0): ";
                            if(!(std::cin>>prowizja) || prowizja<0.0 || prowizja>1.0){
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                std::cout<<"Nieprawidlowa prowizja."<<std::endl;
                            } else {
                                kadr.push_back(new PracownikProwizyjny(imie,nazwisko,id,sprzedaz,prowizja));
                                std::cout<<"Dodano pracownika prowizyjnego."<<std::endl;
                            }
                        }
                    } else {
                        std::cout<<"Nieprawidlowy typ pracownika."<<std::endl;
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                break;
            case 2:
                std::cout<<"Wybor: Wyswietl dane pracownikow"<<std::endl;
                std::cout<<"Lista pracownikow: "<<std::endl;
                for(const auto& pracownik:kadr)
                {
                    pracownik->wyswietl();
                }
                break;
            case 3:
                {
                    std::cout<<"Wybor: Policz sume wynagrodzen"<<std::endl;
                    double sumaWynagrodzen = 0;
                    for(const auto& pracownik:kadr)
                    {
                        sumaWynagrodzen += pracownik->obliczPensje();
                    }
                    std::cout<<"Suma wynagrodzen dla calego zespolu: "<<sumaWynagrodzen<<" zl"<<std::endl;
                }
                break;
            case 4:
                std::cout<<"Koniec programu. Zwalnianie pamieci."<<std::endl;
                dziala = false;
                break;
            default:
                std::cout<<"Nieprawidlowy wybor"<<std::endl;
                break;
        }
    }
    for(auto p : kadr) delete p;
    return 0;
}


