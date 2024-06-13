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
    elem *p=*lista;
    if(*lista==NULL)
    {
        *lista=nou(nr,NULL);
    }
    else
    {
        while(p->urm!=NULL)
        {
            p=p->urm;
        }
        p->urm=nou(nr,NULL);
    }
}

int cautare(elem *lista,int nr)
{
    int ok=0;
    for(elem *p=lista;p;p=p->urm)
    {
        if(p->nr==nr)
        {
            ok=1;
        }
    }
    return ok;
}

elem *reuniune(elem **lista1,elem **lista2)
{
    elem *lista3=NULL;
    elem *p1=*lista1,*p2=*lista2;
    for(p1=*lista1;p1;p1=p1->urm)
    {
        if(!cautare(lista3,p1->nr))
        {
            add_end(&lista3,p1->nr);
        }
    }
    for(p2=*lista2;p2;p2=p2->urm)
    {
        if(!cautare(lista3,p2->nr))
        {
            add_end(&lista3,p2->nr);
        }
    }
    return lista3;
}

elem *intersectie(elem **lista1,elem **lista2)
{
    elem *lista3=NULL;
    elem *p1=*lista1,*p2=*lista2;
    for(p1=*lista1;p1;p1=p1->urm)
    {
        for(p2=*lista2;p2;p2=p2->urm)
        {
            if((p1->nr==p2->nr) && !(cautare(lista3,p1->nr)))
            {
                add_end(&lista3,p1->nr);
            }
        }
    }
    return lista3;
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

void afisare2(elem *lista,FILE *fp)
{
    elem *p;
    for(p=lista;p;p=p->urm)
    {
        fprintf(fp,"%d ",p->nr);
    }
    fprintf(fp,"\n");
}

void eliberare(elem *lista)
{
    elem *p=lista,*aux;
    while(p!=NULL)
    {
        aux=p->urm;
        free(p);
        p=aux;
    }
}

int main()
{
    struct elem *lista1=NULL,*lista2=NULL,*r,*i;
    FILE *fp1=NULL,*fp2=NULL;
    int x;
    if(((fp1=fopen("MULTIME1.TXT","r+"))==NULL) || ((fp2=fopen("MULTIME2.TXT","r+"))==NULL))
    {
        perror(NULL);
        exit(-1);
    }
    while(fscanf(fp1,"%d",&x)==1)
    {
        add_end(&lista1,x);
    }
    while(fscanf(fp2,"%d",&x)==1)
    {
        add_end(&lista2,x);
    }
    r=reuniune(&lista1,&lista2);
    i=intersectie(&lista1,&lista2);
    afisare(lista1);  //am afisat cele 2 liste initiale pe ecran pentru a ne asigura ca au fost create corect
    afisare(lista2);
    fprintf(fp1,"\n");
    afisare2(r,fp1);
    afisare2(i,fp1);
    fprintf(fp2,"\n");
    afisare2(r,fp2);
    afisare2(i,fp2);
    eliberare(lista1);
    eliberare(lista2);
    eliberare(r);
    eliberare(i);
    if((fclose(fp1)!=0) || (fclose(fp2)!=0))
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}