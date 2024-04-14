#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CHUNK 10

//problema 4.5

typedef struct
{
    unsigned int grad:2;
    unsigned int reteta:1;
    unsigned int varsta_min:5;
}medicament;

void citire(medicament *m)
{
    int aux=0,aux1=0,aux2=0;
    printf("Dati gradul de periculozitate: ");
    scanf("%d",&aux);
    printf("Scrieti 1 daca se elibereaza doar pe baza de reteta,altfel 0 ");
    scanf("%d",&aux1);
    printf("Dati varsta minima de administrare: ");
    scanf("%d",&aux2);
    m->grad=aux;
    m->reteta=aux1;
    m->varsta_min=aux2;
}

void afisare(medicament *m)
{
    switch(m->grad)
    {
        case 0:
            printf("scazuta, ");
            break;
        case 1:
            printf("medie, ");
            break;
        case 2:
            printf("mare, ");
            break;
    }
    switch(m->reteta)
    {
        case 0:
            printf("nu se elibereaza pe baza de reteta, ");
            break;
        case 1:
            printf("se elibereaza doar pe baza de reteta, ");
            break;
    }
    printf("varsta minima de administrare este de %d ani.\n",m->varsta_min);
}

int main(void)
{
    medicament paracetamol;
    citire(&paracetamol);
    afisare(&paracetamol);
    return 0;
}