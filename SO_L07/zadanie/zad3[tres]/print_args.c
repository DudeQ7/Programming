#include <stdio.h>
#include "funkcje.h"
void print_args(char *argv[],int start,int end)
{
    for(int i = start; i<=end; i++)
    {
        printf("%s",argv[i]);
        if(i <end)
        {
            printf(" "); 
        }
    }
}