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

    /*Uzyskanie dostępu do istniejącego segmentu pamięci współdzielonej
    shmget: uzyskuje identyfikator segmentu o podanym kluczu i rozmiarze
    */
    shmid = shmget(key, SHM_SIZE, 0666);
    if (shmid == -1) 
    {
        perror("Błąd shmget"); // Wypisuje błąd, jeśli segment nie istnieje
        exit(1);
    }
    /*Podłączanie segmentu pamięci do przestrzeni adresowej procesu
    shmat: mapuje segment do przestrzeni adresowej, zwracając wskaźnik
    */
    shm = (char *)shmat(shmid, NULL, 0);
    if (shm == (char *)-1) 
    {
        perror("Błąd shmat"); // Wypisuje błąd, jeśli podłączenie się nie powiedzie
        exit(1);
    }
    /*Odczytanie i wyświetlenie zawartości pamięci współdzielonej
    printf: wypisuje tekst zapisany w segmencie pamięci
    */
    printf("Odczytano z pamięci współdzielonej: %s\n", shm);
    /*Odłączanie segmentu pamięci
    shmdt: zwalnia mapping pamięci współdzielonej
    */
    if (shmdt(shm) == -1) 
    {
        perror("Błąd shmdt"); // Wypisuje błąd, jeśli odłączenie się nie powiedzie
        exit(1);
    }
    /*Usuwanie segmentu pamięci współdzielonej
    shmctl z IPC_RMID: usuwa segment pamięci
    */
    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("Błąd shmctl"); // Wypisuje błąd, jeśli usuwanie się nie powiedzie
        exit(1);
    }
    return 0;
}