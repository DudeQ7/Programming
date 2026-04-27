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
#define M 3 //rozmiar buforu B2
#define SHM_Key_B1 1234 //klucz dla pamieci wspoldzielonej B1
#define SHM_Key_B2 1235 //klucz do pamieci wspoldzielonej B2
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
}CircularBufferB1;
typedef struct
{
    int buffer[M];
    int in;
    int out;
}CircularBufferB2;
//Unia potrzebne do dzialan na semaforach:
union semun 
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};
//glboal id
int shmid_b1,shmid_b2,semid;
CircularBufferB1 *cb1;
CircularBufferB2 *cb2;
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
    printf("\nZakonczenie programu przez CTRL + C ");
    shmdt(cb1);
    shmdt(cb2);
    shmctl(shmid_b1,IPC_RMID,NULL);
    shmctl(shmid_b2,IPC_RMID,NULL);
    semctl(semid,0,IPC_RMID);
    exit(0);
}
//produkcja liczb parzystych
void even_process()
{
    int number = 2;
    while(1)
    {
        sem_op(semid,1,-1); //oczekiwanie na wolne miejsce[empty B1]
        sem_op(semid,4,-1); //sekcja krytyczna[mutex B1]
        cb1->buffer[cb1->in] = number;
        printf("Even, in crit B1, :%d.\n",number);
        cb1->in = (cb1->in +1)%N;
        sem_op(semid,4,1);
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
        sem_op(semid,4,-1); //wejscie do sekcji krytycznej
        int num1 = cb1->buffer[cb1->out];
        cb1->out =(cb1->out +1) % N;
        int num2 = cb1->buffer[cb1->out];
        cb1->out =(cb1->out +1) % N;
        int num3 = (cb1->buffer[cb1->out]);
        cb1->out =(cb1->out +1) % N;
        printf("Get3Numbers in crit B1: %d,%d,%d.\n",num1,num2,num3);
        sem_op(semid,4,1); //wyjscie z sekcji krytycznej
        sem_op(semid,1,3); //zwolnij 3 miejsca [empty B1]
        int sum = num1 + num2 + num3;
        sem_op(semid,3,-1); //czeka na wolne miejsce [empty B2]
        sem_op(semid,6,-1); //sekcja krytyczna [mutex B2]
        cb2->buffer[cb2->in] = sum;
        printf("Get3Numbers,in crit B2,%d\n",sum);
        cb2->in = (cb2->in+1)%M;
        sem_op(semid,6,1);//wyjscie z sekcji krytycznej
        sem_op(semid,2,1);//zwieksz liczbe elementow [full b2]
        sleep(1);
    }
}
//Funkcja generuje liczby nieparzyste parami (np. 1, 3) i zapisuje je do bufora B1.
void odd_process()
{
    int number = 1; 
    while(1)
    {
        sem_op(semid,1,-2); //oczekiwanie na 2 wolne miejsca [empty]
        sem_op(semid,4,-1); // sekcja krytyczna [mutex]
        cb1->buffer[cb1->in]=number;
        printf("Odd, in crit B1,%d, %d.\n",number,number + 2);
        cb1->in = (cb1->in +1) % N;
        cb1->buffer[cb1->in] = number + 2;
        cb1->in = (cb1->in +1)% N;
        sem_op(semid,4,1);
        sem_op(semid,0,2);
        number += 4;
        sleep(1);
    }
}
//funkcja pobiera pelne B2 , oblicza sume i wypisuje wynik
void getb2_process()
{
    while(1)
    {
        printf("GetB2,wait B2, -\n");
        sem_op(semid,2,-M); //czeka na pelne B2 [full b2]
        sem_op(semid,6,-1); //sekcja krytyczna [mutex b2]
        int sum =0;
        for(int i =0; i< M; i++)
        {
            sum += cb2->buffer[cb2->out];
            printf("Get B2, in crit B2, %d",cb2->buffer[cb2->out]);
                if(i < M -1)printf(", ");
                cb2->out = (cb2->out +1)%M;
        }
        printf(".\n");
        printf("GetB2, write_out: %d\n",sum);
        sem_op(semid,6,1); // wyjscie z sekcji krytycznej
        sem_op(semid,3,M); // zwolneinie miejsca M [empty B2]
        sleep(1);
    }
}
int main()
{
    //obsluga CTRL+C
    signal(SIGINT, cleanup);
    //tworzenie pamieci wspoldzielonej
    shmid_b1 = shmget(SHM_Key_B1, sizeof(CircularBufferB1), IPC_CREAT | 0666);
    if (shmid_b1 == -1) {
        perror("shmget");
        exit(1);
    }
    shmid_b2 = shmget(SHM_Key_B2, sizeof(CircularBufferB2), IPC_CREAT | 0666);
    if (shmid_b2 == -1) {
        perror("shmget B2");
        exit(1);
    }
    //pamiec wspoldzielona
    cb1 = (CircularBufferB1 *)shmat(shmid_b1, NULL, 0);
    if (cb1 == (void *)-1) {
        perror("shmat B1");
        exit(1);
    }
    cb2 = (CircularBufferB2 *)shmat(shmid_b2, NULL, 0);
    if (cb2 == (void *)-1) {
        perror("shmat B2");
        exit(1);
    }
    //bufor 
    cb1->in = 0;
    cb1->out = 0;
    memset(cb1->buffer, 0, sizeof(cb1->buffer));
    cb2->in = 0;
    cb2->out = 0;
    memset(cb2->buffer, 0, sizeof(cb2->buffer));
    semid = semget(SEM_Key, 6, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }
    //inicjalizacja semaforow
    union semun arg;
    arg.val = 0;   // full B1 = 0
    semctl(semid, 0, SETVAL, arg);
    arg.val = N;   // empty B1 = N
    semctl(semid, 1, SETVAL, arg);
    arg.val = 0;   // full B2 = 0 
    semctl(semid, 2, SETVAL, arg);
    arg.val = M;   // empty B2 = M 
    semctl(semid, 3, SETVAL, arg);
    arg.val = 1;   // mutex B1 = 1
    semctl(semid, 4, SETVAL, arg);
    arg.val = 1;   // mutex B2 = 1 
    semctl(semid, 5, SETVAL, arg);
    //tworzenie procesu even 
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        even_process();
        exit(0);
    }
    //tworzenie procesu odd
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        odd_process();
        exit(0);
    }
    //tworzenie procesu get3numbers
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        get3numbers_process();
        exit(0);
    }
    //tworzenie procesu getb2
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        getb2_process();
        exit(0);
    }
    //czekanie na procesy potomne
    while (wait(NULL) > 0) {
        if (errno == ECHILD) break;
    }
    cleanup(0);
    return 0;
}