#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

//problema 2

float *allocVec(int n,...)
{
    float *array=NULL;
    if((array=(float *)malloc(n*sizeof(float)))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    va_list va;
    va_start(va,n);
    for(int i=0;i<n;i++)
    {
        array[i]=va_arg(va,double);
    }
    va_end(va);
    return array;
}

void afisare(float *array,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%f ",array[i]);
    }
    printf("\n");
}

int main(void)
{
    float *array=allocVec(3,1.0,1.5,2.0);
    afisare(array,3);
    free(array);
    return 0;
}