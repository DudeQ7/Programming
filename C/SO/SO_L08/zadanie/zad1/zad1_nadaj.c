#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#define SHM_SIZE 100 // Definiuje rozmiar segmentu pamięci współdzielonej (wystarczający dla tekstu)
int main() 
{
    int shmid; // Identyfikator segmentu pamięci współdzielonej
    char *shm; // Wskaźnik na segment pamięci współdzielonej
    key_t key = 1234; // Klucz do identyfikacji segmentu pamięci (stały dla prostoty)
    // Tworzenie segmentu pamięci współdzielonej
    // shmget: alokuje segment o rozmiarze SHM_SIZE z flagami IPC_CREAT (tworzenie) i 0666 (prawa dostępu)
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) 
    {
        perror("Błąd shmget"); // Wypisuje błąd, jeśli tworzenie segmentu się nie powiedzie
        exit(1); 
    }
    /*Podłączanie segmentu pamięci do przestrzeni adresowej procesu
    shmat: mapuje segment pamięci do przestrzeni adresowej, zwracając wskaźnik
    */
    shm = (char *)shmat(shmid, NULL, 0);
    if (shm == (char *)-1) 
    {
        perror("Błąd shmat"); // Wypisuje błąd, jeśli podłączenie segmentu się nie powiedzie
        exit(1); 
    }
    /*Zapisanie tekstu do pamięci współdzielonej
    strncpy: kopiuje tekst do segmentu pamięci, ograniczając długość do SHM_SIZE
    */
    char *tekst = "pamięć współdzielona 123";
    strncpy(shm, tekst, SHM_SIZE);
    /*Odłączanie segmentu pamięci od przestrzeni adresowej procesu
    shmdt: zwalnia mapping pamięci współdzielonej
    */
    if (shmdt(shm) == -1) 
    {
        perror("Błąd shmdt"); // Wypisuje błąd, jeśli odłączenie segmentu się nie powiedzie
        exit(1); 
    }
    printf("Tekst zapisany do pamięci współdzielonej.\n"); 
    return 0; 
}