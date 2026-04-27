#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char* argv[])
{ 

    //sprawdzenie liczby argumentów podanych przez uzytkownika, powinny byc 3: nazwa programu + 2 liczby
    if (argc != 3) {
        printf("Podales bledna liczbe argumentow\n");
        return -100;
    }
    int arg_1 = atoi(argv[1]);
    int arg_2 = atoi(argv[2]);
    //sprawdzenie czy arg_1 musi byc mniejsze niz arg_2
    if (arg_1 >= arg_2) {
        printf("Niepoprawne uporzadkowanie argumentow\nSprobuj jeszcze raz!\n");
        return -200;
    }
    //tworzenie procesu potomka dzieki funkcji fork
    pid_t proces = fork();

    if (proces < 0) {
        printf("Blad przy wywolaniu funkcji fork!\n");
        return -1;
    }
    else if (proces == 0) {
        // Proces potomny , ktory wypisuje dziecko mowi czesc , w zaleznosci od wartosci arg_2
        for (int i = 0; i < arg_2; i++) {
            printf("Dziecko mowi czesc\n");
            usleep(50000); //opoznienie 50ms zeby komunikaty zostaly wyswietlone w sposob identyczny jak w przykladzie
        }
        return 22; //kod zakonczenia potomka
    }
    else {
        //proces rodzica, ktory wypisuje Rodzic mowi halo razy w zaleznosci od wartosci arg_1
        for (int i = 0; i < arg_1; i++) {
            printf("Rodzic mowi halo\n");
            usleep(50000);  //opoznienie 50ms dla przeplatania komunikatow 
        }
        //oczekiwanie na zakonczenie procesu potomka, i pobranie jego statusu
        int status;
        pid_t dziecko_proces = wait(&status);
        int exit_code = WEXITSTATUS(status);

        if (WIFEXITED(status)) {
            printf("Dziecko STOP: PID = %d\n", dziecko_proces);
            printf("Dziecko EXIT: CODE = %d\n", exit_code);
        }
    }
    return 0;
}
