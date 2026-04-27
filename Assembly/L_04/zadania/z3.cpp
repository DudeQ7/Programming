#include <iostream>
/*
Zadanie 4 - tablica typu  short int
Napisz wstawkę asemblerową wyliczającą ile razy w tablicy TAB występuje
element EL. Wynik zapisz do zmiennej k typu short int
*/
int main()
{
	
	short int tablica[] = {1,2,5,5,5};
	short int EL = 5;
	short int k = 0; // zmienna przechowuje ile razy wystepuja szukana zmienna EL
	int n = sizeof(tablica) / sizeof(tablica[0]);
	__asm
	{
		mov ecx, n; // indeks EXC przechowuje liczbe elementow w tablicy
		mov esi, 0; // przypisujemy indeksowi ESI poczatkowa wartosc 0 
		mov ax, EL; //przypisujemy indeksowi AX , szukana wartosc ze zmiennej EL 
		mov bx, 0; //przypisujemy indeksowi bx , liczbe wystapien k 
	petla:
		cmp esi, ecx; // porownujemy indeks i liczbe elementow z tablicy
		jge koniec; // jesli indeks bedzie wiekszy od liczby elementow, to skrypt przeskoczy do metody koniec
		movsx eax, [tablica + esi * 2]; //instrukcja jest zapisana w ten sposob poniewaz kazdy element tablicy typu short int zajmuje 2 bajty, wiec aby przejsc do kolejnego elementu to musimy przeskoczyc o 2 bajty 
		cmp ax, EL; //porowonujemy dany indeks z szukana wartoscia ze zmiennej EL;
		jne dalej; //jesli element nie jest rowny EL to go pomijamy
		inc bx; // jesli jest rowny to zwiekszamy wartosc indeksu bx o 1 
	dalej:
		inc esi; //zwiekszamy wartosc indeksu o 1 by przeskoczyc do kolejnego elementu
		jmp petla; // wracamy do petli
	koniec:
		mov k, bx; //przypisujemy do zmiennej k, liczbe ile razy wystapila nasza wartosc ze zmiennej EL
	}
	std::cout << "W podanej tablicy, liczba o wartosci takiej samej jak zmienna EL , pojawila sie: " << k <<" razy"<< std::endl;
	return 0; 
}