#include <iostream>
using namespace std;
/*
Napisz program  "zadanie4.cpp", w którym user podaje zmienną int A - numer dnia tygodnia (1-poniedziałek, 2-.
Jeżeli A nie jest z zakresu od 1 do 7 - wyświetl komunikat "błędny numer"
Jeżeli A jest z zakresu od 1 do 7, oblicz i wyświetl ile dni pozostało do weekendu,
a następnie korzystając z instrukcji switch - wyświetl jaki jest dzień i dni do weekendu.
Jeżeli podana wartość A jest >5 i <=7 wyświetl "już trwa weekend"
np. A=4
wynik: "czwartek, do weekendu pozostało: czwartek, piątek"*/
class zadanie4{
    public:
        int A;
    
    void sprawdzenie()
    {
        cout << "Podaj numer dnia tygodnia: ";
        cin >> A;
    }
    void dzialanie()
    {
         const string dni[] = {"Niedziela","Sobota","Piatek","Czwartek","Sroda","Wtorek","Poniedzialek"};//bedzie latwiej wywolywac dane dni

        if(A>=1&&A<=7)
        {
            cout <<"Podany dzien_tygodnia znajduje sie w podanym zakresie!"<<endl;
            switch(A)
            {
                case 1:
                    cout << "Poniedzialek ,do weekendu pozostalo: ";
                    if(A>=1 && A<=5)
                         {
                            for(int i=5; i>A; i--)
                            {
                                cout <<dni[i]<< ", ";
                            }
                         }
                    else{
                            cout<<"Weekend juz trwa";
                        }
                    break;
                case 2:
                    cout << "Wtorek ,do weekendu pozostalo: ";
                    if(A>=1 && A<=5)
                         {
                            for(int i=5; i>=A; i--)
                            {
                                cout <<dni[i]<< ", ";
                            }
                         }
                    else{
                            cout<<"Weekend juz trwa";
                        }
                    break;
                case 3:
                    cout <<"Sroda"<<endl;
                     if(A>=1 && A<=5)
                         {
                            int left = 6-A;
                            cout << "Zostaly: "<<left<<" dni do weekendu!";
                         }
                    else{
                            cout<<"Weekend juz trwa";
                        }
                    break;
                case 4:
                    cout <<"Czwartek"<<endl;
                     if(A>=1 && A<=5)
                         {
                            int left = 6-A;
                            cout << "Zostaly: "<<left<<" dni do weekendu!";
                         }
                    else{
                            cout<<"Weekend juz trwa";
                        }
                    break;
                case 5:
                    cout << "Piatek"<<endl;
                     if(A>=1 && A<=5)
                         {
                            int left = 6-A;
                            cout << "Zostal: "<<left<<" dzien do weekendu!";
                         }
                    else{
                            cout<<"Weekend juz trwa";
                        }
                    break;
                case 6:
                    cout <<"Sobota"<<endl;
                     if(A>=1 && A<=5)
                         {
                            int left = 6-A;
                            cout << "Zostalo: "<<left<<" dni do weekendu!";
                         }
                    else{
                            cout<<"Weekend juz trwa";
                        }
                    break;
                case 7:
                    cout << "Niedziela"<<endl;
                     if(A>=1 && A<=5)
                         {
                            int left = 6-A;
                            cout << "Zostalo: "<<left<<" dni do weekendu!";
                         }
                    else{
                            cout<<"Weekend juz trwa";
                        }
                    break;
            }
        }
        else
        {
            cout << "Podany dzien_tygodnia nie znajduje sie w podanym zakresie"<<endl;
        }
    }
};





int main() {
    zadanie4 zad ;
    zad.sprawdzenie();
    zad.dzialanie() ;

    
    return 0;
}
