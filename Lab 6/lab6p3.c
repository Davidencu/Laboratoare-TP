#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

//problema 3

/*Să se scrie o funcție absN(int n,...) care primește un număr n de adrese de tip float și setează la
fiecare dintre aceste adrese valoarea absolută de la acea locație.
Exemplu: absN(2,&x,&y); // echivalent cu x=fabs(x); y=fabs(y);*/

void absN(int n,...)
{
    va_list va;
    va_start(va,n);
    double *aux;
    for(int i=0;i<n;i++)
    {
        aux=va_arg(va,double *);
        if (*aux<0)
        {
            *aux=-(*aux);
        }
    }
    va_end(va);
}

int main(void)
{
    float x=3.0,y=-4.0,z=1.5;
    absN(3,&x,&y,&z);
    printf("%f %f %f",x,y,z);
    return 0;
}