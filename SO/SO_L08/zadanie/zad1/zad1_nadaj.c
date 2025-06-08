#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#define SHM_SIZE 100 // Rozmiar segmentu pamięci współdzielonej (wystarczy na nasz tekst)
int main() 
{
    int shmid; // Identyfikator segmentu pamięci współdzielonej
    char *shm; // Wskaźnik na segment pamięci
    key_t key = 1234; // Klucz do identyfikacji segmentu pamięci
    // Tworzenie segmentu pamięci współdzielonej
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) 
    {
        perror("Błąd shmget");
        exit(1);
    }
    // Podłączanie segmentu pamięci do przestrzeni adresowej procesu
    shm = (char *)shmat(shmid, NULL, 0);
    if (shm == (char *)-1) 
    {
        perror("Błąd shmat");
        exit(1);
    }
    // Zapisanie tekstu do pamięci współdzielonej
    char *tekst = "pamięć współdzielona 123";
    strncpy(shm, tekst, SHM_SIZE);
    // Odłączanie segmentu pamięci
    if (shmdt(shm) == -1) 
    {
        perror("Błąd shmdt");
        exit(1);
    }
    printf("Tekst zapisany do pamięci współdzielonej.\n");
    return 0;
}