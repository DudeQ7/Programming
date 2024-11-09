#include <iostream>
/*
IF Ćwiczenie 3
Napisz program, w którym user podaj dwie zmienne (int liczba1, int liczba2). Napisz metodę, która wyświetli - która zmienna jest większa i o ile.
 
np.
	liczba1 = 5
	liczba2 = 7
odpowiedz:
	wieksza jest druga liczba o 2
*/
using namespace std;
int liczba1, liczba2;
int main() {
    cout << "Podaj watosc pierwszej zmiennej: ";
    cin >> liczba1 ;
    cout << "Podaj watosc drugiej zmiennej: ";
    cin >> liczba2 ;
    if (liczba1 > liczba2){
        int wynik1 = liczba1 - liczba2;
        cout << "wieksza jest liczba pierwsza o: "<<wynik1;
    }
    else {
        int wynik2 = liczba2 - liczba1;
        cout << "wieksza jest liczba druga o: "<<wynik2;
    }
    return 0;
}
