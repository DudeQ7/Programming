#include <iostream>
/*
Tablice - zadanie 3 - tablica typu char done
Napisz wstawkę asemblerową wyliczającą sumę wartość z elementów tablicy
mniejszych od 5. Tablica składa się z liczb char / int /short int

*/
int main()
{
	char tablica[] = {1,2,3,1,5};
	int n = sizeof(tablica) / sizeof(tablica[0]);
	int suma = 0; 
	__asm
	{
		mov ecx, n; // indeks ecx przechowuje rozmiar pojedynczego elementu tablicy
		mov esi, 0; // indeks esi, przechwouje poczatkowa wartosc indeksu i 
		mov ebx, 0; // ebx, przechowuje poczatkowa wartosc sumy 
	petla:
		cmp esi, ecx; // porownanie indeksu z liczba elementow tablicy
		jge koniec; // jesli indeks jest wiekszy lub rowny liczbie elementow to przeskocz do metody koniec

		mov al, [tablica + esi]; // do indeksu al przypisujemy kolejne indeksy tablicy

		cmp al, 5;//porownanie danego indeksu tablicy z 5'ka
		jge dalej; // jesli dany indeks tablicy jest wiekszy lub rowny 5 to przeskocz do metody dalej
		
		movsx eax, al; // rozszerzamy al do eax  
		add ebx, eax;  // dodajemy do indeksu ebx(poczatkowa wartosc naszej sumy) , indeks naszej tablicy, ktory zostal przypisany do indeksu eeax 
	dalej:
		inc esi; //inc == i++ 
		jmp petla;
	koniec:
		mov suma, ebx; //przypisanie sumy do zmiennej suma
	
	}
	std::cout << "Suma elementow mniejszych niz 5 to: " << suma;
	return 0;
}