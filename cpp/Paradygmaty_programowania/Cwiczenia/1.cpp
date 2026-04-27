#include <iostream>
using namespace std;
 
class Punkt
{
public:
    int x;
    Punkt(int x) : x(x) {}
};
 
void zmienWartosc(Punkt p)
{
    p.x = 100;
}
 
void zmienReferencja(Punkt& p)
{
    p.x = 200;
}
 
int main()
{
    Punkt p(10);
 
    zmienWartosc(p);
    cout << p.x << endl; // 10
 
    zmienReferencja(p);
    cout << p.x << endl; // 200
 
    return 0;
}