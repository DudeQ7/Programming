#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#define N 6 //rozmiar bufora B1
#define SHM_Key 1234 //klucz dla pamieci wspoldzielonej
#define SEM_Key 5678 //Klucz do semaforów
/*
nazwa procesu,  stan,    stan bufora 
Even,   in_crit_B1,  2. 
Even,   in_crit_B1,  4. 
Get3Numbers,  wait_B1,  - 
Even,   in_crit_B1,  6. 
Get3Numbers,  in_crit_B1,  2, 4, 6. 
Get3Numbers,  write_out: 12 
Even,   in_crit_B1,  8.
*/
//bufor cykliczny - stala niezmieniajaca polozenia tablica 
//struktura buforu cyklicznego:
typedef struct
{
    int buffer[N];
    int in;//zapis
    int out;//odczyt
}CircularBuffer;
//Unia potrzebne do dzialan na semaforach:
union semun 
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};
//glboal id
int shmid,semid;
CircularBuffer *cb;
//operacje na semaforach
void sem_op(int semid,int sem_num,int op)
{
    struct sembuf sb ={sem_num,op,0};
    if(semop(semid,&sb,1) == -1)
    {
        perror("Operacja na semaforach");
        exit(1);
    }
}
//obsluga ctrl+c , zgodnie z wymaganiami
void cleanup(int signum)
{
    printf("\nZakonczenie projektu przez CTRL + C ");
    shmdt(cb);
    shmctl(shmid,IPC_RMID,NULL);
    semctl(semid,0,IPC_RMID);
    exit(0);
}
//produkcja liczb parzystych
void even_process()
{
    int number = 2;
    while(1)
    {
        sem_op(semid,1,-1); //oczekiwanie na wolne miejsce[empty]
        sem_op(semid,2,-1); //sekcja krytyczna[mutex]
        cb->buffer[cb->in] = number;
        printf("Even, in crit B1, :%d.\n",number);
        cb->in = (cb->in +1)%N;
        sem_op(semid,2,1);
        sem_op(semid,0,1);
        number += 2;
        sleep(1);
    }
}
//pobiera 3 elementy i lcizy sume
void get3numbers_process()
{
    while(1)
    {
        printf("Get3Numbers, wait B1, -.\n");
        sem_op(semid,0,-3); //czeka na 3 elementy
        sem_op(semid,2,-1); //wejscie do sekcji krytycznej
        int num1 = cb->buffer[cb->out];
        cb->out =(cb->out +1) % N;
        int num2 = cb->buffer[cb->out];
        cb->out =(cb->out +1) % N;
        int num3 = (cb->buffer[cb->out]);
        cb->out =(cb->out +1) % N;
        printf("Get3Numbers in crit B1: %d,%d,%d.\n",num1,num2,num3);
        printf("Get3Numbers, write_out: %d\n",num1+num2+num3);
        sem_op(semid,2,1); //wyjscie z sekcji krytycznej
        sem_op(semid,1,3); //zwolnij 3 miejsca
        sleep(1);
    }
}
int main()
{
    //obsluga CTRL+C
    signal(SIGINT,cleanup);
    //tworzenie pamieci wspoldzielonej
    shmid = shmget(SHM_Key,sizeof(CircularBuffer),IPC_CREAT|0666);
    if(shmid == -1 )
    {
        perror("shmget");
        exit(1);
    }
    //pamiec wspoldzielona
    cb =(CircularBuffer *) shmat(shmid,NULL,0);
    if(cb == (void *) -1)
    {
        perror("shmat");
        exit(1);
    }
    //bufor 
    cb->in =0;
    cb->out =0;
    memset(cb->buffer,0,sizeof(cb->buffer));
    //tworzenie semaforow[0:full,1:empty,2:mutex]
    semid = semget(SEM_Key,3,IPC_CREAT |0666);
    if(semid == -1)
    {
        perror("semget");
        exit(1);
    }
    //inicjalizacja semaforow
    union semun arg;
    arg.val = 0; //full = 0
    semctl(semid,0,SETVAL,arg);
    arg.val = N; //empty = N
    semctl(semid,1,SETVAL,arg);
    arg.val = 1; //mutex =1
    semctl(semid,2,SETVAL,arg);
    //tworzenie procesu even 
    pid_t pid = fork();
    if(pid == -1)
    {
        perror("fork");
        exit(1);
    }
    if(pid == 0 )
    {
        even_process();
        exit(0);
    }
    //get 3 numbers 
    pid = fork();
    if(pid == -1)
    {
        perror("fork");
        exit(1);
    }
    if(pid==0)
    {
        get3numbers_process();
        exit(0);
    }
    //czekanie na procesy potomne
    while(wait(NULL)>0);
    cleanup(0);
    return 0;
}