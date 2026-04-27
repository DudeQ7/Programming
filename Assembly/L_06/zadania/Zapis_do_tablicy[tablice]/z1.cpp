#include <iostream>
//program zapisujacy do tablicy kolejne liczby naturalne od 1 do 10 
int tablica[10];
int n = sizeof(tablica) / sizeof(tablica[0]);
int k = 1; // nasza liczb naturalna
int cond = 0; //zmienna potrzebna do naszego for'a
int main()
{
	__asm
	{
		mov esi, 0; //startowy indeks tablicy
		mov eax, 1;//pierwsza liczba naturalna , ktora bedziemy inkrementowac
		mov ecx, n; //rozmiar naszej tablicy
	petla:
		cmp esi, ecx;
		jge koniec; // sprawdzamy czy indeks tablicy, nie przekroczyl rozmiaru tablicy
		mov[tablica + esi * 4], eax; //przypisujemy do tablicy wartosc liczby naturalnej do tablicy
		inc eax; //zwiekszamy liczbe naturalna
		inc esi; // zwiekszamy indeks
		jmp petla; // wykonujemy petle ponownie
	koniec:
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Element tablicy numer: " << i << " to:" << tablica[i]<<std::endl;
	}

	return 0;
}