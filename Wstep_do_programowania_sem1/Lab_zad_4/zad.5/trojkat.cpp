#include <iostream>
using namespace std;

/*
Napisz klasę narysujTrojkat, zawierająca metodę podajA(), w której użytkownik poda wielkość podstawy
trójkąta równobocznego (wartość nieparzysta) oraz metodę narysuj() – która wyświetli na ekranie trójkąt
równoboczny o podanej podstawie. Użyj pętli for.
*/

class narysujTrojkat {
public:
    int a; 
    void podajA() 
    {
        cout << "Podaj dlugosc podstawy trojkata (nieparzysta liczba): ";
        cin >> a;
        if (a % 2 == 0) 
        {
            cout << "Podano nieprawidlowa liczbe. Podstawa musi byc liczba nieparzysta!" << endl;
        } 
        else 
        {
            cout << "Podano prawidlowa liczbe!" << endl;
        }
    }
    void narysuj() 
    {
        int trojkat_w = (a + 1) / 2; 
        for (int i = 0; i < trojkat_w; i++) 
        {
            for (int j = 0; j < trojkat_w - i - 1; j++) 
            {
                cout << " ";
            }
            for (int j = 0; j < 2 * i + 1; j++) 
            {
                if (i == trojkat_w - 1 || j == 0 || j == 2 * i) 
                {
                    cout << "*";
                } else 
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    narysujTrojkat trojkat;
    trojkat.podajA(); 
    if (trojkat.a % 2 != 0) { 
        trojkat.narysuj(); 
    }
    return 0;
}
