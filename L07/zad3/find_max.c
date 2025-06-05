#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"
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