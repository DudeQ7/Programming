#include <iostream>
/*
 Niech i, j, k będą zmiennymi typu int. Napisz wstawkę asemblerową wykonującą operację k=i+j. Użyj
rejestrów eax i ebx
*/
int main()
{
    int i, j, k;
    __asm
    {
        mov i, 15;
        mov j, 10;
        mov eax, i;
        mov ebx, j;
        add eax, ebx;
        mov k, eax;
      
    }
    std::cout << k;
    return 0;
}