#include<stdio.h>
#include<stdlib.h>

typedef struct elem
{
    int n;
    struct elem *urm;
}elem;

elem *nou(int numar,elem *urm)
{
    elem *p;
    if((p=malloc(sizeof(elem)))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    p->n=numar;
    p->urm=urm;
    return p;
}

elem *adaugare_sfarsit(int n,elem *lista)
{
    if (!lista) return nou(n,NULL);
    elem *p;
    for(p=lista;p->urm;p=p->urm)
    {
    }
    p->urm=nou(n,NULL);
    return lista;
}

void afisare(elem *lista)
{
    elem *c;
    for(c=lista;c;c=c->urm)
    {
        printf("%d ",c->n);
    }
    printf("\n");
}

void eliberare(elem *lista)
{
    elem *c=lista,*u;
    while(c)
    {
        u=c->urm;
        free(c);
        c=u;
    }
}

elem *stergere(elem *lista)
{
    elem *p=NULL,*c=lista,*u;
    while(c!=NULL)
    {
        u=c->urm;
        if((c->n)%2==0)
        {
            if(c==lista)
            {
                lista=lista->urm;
                free(c);
            }
            else
            {
                p->urm=c->urm;
                free(c);
            }
        }
        else
        {
            p=c;
        }
        c=u;
    }
    return lista;
}

int main()
{
    elem *lista=NULL;
    lista=adaugare_sfarsit(1,lista);
    lista=adaugare_sfarsit(2,lista);
    lista=adaugare_sfarsit(3,lista);
    lista=adaugare_sfarsit(4,lista);
    lista=adaugare_sfarsit(5,lista);
    lista=adaugare_sfarsit(6,lista);
    lista=adaugare_sfarsit(7,lista);
    lista=adaugare_sfarsit(8,lista);
    lista=adaugare_sfarsit(10,lista);
    lista=adaugare_sfarsit(9,lista);
    afisare(lista);
    lista=stergere(lista);
    afisare(lista);
    eliberare(lista);
    return 0;
}