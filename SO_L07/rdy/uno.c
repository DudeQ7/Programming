#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Podales bledna liczbe argumentow\n");
        return -100;
    }

    int arg_1 = atoi(argv[1]);
    int arg_2 = atoi(argv[2]);

    if (arg_1 >= arg_2) {
        printf("Niepoprawne uporzadkowanie argumentow\nSprobuj jeszcze raz!\n");
        return -200;
    }

    pid_t proces = fork();

    if (proces < 0) {
        printf("Blad przy wywolaniu funkcji fork!\n");
        return -1;
    }
    else if (proces == 0) {
        // Proces potomny – dziecko
        for (int i = 0; i < arg_2; i++) {
            printf("Dziecko mowi czesc\n");
            usleep(50000); 
        }
        return 22;
    }
    else {
        for (int i = 0; i < arg_1; i++) {
            printf("Rodzic mowi halo\n");
            usleep(50000); 
        }

        int status;
        pid_t dziecko_proces = wait(&status);
        if (WIFEXITED(status)) {
            int exit_code = WEXITSTATUS(status);
            printf("Dziecko STOP: PID = %d\n", dziecko_proces);
            printf("Dziecko EXIT: CODE = %d\n", exit_code);
        }
    }

    return 0;
}
