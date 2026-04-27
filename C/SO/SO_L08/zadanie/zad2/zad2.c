#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
// Definicja struktury shm_perm z instrukcji
struct shm_perm
{
    key_t key;
    ushort uid; /* euid i egid właściciela */
    ushort gid;
    ushort cuid; /* euid i egid twórcy */
    ushort cgid;
    ushort mode; /* 9 najmniej znaczących bitów shmflg */
    ushort seq; /* numer porządkowy */      
};
#define SHM_SIZE 100 // Rozmiar segmentu pamięci współdzielonej
int main()
{
    key_t key;
    int shmid;
    char *shm;
    struct shmid_ds shm_info;
    struct shm_perm perm;
    // Generowanie klucza dla segmentu pamięci przy użyciu  funkcji ftok
    key = ftok("zad2.c", 65);
    if (key == -1)
    {
        perror("Błąd funkcji ftok"); // Wypisuje błąd, jeśli generowanie klucza się nie powiedzie
        exit(1);
    }
    /*Tworzenie segmentu pamięci współdzielonej
    hmget: alokuje segment o rozmiarze SHM_SIZE z flagami IPC_CREAT i 0666
    */
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1)
    {
        perror("Błąd shmget"); // Wypisuje błąd, jeśli tworzenie segmentu się nie powiedzie
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
    /*Tworzenie procesu potomnego
    fork: tworzy nowy proces, zwracając PID potomnego lub 0 w potomnym
    */
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("Błąd fork"); // Wypisuje błąd, jeśli tworzenie procesu się nie powiedzie
        exit(1);
    }
    if (pid == 0) // Proces potomny
    {
        sleep(1); // Opóźnienie dla synchronizacji z procesem nadrzędnym
        /*Pobieranie informacji o segmencie pamięci
        shmctl z IPC_STAT: zapisuje informacje o segmencie do shm_info
        */
        if (shmctl(shmid, IPC_STAT, &shm_info) == -1)
        {
            perror("Błąd shmctl"); // Wypisuje błąd, jeśli pobranie informacji się nie powiedzie
            exit(1);
        }
        // Kopiowanie danych do struktury perm
        perm.key = shm_info.shm_perm.__key;
        perm.uid = shm_info.shm_perm.uid; // UID właściciela
        perm.gid = shm_info.shm_perm.gid; // GID właściciela
        perm.cuid = shm_info.shm_perm.cuid; // UID twórcy
        perm.cgid = shm_info.shm_perm.cgid; // GID twórcy
        perm.mode = shm_info.shm_perm.mode & 0777; // Prawa dostępu
        perm.seq = shm_info.shm_perm.__seq; // Numer porządkowy
        // Wyświetlanie informacji o segmencie pamięci
        printf("PID potomnego: %d\n", getpid());
        printf("Informacje o segmencie pamięci współdzielonej:\n");
        printf("Klucz: %d\n", perm.key);
        printf("UID: %u\n", perm.uid);
        printf("GID: %u\n", perm.gid);
        printf("UID twórcy: %u\n", perm.cuid);
        printf("GID twórcy: %u\n", perm.cgid);
        printf("Prawa dostępu: %o\n", perm.mode);
        printf("Rozmiar segmentu: %zu bajtów\n", shm_info.shm_segsz);
        printf("PID ostatniego użycia: %d\n", shm_info.shm_lpid);
        printf("PID twórcy: %d\n", shm_info.shm_cpid);
        printf("Liczba przyłączeń: %ld\n", shm_info.shm_nattch);
        // Odłączanie segmentu pamięci w procesie potomnym
        if (shmdt(shm) == -1)
        {
            perror("Błąd shmdt w potomnym"); // Wypisuje błąd, jeśli odłączenie się nie powiedzie
            exit(1);
        }
        exit(0); // Zakończenie procesu potomnego
    }
    else // Proces nadrzędny
    {
        printf("PID nadrzędnego procesu po shmget: %d\n", getpid());
        sleep(1); // Opóźnienie dla synchronizacji
        wait(NULL); // Czekanie na zakończenie procesu potomnego
        // Odłączanie segmentu pamięci w procesie nadrzędnym
        if (shmdt(shm) == -1)
        {
            perror("Błąd shmdt w procesie nadrzędnym"); // Wypisuje błąd, jeśli odłączenie się nie powiedzie
            exit(1);
        }
        // Usuwanie segmentu pamięci współdzielonej
        // shmctl z IPC_RMID: usuwa segment pamięci
        if (shmctl(shmid, IPC_RMID, NULL) == -1)
        {
            perror("Błąd shmctl IPC_RMID"); // Wypisuje błąd, jeśli usuwanie się nie powiedzie
            exit(1);
        }
        printf("Segment pamięci współdzielonej usunięty\n");
    }
    return 0;
}