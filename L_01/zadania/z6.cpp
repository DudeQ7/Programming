#include <iostream>
/*
Niech i, j, k będą zmiennymi typu short int. Napisz wstawkę asemblerową podstawiającą do zmiennej k
wartość 0 jeżeli i<j, wartość 1 jeżeli i==j, wartość 2 jeżeli i>j.
*/
short int i, j, k;
int main()
{
	i = 8;
	j = 7;
	__asm
	{
		movzx eax, i;
		movzx edx, j;
		cmp edx,eax; //if j ==i
		je rowne;
		jl mniejsze;
		jg wieksze;

		rowne:
			mov k, 1;
			jmp end;
		mniejsze: //i<j
			mov k, 0
			jmp end;
		wieksze://i>j
			mov k, 2;
			jmp end;
		end:
	}
	std::cout << "Wartosc zmiennej k: " << k;
	return 0;
}