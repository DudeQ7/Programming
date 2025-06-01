#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

//n argumentow wieksze od 1 ale mniejsze od 20 
int main(int argc, char* argv[])
{
    if((argc >1)&&(argc <20))
    {
        printf("Podales poprawna liczbe argumentow");
        int arg_1 = atoi(argv[1]);
        int arg_2 = atoi(argv[2]);
            if((argc == 1)||(argc ==2))
            {
               
                    if(arg_1>arg_2)
                    {
                        printf("max: %d",arg_1);
                        printf("\nmin: %d",arg_2);
                    }
            }
    }
    else
    {
        printf("Bledna liczba argumentow");
        return -100;
    }
    return 0;
}