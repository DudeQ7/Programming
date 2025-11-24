#include <iostream>
//reszta z dzielenia
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
