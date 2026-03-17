// a) Dyrektywy preprocesora
#include <iostream> 
#include <string>
// b) Funkcja główna
int main() {
    // d) Typy iterałów:
    int liczba = 10;              // Iterał całkowity 
    double cena = 1.50;           // Iterał zmiennoprzecinkowy 
    char znak = 'A';              // Iterał znakowy 
    std::string tekst = "Cześć";  // Iterał łańcuchowy 
    bool logiczny = true;         // Iterał logiczny 
    // e) Output programu (wyjście)
    std::cout << "Podaj swoj wybor: "; 
    // c) Instrukcja 
    int wybor;
    // e) Input programu (wejście)
    std::cin >> wybor;
    // Kolejna instrukcja (przypisania)
    liczba = wybor + 5;
    return 0;
}