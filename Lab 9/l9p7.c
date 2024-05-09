#include<stdio.h>
#include<stdlib.h>

typedef struct elem
{
    int n;
    struct elem *pred;
    struct elem *urm;
}elem;

typedef struct
{
    elem *start;
    elem *end;
}lista;

elem *nou(elem *pred,elem *urm,int n)
{
    elem *p;
    if((p=(elem *)malloc(sizeof(elem)))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    p->n=n;
    p->pred=pred;
    p->urm=urm;
    return p;
}

void init(lista *lista)
{
    lista->start=NULL;
    lista->end=NULL;
}

void adaugare_final(lista *lista,int n)
{
    elem *p;
    if(lista->start==NULL)
    {
        p=nou(NULL,NULL,n);
        lista->start=p;
        lista->end=p;
    }
    else
    {
        p=nou(lista->end,NULL,n);
        lista->end->urm=p;
        lista->end=p;
    }
}

void afisare(lista *lista)
{
    elem *p=lista->start;
    for(;p;p=p->urm)
    {
        printf("%d ",p->n);
    }
    printf("\n");
}

void afisare_inv(lista *lista)
{
    elem *p=lista->end;
    for(;p;p=p->pred)
    {
        printf("%d ",p->n);
    }
    printf("\n");
}

void eliberare(lista *lista)
{
    elem *c=lista->start;
    while(c!=lista->end)
    {
        lista->start=c->urm;
        free(c);
        c=lista->start;
    }
    free(c);
}

int palindrom(lista *lista)
{
    elem *c;
    long nr1=0,nr2=0;
    for(c=lista->start;c;c=c->urm)
    {
        nr1=nr1*10+(c->n);
    }
    for(c=lista->end;c;c=c->pred)
    {
        nr2=nr2*10+(c->n);
    }
    if (nr1==nr2)
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    lista lista;
    init(&lista);
    adaugare_final(&lista,2);
    adaugare_final(&lista,3);
    adaugare_final(&lista,0);
    adaugare_final(&lista,0);
    adaugare_final(&lista,3);
    adaugare_final(&lista,1);
    afisare(&lista);
    afisare_inv(&lista);
    printf("%d\n",palindrom(&lista));
    eliberare(&lista);
    return 0;
}