#include <iostream>
extern "C" double pole_okregu(double R);
int main()
{
    double R = 5.0;
    double wynik = pole_okregu(R);
    std::cout << "Promien: " << R << "\nDlugosc okregu: " << wynik << std::endl;
    return 0;
}