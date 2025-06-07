#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "funkcje.h"
int main(int argc, char* argv[])
{
    if(argc<2)
    {
        printf("Błedna liczba argumentow\n");
        return -100;
    }
    if(argc ==2)
    {
        int zmienna_0=atoi(argv[1]);
            printf("Max to: %d",zmienna_0);
            printf("\nMin to: %d",zmienna_0);
        return 0;
    }
    if(argc ==3)
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
    int n = argc -1; 
    int mid = n / 2 ; 
    int first_half = mid; 
    int second_half = mid+1;
    pid_t pids[4] ; 
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
                            if(i==0) 
                            {
                                start =1;
                                end = first_half;
                                type = "max";
                                result = find_max(argv,start,end);
                            }
                            else if(i==1)
                            {
                                start = second_half;
                                end = n;
                                type = "max";
                                result =find_max(argv,start,end);
                                

                            }
                            else if(i==2)
                            {
                                start = 1;
                                end = first_half;
                                type = "min";
                                result =find_min(argv,start,end);

                            }
                            else 
                            {
                              start = second_half;
                              end = n;
                              type = "min";
                              result = find_min(argv,start,end);
                            }
                            printf("%d %d ",getppid(),getpid());
                            print_args(argv,start,end);
                            printf(" %s %d\n",type, result);
                            exit(result);
                    }   
        }
        int max_0,max_1,min_0,min_1,status; 
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
        int global_max = (max_0>max_1) ? max_0:max_1;
        int global_min = (min_0<min_1) ? min_0:min_1;

            printf("max: %d",global_max);
            printf("\nmin:%d",global_min);
    return 0;
}