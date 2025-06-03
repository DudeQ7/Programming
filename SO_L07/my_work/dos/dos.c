#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int find_max(char *argv[],int start,int end)
{
    int max = atoi(argv[start]);
        for(int i = start+1;i<=end; i++)
        {
            int zmienna_0 = atoi[argv[i]];
            int (zmienna_0>max) max = zmienna_0;
        }
    return max;
}
//n argumentow wieksze od 1 ale mniejsze od 20 
int main(int argc, char* argv[])
{
    if(argc<2)
    {
        printf("Błedna liczba argumentow");
        return -100;
    }
    if(argc ==2)//realnie jeden argument
    {
        int zmienna_0=atoi(argv[1]);
            printf("Max to: %d",zmienna_0);
            printf("\nMin to: %d",zmienna_0);
    }
    if(argc ==3)//realnie dwa argumenty
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
            printf("\nMin to:%d",zmienna_0); faf
        }
        return 0;
    }
    int n = argc -1; //odejmujemy argument pierwszy ktorym jest skompliowana nazwa naszego programu 
    int mid = n / 2 ; //punkt podzialu 
    int first_half = mid; 
    int second_half = mid+1;
    pid_t pids[4] ; //tablica na procesy 
    int i ;
        for(i=0; i<4; i++)
        {
            pids[i] = fork();
                if(pids[i]<0)
                {
                    peerror("Fork nie zadzialal");
                    exit(1);
                }
                    if(pids[i]==0) //max pierwsza polowa lancucha
                    {
                        const char *type;
                        int start,end,result;
                    }
                    if(i==0)
                    {
                        start =1;
                        end = first_half;
                        type = "max";
                        result = 
                    }

                
        }
    
    return 0;
}