#include <iostream> 
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
    /* data */
public:
    std::string imie;
    std::string nazwisko; 
    int identyfikator;
    virtual double obliczPensje() = 0; //check
    virtual double wyswietl() = 0; //check
};
class PracownikEtatowy : public Pracownik
{
private:
};

class PracownikGodzinowy : public Pracownik
{
private:
};
class PracownikProwizyjny : public Pracownik
{
private:
};
int main()
{
    return 0;
}