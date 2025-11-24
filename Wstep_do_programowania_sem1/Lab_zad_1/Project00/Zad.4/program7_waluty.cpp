#include <iostream>
#include <iomanip>
// ZŁ do USD
using namespace std;
int main() {
double zlotowki;
const double kurs_dolara = 4.0230 ; // kurs sredni na dzien 28.10.2024
cout << "Jaka kwote checesz przeliczyc na dolary: ";
cin >> zlotowki;
double wynik = zlotowki / kurs_dolara;
cout <<"Twoja kwota: "<<zlotowki <<" zl"<<" jest rowna: "<<wynik<<" $"<<" w przyblizeniu: "<<std::fixed<<std::setprecision(2)<<wynik;
    return 0;
}
