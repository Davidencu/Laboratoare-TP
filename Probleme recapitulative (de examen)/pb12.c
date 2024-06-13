#include<stdio.h>
#include<stdlib.h>

typedef struct elem
{
    int nr;
    struct elem *urm;
}elem;

elem *nou(int nr,elem *urm)
{
    elem *p=malloc(sizeof(elem));
    if(p==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    p->nr=nr;
    p->urm=urm;
    return p;
}

void add_end(elem **lista,int nr)
{
    if(*lista==NULL)
    {
        *lista=nou(nr,NULL);
    }
    else
    {
        elem *p;
        for(p=*lista;p->urm;p=p->urm);
        p->urm=nou(nr,NULL);
    }
}

void inversare(elem **lista)
{
    elem *p=NULL,*c=*lista,*u=c->urm;
    while(c!=NULL)
    {
        c->urm=p;
        p=c;
        c=u;
        if(u)
        {
            u=u->urm;
        }
    }
    *lista=p;
}

void afisare(elem *lista)
{
    elem *p;
    for(p=lista;p;p=p->urm)
    {
        printf("%d ",p->nr);
    }
    printf("\n");
}

void eliberare(elem *lista)
{
    elem *p=lista,*aux;
    while(p)
    {
        aux=p->urm;
        free(p);
        p=aux;
    }
}

int main()
{
    elem *lista=NULL;
    FILE *fp=NULL;
    int x;
    if((fp=fopen("DATA.TXT","r"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    while(fscanf(fp,"%d",&x)==1)
    {
        add_end(&lista,x);
    }
    afisare(lista);
    inversare(&lista);
    afisare(lista);
    eliberare(lista);
    if(fclose(fp)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}