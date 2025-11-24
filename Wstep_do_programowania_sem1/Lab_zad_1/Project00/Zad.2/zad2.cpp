#include <iostream>
#include <cmath>
using namespace std;
int main(){
    #define r 5 
    const double pi = 3.1415;
    float pole_kola = pi * (r*r); //pi* r^2
    cout<<"Pole kola jest rowne: "<<pole_kola<<endl;
    float obwod_okregu = 2 * pi * r; // 2 * pi * r 
   cout<<"Obwod okregu jest rowny: "<<obwod_okregu<<endl;
   int r_2;
   cout <<"Podaj wartosc r: ";
   cin >> r_2;
   float pole_calkowite_kuli = 4 *pi * (r_2*r_2); // 4 * pi * r
   cout <<"Pole powierzchni calkowite kuli jest rowne: "<<pole_calkowite_kuli<<endl;
   double objetosc_kuli = (4.0/3.0* pi) * pow(r_2,3.0);// 4/3 * pi *r_2*r_2*r_2
    cout <<"Objetosc kuli o promieniu r jest rowna: "<<objetosc_kuli<<endl;
    return 0;
}