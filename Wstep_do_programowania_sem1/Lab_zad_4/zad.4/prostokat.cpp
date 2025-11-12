#include <iostream>
/*
Napisz klasę narysujProstokąt, zawierającą metodę rysuj(), która wyświetli na ekranie prostokąt o
wymiarach podanych w metodzie podajxy(). Użyj pętli for.
Przykład – prostokat o wymiarach 5 i 8
********
*      *
*      *
*      *
********
*/
/*
            cout << "Podaj wartosc x: ";
            cin >> x;
            cout << "\nPodaj wartosc y: ";
            cin >> y; 
*/

using namespace std;
class prostokat
{
    public:
    int x,y;
        void podajxy()
        {
            cout <<"Podaj wartosc: x - ";
            cin >> x;
            cout<<"\nPodaj wartosc: y - ";
            cin >> y;
            cout<<endl;
                if(x>0&&y>0)
                {
                    cout <<"Podales poprawne liczby: "<<endl;
                }
                else
                {
                    cout <<"Podales niepoprawne liczby: ";
                }
        }
        void rysuj()
        {
            for (int i = 0; i<y; i++)
            {
                cout <<"*";
                       
            }
            cout <<endl;
            for (int j=0; j<x-2; j++)
            {
                cout<<"*";
                 for(int k=0; k<y-2; k++)
                {
                    cout<<" ";
                } 
            cout << "*";
            cout <<endl;
            }
              for (int i = 0; i<y; i++)
            {
                cout <<"*";
                       
            }
        }                  
};
int main() {
    prostokat zad;
    zad.podajxy();
    zad.rysuj();
    return 0;
}
