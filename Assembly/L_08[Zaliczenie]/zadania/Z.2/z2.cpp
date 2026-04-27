#include <iostream>

int main()
{
    int tablica[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(tablica) / sizeof(tablica[0]);
    int suma = 0;

    __asm {
        mov ecx, n           ; rozmiar tablicy
        mov esi, 0           ; indeks początkowy
        mov eax, 0           ; początkowa wartość sumy

    petla:
        cmp esi, ecx       ; sprawdź, czy indeks < rozmiar tablicy
        jge koniec         ; jeśli nie, zakończ
        mov ebx, [tablica + esi * 4] ; pobierz element tablicy (int = 4 bajty)
        test ebx, 1        ; sprawdź, czy liczba parzysta (ostatni bit = 0)
        jnz dalej          ; jeśli nieparzysta, pomiń
        add eax, ebx       ; dodaj parzystą liczbę do sumy

    dalej:
        inc esi            ; kolejny indeks
        jmp petla

    koniec:
        mov suma, eax      ; zapisz wynik
    }

    std::cout << "Suma liczb parzystych w tablicy wynosi: " << suma << std::endl;
    return 0;
}