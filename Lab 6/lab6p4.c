#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

//problema 4

/*Să se scrie o funcție crescator(int n,char tip,...) care primește un număr n de valori și returnează 1
dacă ele sunt în ordine strict crescătoare, altfel 0. Caracterul tip indică tipul valorilor și poate fi ‘d’ - int, ‘f’ - double.
Exemplu: printf(“%d”,crescator(3,’d’,-1,7,9));*/

int crescator(int n,char tip,...)
{
    va_list va;
    va_start(va,tip);
    double minn=-1000000.0;
    double a2,prev=minn;
    int a1,ok=1;
    switch(tip)
    {
        case(100):
            for(int i=0;i<n;i++)
            {
                a1=va_arg(va,int);
                if(a1>(int)prev)
                {
                    prev=a1;
                }
                else
                {
                    ok=0;
                    break;
                }
            }
            break;
        case(102):
            for(int i=0;i<n;i++)
            {
                a2=va_arg(va,double);
                printf("%f ",a2);
                if(a2>prev)
                {
                    prev=a2;
                }
                else
                {
                    ok=0;
                    break;
                }
            }
            break;
        default:
            printf("eroare\n");
            exit(-1);
            break;
    }
    va_end(va);
    return ok;
}

int main()
{
    printf("%d\n",crescator(5,'d',2,3,6,4,5));
    return 0;
}