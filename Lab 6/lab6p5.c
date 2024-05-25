#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

//problema 5

/*Să se implementeze o funcție input(const char *fmt,...). În șirul fmt pot fi caractere obișnuite (orice
în afară de %) și placeholdere (% urmat de o literă). Pentru fiecare placeholder posibil ( %d - int, %f -float, %c -
char ), în lista de argumente variabile se va afla adresa unei variabile de tipul corespunzător. Funcția afișează pe
ecran caracterele obișnuite și citește de la tastatură pentru placeholdere.
Exemplu: input(”n=%dch=%c”,&n,&ch); // citește o valoare de tip int în n și de tip char în ch*/

void input(const char *fmt,...)
{
    va_list va;
    int *d=NULL;
    double *f=NULL;
    int *c=NULL;
    va_start(va,fmt);
    for(int i=0;i<strlen(fmt);i++)
    {
        if(fmt[i]!='%')
        {
            printf("%c",fmt[i]);
        }
        else
        {
            switch(fmt[i+1])
            {
                case('d'):
                    d=va_arg(va,int *);
                    scanf("%d",d);
                    break;
                case('f'):
                    f=va_arg(va,double *);
                    scanf("%lf",f);
                    break;
                case('c'):
                    c=va_arg(va,int *);
                    scanf(" %lc",c);
                    break;
            }
            i++;
        }
    }
    va_end(va);
}

int main(void)
{
    int p1,p2,p3,p4,p5;
    input("nr1=%dnr2=%dch1=%cch2=%cnr2=%d",&p1,&p2,&p3,&p4,&p5);
    printf("%d%d%c%c%d\n",p1,p2,p3,p4,p5);
    return 0;
}