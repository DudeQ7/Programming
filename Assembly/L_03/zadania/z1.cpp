#include <iostream>
#include <stdio.h>
/* Niech będzie dana zmienna i typu int. Napisz wstawkę asemblerową przypisującą zmiennej i wartość 10.
Użyj rejestru eax */

int main()
{
	int i = 10;
	__asm
	{
		mov eax, 10;
		mov i, eax;
	}
	std::cout <<i;
	return 0;
}