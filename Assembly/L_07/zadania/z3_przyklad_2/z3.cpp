#include <iostream>
using namespace std;
extern "C" double srednia_arytmetyczna(float *tab, int n);
int main()
{
    float arr[] = {1.5f, 3.0f, 4.5f, 6.0f, 8.1f, 4.9f, 9.0f};
    int n = 7;
    double result = srednia_arytmetyczna(arr, n);
    cout << "Srednia arytmetyczna (7 elementow) jest rowna: " << result << endl;
    return 0;
}