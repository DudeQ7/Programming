#include <iostream>
//Niech i, k będą zmiennymi typu short int.Napisz wstawkę asemblerową przypisującą do zmiennej k sumę
//starszego i młodszego bajtu zmiennej i.
short int k, i;
int main()
{
    __asm
    {
        mov ax, i; //16 bitowa zmienna(short int) I  --> rejestru ax 
        mov bl, al; //przekopiwoanie mlodszego bajtu z rej. AL do bl 
        shr ax, 8; //przesuniecie ax o 8 bitow w prawo, by dostac starszy bajt
        add bl, al; // sumowanie mlodszego i starszego bajtu 
        movzx ax, bl; //uzupeniamy zerami nasza instrukcje 
        mov k, ax; // przypisanie wyniku do zmiennej k 
    }

    std::cout <<"wynik to :"<< k;
    return 0;
}