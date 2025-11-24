#include <iostream>
//roznica
using namespace std;

int main() {
    int a,b;
    cout <<"Podaj wartosc a: ";
    cin >> a;
    cout <<"Podaj wartosc b: ";
    cin >> b;
    int opcja_1 = a - b ;
    int opcja_2 = b - a ;

    cout <<"a - b jest rowne: "<< opcja_1<<endl;
    cout <<"b - a jest rowne: "<< opcja_2<<endl;

    return 0;
}
