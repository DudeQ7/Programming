#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
//definicja struktury przekopiowana z instrukcji
struct shm_perm
{
    key_t key;
    ushort uid; /*euid i egid wlascicela*/
    ushort gid;
    ushort cuid; /*euid i egid twórcy*/
    ushort cgid;
    ushort mode; /*9 najmniej znaczących bitów shmflg*/
    ushort seq; /* numer porządkowy*/      
};
#define SHM_SIZE 100 //Rozmiar segmentu pamieci wspoldzielonej
int main()
{
   key_t key;
   int shmid;
   char *shm;
   struct shmid_ds shm_info;
   struct shm_perm perm;
    key = ftok("zad2.c",65);
    if(key == -1)
    {
        perror("Blad funkcji ftok");
        exit(1);
    }
    //tworzenie segmentu pamieci wspoldzielonej
    shmid = shmget(key,SHM_SIZE,IPC_CREAT | 0666); //prev value 0777
    if(shmid == -1)
    {
        perror("Blad shmget");
        exit(1);
    }
    //podlaczanie segmentu pamieci do przestrzeni adresowej
    shm =(char *)shmat(shmid,NULL,0);
    if(shm == (char *)-1)
    {
        perror("Blad shmat");
        exit(1);
    }
    pid_t pid = fork();
    if(pid == -1)
    {
        printf("Blad fork'u");
        exit(1);
    }
    if(pid ==0)
     
    //pobieranie informacji o segmencie pamieci
    {
    sleep(1);   //opoznienie dla synchronizacji
        if(shmctl(shmid,IPC_STAT,&shm_info)==-1)
        {
            perror("Blad shmctl");
            exit(1);
        }
        perm.key = shm_info.shm_perm.__key;
        perm.uid = shm_info.shm_perm.uid; //uid wlascicela
        perm.gid = shm_info.shm_perm.gid; //gid wlasciciela
        perm.cuid = shm_info.shm_perm.cuid; //uid tworcy obszaru
        perm.cgid = shm_info.shm_perm.cgid; //gid tworcy
        perm.mode = shm_info.shm_perm.mode & 0777; //praw dostepu 
        perm.seq  = shm_info.shm_perm.__seq; //numer porzadkowy
        //wyswietlanie informacji
        printf("PID potomnego: %d\n",getpid());
        printf("Informacje o segmencie pamieci wspoldzielonej:\n");
        printf("Klucz: %d\n",perm.key);
        printf("UID: %u\n",perm.uid);
        printf("GUID: %u\n",perm.gid);
        printf("UID tworcy: %u\n",perm.cuid);
        printf("GID tworcy: %u\n",perm.cgid);
        printf("Prawa dostepu: %o\n",perm.mode);
        printf("Rozmiar segmentu: %zu bajtow\n",shm_info.shm_segsz);
        printf("PID ostatniego uzycia: %d\n",shm_info.shm_lpid);
        printf("PID tworcy: %d\n",shm_info.shm_cpid);
        printf("Liczba przylaczen: %ld\n",shm_info.shm_nattch);
        if(shmdt(shm)== -1)
        {
            perror("Blad shmdt w potomnym");
            exit(1);
        }
        exit(0);
    } //ten srednik jest unlikely
    else
    {   printf("PID nadrzednego procesu po shmget: %d\n",getpid());
        sleep(1); //opoznienie dla aktualizacji
        wait(NULL); // czekanie na zakonczenie procesu potomnego
        if(shmdt(shm)==-1)
        {
            perror("Blad shmdt w procesie nadrzednym");
            exit(1);
        }
        //usuwanie segmentu pamieci
        if(shmctl(shmid,IPC_RMID,NULL)==-1)
        {
            perror("Blad shmctl IPC_RMID");
            exit(1);
        }
        printf("Segment pamieci wspoldzielonej usuniety\n");
    }
    return 0;
}