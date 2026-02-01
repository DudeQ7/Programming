#include <deque>
#include <iostream>
/*
Ćwiczenie 4 
Zastosowanie metod erase, insert, resize. 
1. Utwórz deque<int> zawierający liczby od 1 do 10. 
2. Usuń: 
a. jeden wybrany element ze środka kontenera, 
b. zakres pierwszych trzech elementów. 
3. Wstaw nowy element w środku kontenera. 
4. Zmień rozmiar kontenera: 
a. zmniejsz go do 5 elementów, 
b. następnie zwiększ do 8 elementów (nowe elementy ustaw na 0)
*/
int main()
{
    std::deque <int> k1;
    for(int i=1; i<=10; i++)
    {
        k1.push_back(i);
        std::cout<<"elementy: "<<k1.at(i-1)<<std::endl;
    }
    std::cout<<"Usuwanie 1 elementu z srodku";
    k1.erase(k1.begin() +4);
    std::cout<<"\nElementy po usunieciu: "<<std::endl;
     for(int i=0; i<k1.size(); i++)
    {
        std::cout<<"elementy: "<<k1.at(i)<<std::endl;
    }
    std::cout<<"Usuwanie 3 pierwszych elementow: ";
    k1.erase(k1.begin(),k1.begin()+3);
     std::cout<<"\nElementy po usunieciu: "<<std::endl;
      for(int i=0; i<k1.size(); i++)
    {
        std::cout<<"elementy: "<<k1.at(i)<<std::endl;
    }
    std::cout<<"Dodanie elementu od srodka";
    std::deque<int>::iterator it =k1.begin() +5;
    k1.insert(it,777);
     std::cout<<"\nElementy po dodaniu elementu: "<<std::endl;
    for(int i=0; i<k1.size(); i++)
    {
        std::cout<<"elementy: "<<k1.at(i)<<std::endl;
    }
    std::cout<<"Zmniejszenie struktury do 5 elementow: "<<std::endl;
    k1.resize(5); //nie dziala 
      for(int i=0; i<k1.size(); i++)
    {
        std::cout<<"elementy: "<<k1.at(i)<<std::endl;
    }
    std::cout<<"Zwiekszenie struktury do 8 elementow"<<std::endl;
    k1.resize(8,0);
       for(int i=0; i<k1.size(); i++)
    {
        std::cout<<"elementy: "<<k1.at(i)<<std::endl;
    }
    return 0;
}