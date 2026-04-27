#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double a = 0.1;
    double b = 0.2;
    double c = 0.3;
    double suma = a + b;
    cout << fixed << setprecision(20);
    cout << "a     = " << a << endl;
    cout << "b     = " << b << endl;
    cout << "c     = " << c << endl;
    cout << "a + b = " << suma << endl;
    cout << endl;
    cout << "Czy (a + b == c)? " << (suma == c ? "true" : "false") << endl;
    cout << endl;
    cout << "Roznica |(a+b)-c| = " << fabs(suma - c) << endl;
    double epsilon = 1e-12;
    cout << "Czy sa rowne z tolerancja? "
         << (fabs(suma - c) < epsilon ? "tak" : "nie") << endl;
    cout << endl;
    double duza = 10000000000000000.0; // 10^16
    double mala = 1.0;
    double wynik1 = (duza + mala) - duza;
    double wynik2 = duza - duza + mala;
    cout << "((duza + mala) - duza) = " << wynik1 << endl;
    cout << "(duza - duza + mala)   = " << wynik2 << endl;
    return 0;
}
 