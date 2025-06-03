#include <iostream>

extern "C" int iloczyn_mniejszych(int* tablica, int rozmiar, int K);

int main() {
    //int tablica[6] = { 6, 4, 3, 2, 10, 1 };
    int tablica[7] = {1,3,4,6,8,4,9};
    int K;
    std::cout << "Podaj wartosc K: ";
    std::cin >> K;
   

    int wynik = iloczyn_mniejszych(tablica, 6, K);

    std::cout << "Iloczyn wartosci mniejszych od " << K << " wynosi: " << wynik << "\n";

    return 0;
}
