#include <iostream>
//temperatura ℃ dp °F
using namespace std;
double wartosc;

int main() {
    cout<<"Podaj wartosc jaka stopni Celsjusza jaka chcesz przeliczyc: ";
    cin >> wartosc;
    double fahrenheit = wartosc * 9/5 +32; 
    cout << wartosc <<" stopni Celsujsza"<<" jest rowna: "<<fahrenheit <<" stopni Fahrenheita";
    return 0;
}
