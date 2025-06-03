#include <iostream>
/*Niech i, j, k będą zmiennymi typu short int. Napisz wstawkę asemblerową wykonującą operację
k= (i+j) % 256
*/
short int k, i, j; //te rejestry konfliktuja z typem short int 
int main()
{
    __asm
    {
        mov i, 10; 
        mov j, 15; 
        movzx eax, i; 
        movzx edx, j; 
        add eax, edx; 
        and eax, 255; 
        mov k, ax; 

    }
    std::cout << k;
    return 0;
}