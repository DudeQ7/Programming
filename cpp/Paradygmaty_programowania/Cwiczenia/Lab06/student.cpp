#include <iostream>
class Student
{
    public:
        std::string imie;
    private:
        double srednia;
    void ustawSrednia()
    {
        if((srednia=2.0)||(srednia=5.0))
        {
            std::cout<<"Poprawna wartosc";
        }
    }
    void pobierzSrednia()
    {

    }
    };
int main()
{
    Student mojstudent;
    mojstudent.imie = "Pablo";
    mojstudent.srednia = 5.0;

}