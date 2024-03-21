#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CHUNK 10

//problema 4.6

typedef struct
{
    unsigned int valoare:10;
    unsigned int unitate:2;
    unsigned int m:4;
} masuratoare;

void citire(masuratoare *a)
{
    long val;
    char s[6];
    int aux=0,nr=0;
    printf("Dati valoarea ");
    scanf("%ld",&val);
    printf("Dati unitatea ");
    getchar();
    if(fgets(s,6,stdin)==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    if(s[strlen(s)-1]=='\n')
    {
        s[strlen(s)-1]='\0';
    }
    if(strcmp(s,"gram")==0)
    {
        aux=0;
    }
    if(strcmp(s,"metru")==0)
    {
        aux=1;
    }
    if(strcmp(s,"litru")==0)
    {
        aux=2;
    }
    a->unitate=aux;
    while(val>=1024)
    {
        if (nr<3) val=val/10;
        else val=val/1000;
        nr++;
        if (nr>5)
        {
            printf("eroare\n");
            exit(-1);
        }
    }
    if (nr!=0) 
    {
        a->m=nr+5;
    }
    else
    {
        a->m=nr;
    }
    a->valoare=val;
}

void afisare(masuratoare *a)
{
    printf("%d ",a->valoare);
    switch(a->m)
    {
        case 0:
            break;
        case 1:
            printf("pico");
            break;
        case 2:
            printf("nano");
            break;
        case 3:
            printf("mili");
            break;
        case 4:
            printf("centi");
            break;
        case 5:
            printf("deci");
            break;
        case 6:
            printf("deca");
            break;
        case 7:
            printf("hecto");
            break;
        case 8:
            printf("kilo");
            break;
        case 9:
            printf("mega");
            break;
        case 10:
            printf("giga");
            break;
    }
    switch(a->unitate)
    {
        case 0:
            printf("gram\n");
            break;
        case 1:
            printf("metru\n");
            break;
        case 2:
            printf("litru\n");
            break;
    }
}

int main(void)
{
    masuratoare a;
    citire(&a);
    afisare(&a);
    return 0;
}