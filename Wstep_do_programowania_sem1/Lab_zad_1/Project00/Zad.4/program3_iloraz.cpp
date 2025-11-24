#include <iostream>
//iloraz
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
