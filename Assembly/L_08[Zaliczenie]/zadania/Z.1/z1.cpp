#include <iostream>
/*
funkcja ktora obliczy wartosc int , wartosc funkcja x^3 + 2x +1
x =1
*/
int x = 1, wynik;
int main()
{
    __asm
    {

		mov eax, x; // przypisanie do eax , x  
		mov ebx, eax; // przypisanie do ebx eax || ebx = x 
		imul eax, eax // x^2
		imul eax, ebx         // x^3
		mov ecx, ebx // przypisanie wyniku x^3
		mov edx, 2 // przypisanie wartosci 2 do rejestru edx 
		imul ecx, edx;        // mnozenie x^3 * 2 
		add eax,ecx  // zsumowanie x^3 do eax 
		add eax,1 // dodanie 1 do wyniku
		mov wynik, eax         // przypisanie wyniku do zmiennej
    }
    std::cout << "Wartosc przechowywana w rejestrze  ecx to: " << wynik;
    return 0;
}