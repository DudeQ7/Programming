#include <iostream>
extern "C" double wyrazenie_a(double a, double b, double c, double d, double e, double f, double g);
int main()
{
    double wynik = wyrazenie_a(2.34, 1.75, 373, 1.735, 97, 6.33, 3.14);
    std::cout << "a=" << 2.34 << ", b=" << 1.75 << ", c=" << 373.0 << ", d=" << 1.735 << ", e=" << 97.0 << ", f=" << 6.33 << ", g=" << 3.14 << std::endl;
    std::cout << "\nWynik to: " << wynik << std::endl;
    return 0;
}