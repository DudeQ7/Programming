#include <stdio.h>

int main() {
    short int i = 300, j = 200, k;

    __asm__(
        "movw %1, %%ax;"   // Przenieś wartość i do ax
        "movw %2, %%bx;"   // Przenieś wartość j do bx
        "addw %%bx, %%ax;" // Dodaj ax i bx, wynik w ax
        "andw $255, %%ax;" // Zastosuj modulo 256
        "movw %%ax, %0;"   // Przenieś wynik do k
        : "=r" (k)         // Wyjście: zmienna k
        : "r" (i), "r" (j) // Wejście: zmienne i, j
        : "%ax", "%bx"     // Rejestry ax i bx są używane
    );

    // Wyświetl wynik
    printf("Wartość zmiennej k: %d\n", k);

    return 0;
}
