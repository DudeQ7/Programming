/*
Napisz program, w którym stworzysz zmienne całkowite a1 i a2 (int)
Użytkownik podaje ich wartości.
Wykonaj działania i wyświetl ich wyniki
wynik=a1+a2
wynik=++a1 + ++a2 done
wynik=a1-a2 done
wynik=a1-- + --a2 done
wynik=a1+a2  done 
wynik=a1-- + ++a2 done
// Stwórz zmienne: 
zm1=10;
zm2=20;
// wykonaj polecenie:
cout<<"1 zm1="<<++zm1<<endl;
cout<<"2 zm1="<<zm1++<<endl;
cout<<"3 zm1="<<zm1<<endl;
cout<<"4 zm2="<<zm2<<endl;
cout<<"5 zm2="<<zm2--<<endl;
cout<<"6 zm2="<<--zm2<<endl;
cout<<"7 zm2="<<zm2--<<endl;
cout<<"8 zm2="<<zm2<<endl;
 */

#include <iostream>
using namespace std;
int main(){
    int a1 , a2;
    cout <<"Podaj wartosc a1: "<<endl;
    cin >>a1;
    cout <<"Podaj wartosc a2: "<<endl;
    cin >>a2;
    cout <<"wynik 1: "<<a1 +a2<<endl;
    cout <<"wynik 2: "<<++a1 + ++a2<<endl;
    cout <<"wynik 2: "<<a1 - a2<<endl;
    cout <<"wynik 3: "<<--a1 + --a2<<endl;
    cout <<"wynik 4: "<<++a1 + ++a2<<endl;
    cout <<"wynik 5: "<<--a1 + ++a2<<endl;
    int zm1=10,zm2=20;
    cout<<"1 zm1="<<++zm1<<endl;
    cout<<"2 zm1="<<zm1++<<endl;
    cout<<"3 zm1="<<zm1<<endl;
    cout<<"4 zm2="<<zm2<<endl;
    cout<<"5 zm2="<<zm2--<<endl;
    cout<<"6 zm2="<<--zm2<<endl;
    cout<<"7 zm2="<<zm2--<<endl;
    cout<<"8 zm2="<<zm2<<endl;

    
    return 0;
}