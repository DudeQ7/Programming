#include <iostream>
#include <iomanip>

//przelicznik kilogramy na funty
using namespace std;
int main() {
    double liczba;
    cout <<"Podaj ilosc kilogramow do przeliczenia:  ";
    cin >> liczba;
    double funty = liczba /  0.45359237;

    cout << "Twoja liczba: "<<liczba<<" kg"<<" jest rowna: "<<funty<<" lbs"<<" w przyblizeniu: "<<std::fixed<<std::setprecision(2)<<funty<<" lbs";
    return 0;
}
