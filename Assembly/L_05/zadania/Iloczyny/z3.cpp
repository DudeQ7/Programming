#include <iostream>
int a, b, c, d;
/*
Napisz funkcję w asemblerze liczącą iloczyn z 4 podanych liczb jako argumenty. Liczby
typu całkowitego.
*/
extern "C" int iloczyn(int a,int b,int c, int d);
int main() {
    
    std::cout << "Podaj wartosc a: ";
    std::cin >> a;
    std::cout << "Podaj wartosc b: ";
    std::cin >> b;
    std::cout << "Podaj wartosc c: ";
    std::cin >> c;
    std::cout << "Podaj wartosc d: ";
    std::cin >> d;
    int wynik = iloczyn(a,b,c,d);
    std::cout << "Wynik to " << wynik << std::endl;
    return 0;
}
