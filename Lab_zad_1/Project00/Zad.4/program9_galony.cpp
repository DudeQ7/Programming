#include <iostream>
#include <iomanip>
//przelicznik litry na galony
using namespace std;
int main() {
    double objetosc_l;
    cout << "Podaj wielkosc objetosci w litrach: ";
    cin >> objetosc_l;
    double galon = objetosc_l * 0.26417;
    cout <<"Objetosc w galonach wynosi: "<< galon <<" w przyblizeniu: "<<std::fixed<<std::setprecision(1)<<galon<<" gal";
    return 0;
}
