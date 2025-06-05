#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"
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