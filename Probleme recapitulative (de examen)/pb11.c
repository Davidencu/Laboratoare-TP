#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct elem
{
    char ch;
    struct elem *urm;
}elem;

elem *nou(char ch,elem *urm)
{
    elem *p=malloc(sizeof(elem));
    if(p==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    p->ch=ch;
    p->urm=urm;
    return p;
}

void add_end(elem **lista,char ch)
{
    if(*lista==NULL)
    {
        *lista=nou(ch,NULL);
    }
    else
    {
        elem *p;
        for(p=*lista;p->urm;p=p->urm);
        p->urm=nou(ch,NULL);
    }
}

int verificare(elem *lista)
{
    if(lista->ch=='(')
    {
        elem *a,*b;
        int ok=1,nr=0;
        a=lista->urm->urm->urm->urm;
        b=lista->urm->urm->urm->urm->urm->urm->urm->urm;
        if(a->ch==')' && b->ch=='-')
        {
            for(elem *p=lista->urm;p;p=p->urm)
            {
                if(p!=a && p!=b && !isdigit(p->ch))
                {
                    ok=0;
                    printf("nu e cifra\n");
                }
                nr++;
            }
            if(nr!=12)
            {
                ok=0;
                printf("marime insuficienta\n");
            }
            return ok;
        }
        return 0;
    }
    if(strchr("0123456789",lista->ch)!=0)
    {
        elem *c,*d;
        int ok=1,nr=0;
        c=lista->urm->urm->urm;
        d=lista->urm->urm->urm->urm->urm->urm->urm;
        if(c->ch=='-' && d->ch=='-')
        {
            for(elem *p=lista->urm;p;p=p->urm)
            {
                if(p!=c && p!=d && !isdigit(p->ch))
                {
                    ok=0;
                }
                nr++;
            }
            if(nr!=11)
            {
                ok=0;
            }
            return ok;
        }
        return 0;
    }
    return 0;
}

void afisare(elem *lista)
{
    elem *p;
    for(p=lista;p;p=p->urm)
    {
        printf("%c ",p->ch);
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
    char x;
    if((fp=fopen("DATA.TXT","r"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    while(fscanf(fp,"%c",&x)==1)
    {
        add_end(&lista,x);
    }
    afisare(lista);
    if(verificare(lista))
    {
        printf("Nr. de telefon valid\n");
    }
    else
    {
        printf("Invalid\n");
    }
    eliberare(lista);
    if(fclose(fp)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}