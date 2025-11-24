#include <iostream>
/*
IF Ćwiczenie 2
Napisz program, w którym bedziesz dzielil dwie zmienne typu float i wyswietlał wynik. Użyj instrukcji IF do uniemożliwienia operacji dzielenia przez 0.*/
using namespace std;
float a = 10.0;
float b = 15.0;
float c = b /a ;
int main() {
     if ((a or b) == 0){
            cout <<"Nie dziel cholero przez 0";
     }
     else{
        cout <<"Wynik dzielenia to: "<< c;
     }
    return 0;
}
