#include <stdio.h>
/*
i
Napisać w języku C program spełniający poniższe wymagania.

• Program jest uruchamiany z dwoma argumentami wejściowymi – liczbami
całkowitymi, których wartości są uporządkowane rosnąco (arg1 < arg2).
o Wywołanie programu z inną liczbą argumentów albo bez argumentów, powinno
skutkować wypisaniem na stdout informacji o przyczynie błędnego wywołania
(„Błędna liczba argumentów”) i zakończeniem pracy z kodem zakończenia
równym -100.
o Wywołanie programu z dwoma argumentami, ale z niepoprawnie
uporządkowanymi wartościami (arg1  arg2), powinno skutkować wypisaniem
na stdout informacji o przyczynie błędnego wywołania („Niepoprawne
uporządkowanie argumentów”) i zakończeniem pracy z kodem zakończenia
równym -200.
• Jeżeli liczba argumentów i ich uporządkowanie jest poprawne program wykonuje się,
uruchamiając proces potomny (funkcja fork()).
• Następnie każdy z procesów (rodzic i potomek) wypisuje na stdout odpowiednią
informację identyfikacyjną.
o Rodzic wypisuje „Rodzic mowi halo” – liczba wypisań tej informacji ma być
równa wartości pierwszego argumentu wywołania programu.
o Potomek wypisuje „Dziecko mowi czesc” – liczba wypisań tej informacji ma
być równa wartości drugiego argumentu wywołania programu. Następnie
potomek kończy działanie z kodem 22.
• Rodzic czeka na zakończenie procesu potomnego, a następnie wypisuje na stdout PID
zakończonego potomka i jego kod zakończenia. Następnie rodzic kończy pracę.
*/
int main(int argc,char* argv[])
{
    printf("You have entered %d arguments\n",argc);
    for(int i = 0; i<argc; i++)
    {
        printf("%s\n",argv[i]);
    }
    if(argc ==2 )
    {
        printf("Podales poprawna ilosc argumentow!\n")
    }
    else if (argc==1)
    {
        printf("Podales tylko jeden argument!\n")
    }
    else
    {
        printf("Podales niewlasciwe argumenty sprobouj jeszcze raz!\n")
    }
    
    
    return 0;
}