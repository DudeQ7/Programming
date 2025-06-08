#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#define SHM_SIZE 100 // Rozmiar segmentu pamięci współdzielonej
int main() 
{
    int shmid; // Identyfikator segmentu pamięci współdzielonej
    char *shm; // Wskaźnik na segment pamięci
    key_t key = 1234; // Ten sam klucz, co w nadaj.c
    // Uzyskanie dostępu do istniejącego segmentu pamięci współdzielonej
    shmid = shmget(key, SHM_SIZE, 0666);
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
    // Odczytanie i wyświetlenie zawartości pamięci współdzielonej
    printf("Odczytano z pamięci współdzielonej: %s\n", shm);
    // Odłączanie segmentu pamięci
    if (shmdt(shm) == -1) 
    {
        perror("Błąd shmdt");
        exit(1);
    }
    // Usuwanie segmentu pamięci współdzielonej
    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("Błąd shmctl");
        exit(1);
    }
    return 0;
}