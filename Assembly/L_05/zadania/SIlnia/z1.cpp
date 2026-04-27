#include <iostream>
int n;
extern "C" int silnia(int n);
int main() {
    std::cout << "Podaj liczbe, ktorej silnie chcesz obliczyc: ";
    std::cin >> n;
    int wynik = silnia(n);
    std::cout << "Silnia z " << n << " = " << wynik << std::endl;
    return 0;
}
