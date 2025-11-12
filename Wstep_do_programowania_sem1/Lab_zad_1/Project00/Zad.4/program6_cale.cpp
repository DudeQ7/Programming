#include <iostream>
using namespace std;
//cale do cm
int main(){
    double wybor;
    cout <<"Program zostal przygotowany przez Pawla Dutkiewicza"<<endl<<"Progam zostal przygotowany dnia 28 pazdziernika 2024"<<endl;
    cout << "Podaj dlugosc wyrazona w calach: ";
    cin >> wybor;
    double centymetry = wybor * 2.54;
    cout <<"Podana dlugosc wynosi : "<<centymetry<<" centymetrow" << endl;
    
    return 0;
}