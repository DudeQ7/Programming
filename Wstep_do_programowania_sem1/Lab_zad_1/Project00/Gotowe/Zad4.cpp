// roznica zad.4a
#include <iostream>

using namespace std;

int main() {
    int a,b;
    cout <<"Podaj wartosc a: ";
    cin >> a;
    cout <<"Podaj wartosc b: ";
    cin >> b;
    int opcja_1 = a - b ;
    int opcja_2 = b - a ;

    cout <<"a - b jest rowne: "<< opcja_1 << endl;
    cout <<"b - a jest rowne: "<< opcja_2 << endl;

    return 0;
}



/*
// iloczyn zad.4b
#include <iostream>

using namespace std;

int main() {
    double a,b;
    cout <<"Podaj wartosc a: ";
    cin >> a;
    cout <<"Podaj wartosc b: ";
    cin >> b;
    double iloczyn = a * b ;
    cout <<"Wynik iloczynu a * b: "<<iloczyn<<endl;

    return 0;
}
*/


/*
// iloraz zad.4c
#include <iostream>

using namespace std;

int main() {
    double a,b;
    cout <<"Podaj wartosc a: ";
    cin >> a;
    cout <<"Podaj wartosc b: ";
    cin >> b;
    double iloraz = a / b ;
    double iloraz_2 = b/a;
    cout <<"Wynik ilorazu a / b: "<<iloraz<<endl;
    cout <<"Wynik ilorazu b / a: "<<iloraz_2<<endl;

    return 0;
}
*/


/*
// iloraz_calkowity zad.4b
#include <iostream>

using namespace std;

int main() {
    int a,b;
    cout <<"Podaj wartosc a: ";
    cin >> a;
    cout <<"Podaj wartosc b: ";
    cin >> b;
    int iloraz = a / b ;

    cout <<"Wynik ilorazu calkowitego a / b: "<<iloraz<<endl;
    return 0;
}
*/


/*
// reszta z dzielenia zad.4e
#include <iostream>

using namespace std;

int main() {
    int a,b;
    cout <<"Podaj wartosc a: ";
    cin >> a;
    cout <<"Podaj wartosc b: ";
    cin >> b;
    int iloraz = a % b ;
    cout <<"Wynik reszty z dzielenia a % b: "<<iloraz<<endl;
    return 0;
}
*/


/*
// cale do cm zad.4f
#include <iostream>

using namespace std;

int main(){
    double wybor;
    cout <<"Program zostal przygotowany przez Pawla Dutkiewicza"<<endl<<"Progam zostal przygotowany dnia 28 pazdziernika 2024"<<endl;
    cout << "Podaj dlugosc wyrazona w calach: ";
    cin >> wybor;
    double centymetry = wybor * 2.54;
    cout <<"Podana dlugosc wynosi : "<<centymetry<<" centymetrow" << endl;
    
    return 0;
}
*/

/*
// ZŁ do USD zad.4g
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
double zlotowki;
const double kurs_dolara = 4.0230 ; // kurs sredni na dzien 28.10.2024
cout << "Jaka kwote checesz przeliczyc na dolary: ";
cin >> zlotowki;
double wynik = zlotowki / kurs_dolara;
cout <<"Twoja kwota: "<<zlotowki <<" zl"<<" jest rowna: "<<wynik<<" $"<<" w przyblizeniu: "<<fixed<<setprecision(2)<<wynik;
    return 0;
}
*/


/*
// temperatura ℃ dp °F zad.4h
#include <iostream>

using namespace std;
double wartosc;

int main() {
    cout<<"Podaj wartosc jaka stopni Celsjusza jaka chcesz przeliczyc: ";
    cin >> wartosc;
    double fahrenheit = wartosc * 9/5 +32; 
    cout << wartosc <<" stopni Celsujsza"<<" jest rowna: "<<fahrenheit <<" stopni Fahrenheita";
    return 0;
}
*/


/*
// przelicznik litry na galony zad.4i
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double objetosc_l;
    cout << "Podaj wielkosc objetosci w litrach: ";
    cin >> objetosc_l;
    double galon = objetosc_l * 0.26417;
    cout <<"Objetosc w galonach wynosi: "<< galon <<" w przyblizeniu: "<<fixed<<setprecision(1)<<galon<<" gal";
    return 0;
}
*/


/*
// przelicznik kilogramy na funty zad.4j
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double liczba;
    cout <<"Podaj ilosc kilogramow do przeliczenia:  ";
    cin >> liczba;
    double funty = liczba /  0.45359237;

    cout << "Twoja liczba: "<<liczba<<" kg"<<" jest rowna: "<<funty<<" lbs"<<" w przyblizeniu: "<<fixed<<setprecision(2)<<funty<<" lbs";
    return 0;
}
*/