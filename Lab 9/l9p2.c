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

void create(elem **lista1,elem **lista2,FILE *fp)
{
    int nr;
    while(fscanf(fp,"%d",&nr)==1)
    {
        if(nr%2==0)
        {
            *lista1=adaugare_sfarsit(nr,*lista1);
        }
        else
        {
            *lista2=adaugare_sfarsit(nr,*lista2);
        }
    }
    elem *c=*lista1;
    for(;c->urm;c=c->urm)
    {
    }
    c->urm=*lista2;
}

int main()
{
    FILE *fp=NULL;
    if((fp=fopen("data.in","r"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    elem *lista1=NULL,*lista2=NULL;
    create(&lista1,&lista2,fp);
    afisare(lista1);
    eliberare(lista1);
    if(fclose(fp)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}