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

elem *stergere_inceput(int *n,elem *lista)
{
    elem *p=lista;
    lista=p->urm;
    *n=p->n;
    free(p);
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

elem *permutare(int k,elem *lista)
{
    int aux=0;
    for(int i=0;i<k;i++)
    {
        lista=stergere_inceput(&aux,lista);
        lista=adaugare_sfarsit(aux,lista);
    }
    return lista;
}

int main(void)
{
    elem *lista=NULL;
    FILE *fp=NULL;
    int k,nr;
    if((fp=fopen("data.in","r"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    fscanf(fp,"%d",&k);
    while (fscanf(fp,"%d",&nr)==1)
    {
        lista=adaugare_sfarsit(nr,lista);
    }
    afisare(lista);
    lista=permutare(k,lista);
    afisare(lista);
    eliberare(lista);
    if(fclose(fp)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}
