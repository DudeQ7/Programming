#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
//funckcja , ktory odpowiada za wypisywanie argumentow z podanego zakresu
void print_args(char *argv[],int start,int end)
{
    for(int i = start; i<=end; i++)
    {
        printf("%s",argv[i]);
        if(i <end)
        {
            printf(" "); //spacje miedzy argumentami
        }
    }
}
//funckja ktora znajduje max w konkretnym fragmencie argumentow
int find_max(char *argv[],int start,int end)
{
    int max = atoi(argv[start]);
        for(int i = start+1;i<=end; i++)
        {
            int zmienna_0 = atoi(argv[i]);
                if(zmienna_0>max)
                {
                    max = zmienna_0;
                } 
        }
    return max;
}
//funkcja ktora znajduje min w danmy fragmencie argumentow
int find_min(char *argv[],int start,int end)
{
    int min = atoi(argv[start]);
        for(int i = start+1;i<=end; i++)
        {
            int zmienna_0 = atoi(argv[i]);
                if(zmienna_0<min)
                {
                    min = zmienna_0;
                } 
        }
    return min;
}
//n argumentow wieksze od 1 ale mniejsze od 20 
int main(int argc, char* argv[])
{
    //sprawdzenie czy zostala podana poprawna liczba argumentow(min 2, razem z nazwa porgramu)
    if(argc<2)
    {
        printf("Błedna liczba argumentow\n");
        return -100;
    }
    if(argc ==2)//realnie jeden argument, max i min maja te sama wartosc 
    {
        int zmienna_0=atoi(argv[1]);
            printf("Max to: %d",zmienna_0);
            printf("\nMin to: %d",zmienna_0);
        return 0;
    }
    if(argc ==3)//realnie dwa argumenty, porownanie tych argumentow w celu sprawdzenia ktory jest wiekszy a ktory mniejszy
    {
        int zmienna_0 =atoi(argv[1]);
        int zmienna_1 =atoi(argv[2]);
        if(zmienna_0>zmienna_1)
        {
            printf("Max to:%d",zmienna_0);
            printf("\nMin to:%d",zmienna_1);
        }
        else
        {
            printf("Max to:%d",zmienna_1);
            printf("\nMin to:%d",zmienna_0);
        }
        return 0;
    }
    //obliczenie podzialu argumentow  z podzialem na 2 polowy
    int n = argc -1; //odejmujemy argument pierwszy ktorym jest skompliowana nazwa naszego programu,liczba realnych argumentow[liczbowych] 
    int mid = n / 2 ; //punkt podzialu 
    int first_half = mid; 
    int second_half = mid+1;
    //Utworzenie 4 procesow potonych w celu znalezienia max i min
    pid_t pids[4] ; //tablica na procesy 
    int i ;
        for(i=0; i<4; i++)
        {
            pids[i] = fork();
                if(pids[i]<0)
                {
                    perror("Fork nie zadzialal");
                    exit(1);
                }
                    if(pids[i]==0) 
                    {
                        const char *type;
                        int start,end,result;
                            if(i==0) //Potomek_0:max w 1 polowie
                            {
                                start =1;
                                end = first_half;
                                type = "max";
                                result = find_max(argv,start,end);
                            }
                            else if(i==1)//Potomek_1:max w 2 polowie
                            {
                                start = second_half;
                                end = n;
                                type = "max";
                                result =find_max(argv,start,end);
                            }
                            else if(i==2)//Potomek_2:min w 1 polowie
                            {
                                start = 1;
                                end = first_half;
                                type = "min";
                                result =find_min(argv,start,end);
                            }
                            else //Potomek_3:min w 2 polowie
                            {
                              start = second_half;
                              end = n;
                              type = "min";
                              result = find_min(argv,start,end);
                            }
                            //wypisanie wyniku potomka: Process ID , fragment, typ,wynik 
                            //getppid = zwraca proces id procesu nadrzednego rodzica, getpid procesu dziecka
                            printf("%d %d ",getppid(),getpid());
                            print_args(argv,start,end);
                            printf(" %s %d\n",type, result);
                            exit(result);
                    }   
        }
        //Rodzic, ktory ma zebrac wyniki od potomka
        int max_0,max_1,min_0,min_1,status; // kod potrzebny dla dzialania rodzica
        for(int i=0; i<4; i++)
        {
            waitpid(pids[i],&status,0);
                if(WIFEXITED(status))
                {
                    int exit_code = WEXITSTATUS(status);
                        if(i==0)
                        {
                            max_0 = exit_code;
                        }
                        else if(i==1)
                        {
                            max_1 = exit_code;
                        }
                        else if(i==2)
                        {
                            min_0 = exit_code;
                        }
                        else
                        {
                            min_1 = exit_code;
                        }
                }
        }
        //Obliczenie globalnego max i min, w celu wypisania go zgodnie z formatem przedstawionym w pdf'ie
        int global_max = (max_0>max_1) ? max_0:max_1; // jesli min_0 > max_1 = true, to min_0 zostanie przypisane else min_1 zostanie przypisane
        int global_min = (min_0<min_1) ? min_0:min_1; // jesli min_0<min_1 = true, to min_0 zostanie przypisane, else min_1
            printf("max: %d",global_max);
            printf("\nmin:%d",global_min);
    return 0;
}