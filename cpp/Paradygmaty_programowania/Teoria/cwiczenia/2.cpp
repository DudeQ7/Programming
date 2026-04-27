// for (int x : tab) tworzy kopię
// int x : tab oznacza pracę na kopii elementu.
// int& x : tab oznacza pracę na oryginalnym elemenciez.
 
#include <iostream>
using namespace std;
 
int main()
{
    int tab[] = {1, 2, 3, 4};
 
    cout << "Stan poczatkowy:"<<endl;
    for (int x : tab)
        cout << x << " ";
    cout << '\n';
 
    for (int x : tab)
        x *= 10;
 
    cout << "Po petli przez wartosc:"<<endl;
    for (int x : tab)
        cout << x << " ";
    cout << '\n';
 
    for (int& x : tab)
        x *= 10;
 
    cout << "Po petli przez referencje:"<<endl;
    for (int x : tab)
        cout << x << " ";
    cout << '\n';
 
    return 0;
}