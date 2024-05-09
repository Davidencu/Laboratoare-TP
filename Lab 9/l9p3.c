#include<stdio.h>
#include<stdlib.h>


typedef struct elem
{
    int n;
    struct elem *urm;
}elem;

elem *nou(int n,elem *urm)
{
    elem *p;
    if ((p=(elem *)malloc(sizeof(elem)))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    p->n=n;
    p->urm=urm;
    return p;
}

elem *ins_inceput(int n,elem *lista)
{
    return nou(n,lista);
}

void afisare(elem *lista)
{
    elem *p;
    for(p=lista;p;p=p->urm)
    {
        printf("%d ",p->n);
    }
    printf("\n");
}

void eliberare(elem *lista)
{
    elem *p;
    while(lista)
    {
        p=lista;
        lista=lista->urm;
        free(p);
    }
}

elem *func(elem *lista)
{
    elem *c=lista,*u;
    while(c)
    {
        u=c->urm;
        if(c->n%2==0)
        {
            c->urm=nou((c->n)/2,u);
        }
        c=u;
    }
    return lista;
}

int main(void)
{
    struct elem *lista=NULL;
    lista=ins_inceput(2,lista);
    lista=ins_inceput(1,lista);
    lista=ins_inceput(4,lista);
    lista=ins_inceput(8,lista);
    lista=ins_inceput(2,lista);
    lista=ins_inceput(1,lista);
    afisare(lista);
    lista=func(lista);
    afisare(lista);
    eliberare(lista);
    return 0;
}