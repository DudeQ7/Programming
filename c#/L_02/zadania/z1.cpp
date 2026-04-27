#include <iostream>
/*
Pętla - zadanie 1
Niech i, k będą zmiennymi typu short int. Napisz wstawkę
asemblerową liczącą w pętli sumę liczb 1,2,3,...,i.
Zapisz tą liczbę w zmiennej k
Zrobione 
*/
int i, k;

int main()
{
	i = 10, k = 0;
	__asm
	{
		mov eax, 0;
		mov ecx, i;
		mov edx, 0;
	poczatek:
		add edx, ecx;
		loop poczatek;
		mov k, edx;
	}
	std::cout << "Zmienna k jest rowna: " << k << std::endl;
	return 0;
}