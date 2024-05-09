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

void permutare(lista *lista)
{
    elem *a=NULL,*b=lista->start,*c=b->urm,*d=c->urm;
    do
    {
        d=c->urm;
        b->urm=d;
        b->pred=c;
        c->urm=b;
        c->pred=a;
        
        if (!a)
        {
            lista->start=c;
        }
        else
        {
            a->urm=c;
        }
        if (d) 
        {
            d->pred=b;
            b=d;
            c=d->urm;
            a=d->pred;
        }
        else
        {
            lista->end=b;
        }
    } while(d);
}

int main(void)
{
    lista lista;
    init(&lista);
    adaugare_final(&lista,2);
    adaugare_final(&lista,3);
    adaugare_final(&lista,4);
    adaugare_final(&lista,5);
    adaugare_final(&lista,6);
    adaugare_final(&lista,7);
    afisare(&lista);
    permutare(&lista);
    afisare(&lista);
    eliberare(&lista);
    return 0;
}
