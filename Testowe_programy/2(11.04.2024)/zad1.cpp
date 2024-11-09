//Opcja uno:
// #include <iostream>
// /*
// Napisz program, w ktorym podasz swoj rok urodzenia (zmienna ur) i podasz aktualny rok (zmienna rok). Program ma wyswietlic, czy jestes osoba pelnoletnia.*/
// using namespace std;
// int wiek, rok;
// int main() {
//    cout << "Podaj rok urodzenia: ";
//    cin >> wiek;
//    cout << "Podaj aktualny rok: ";
//    cin >> rok; 
//    if(rok - wiek >= 18){
//     cout << "Jestes pelnoletni";
//    } 
//    else
//    {
//     cout << "Nie jestes pelnoletni";
//    }
   
//     return 0;
// }
#include <iostream>
using namespace std;
/*
Napisz program, w ktorym podasz swoj rok urodzenia (zmienna ur) i podasz aktualny rok (zmienna rok). Program ma wyswietlic, czy jestes osoba pelnoletnia.*/
class zadanie1
{
    public:
    //zmienne
        int rok_ur;
        int rok_akt;
        int roznica;
    void wprowadzenie()
    {
        cout << "Podaj rok urodzenia: "<<endl;
        cin >> rok_ur;
        cout <<"Podaj akutalny rok: "<<endl;
        cin >> rok_akt;
    }
    void liczenie() {
        roznica = rok_akt-rok_ur;
            if(roznica >= 18)
            {
                cout << "jestes pelnoletni "<<endl;
            }
            else
            {
                cout <<"jestes niepelnoletni "<<endl;
            }
            
    }
};
int main() {
    zadanie1 zad;
    zad.wprowadzenie();
    zad.liczenie();   
    return 0;
}
