#include <iostream>
/*
 Niech i będzie zmienną typu int. Napisz wstawkę asemblerową sprawdzającą czy liczba jest równa zero.
 */
int i,pom_1;

int main()
{
	i = 0;
	__asm
	{
		mov eax, i; //przypiasnie zmiennej i do rejestru eax  
		cmp eax, 0; //if(i>0)
		je Zero;
		mov pom_1, 3; //przypisuje ta wartosc gdy rejestr eax != 0 
		jmp end;
		Zero:
		mov pom_1, 5;
	End:
		
	}
	if (pom_1 == 5)
	{
		std::cout << "Liczba jest rowna 0! ";
	}
	else
	{
		std::cout << "Liczba nie jest rowna 0 "<<std::endl<<"Jest rowna: "<<i;
	}
	
}