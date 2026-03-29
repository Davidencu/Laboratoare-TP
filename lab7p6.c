#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// un element al listei

typedef struct elem{
    int n; // informatia utila
    struct elem *urm; // camp de inlantuire catre urmatorul element
}elem;

// aloca un nou element si ii seteaza campurile corespunzatoare
elem *nou(int n,elem *urm)
{
    elem *e=(elem*)malloc(sizeof(elem));
    if(!e)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    e->n=n;
    e->urm=urm;
    return e;
}

typedef struct{
    elem *prim; // primul element din lista
    elem *ultim; // ultimul element din lista
}Lista;

void init(Lista *lista)
{
    lista->prim=NULL;
    lista->ultim=NULL;
}

// adauga un element la inceputul listei

void adaugaInceput(Lista *lista,int n)
{
    elem *prim=lista->prim;
    lista->prim=nou(n,prim);
    if(!prim){ // lista initiala vida - trebuie setat si ultim pe elementul adaugat
    lista->ultim=lista->prim;
}
}
// adauga un element la sfarsitul listei
void adaugaSfarsit(Lista *lista,int n)
{
    elem *e=nou(n,NULL);
    if(lista->ultim){ // adaugare in lista nevida
        lista->ultim->urm=e;
    }
    else{ // adaugare in lista vida
        lista->prim=e;
    }
    lista->ultim=e;
}

void afisare(Lista *lista)
{
    elem *crt;
    for(crt=lista->prim;crt;crt=crt->urm){
        printf("%d ",crt->n);
    }
    putchar('\n');
}

// elibereaza memoria ocupata de o lista

void eliberare(Lista *lista)
{
    elem *p,*crt=lista->prim;
    while(crt){
        p=crt->urm;
        free(crt);
        crt=p;
    }
}

void insert(Lista *lista,int n)
{
    elem *p,*c,*u;
    if(lista->prim==NULL && lista->ultim==NULL)
    {
        adaugaSfarsit(lista,n);
    }
    else
    {
    c=lista->prim;
    u=c->urm;
    if(n<c->n)
    {
        adaugaInceput(lista,n);
    }
    while(c!=NULL && c->urm!=NULL)
    {
        u=c->urm;
        if(n>=(c->n) && n<=(u->n)) 
        {
            p=nou(n,u);
            c->urm=p;
        }
        c=u;
    }
    if(n>(c->n))
    {
        adaugaSfarsit(lista,n);
    }
    }
}

Lista sortare(Lista *lista)
{
    Lista l;
    init(&l);
    elem *crt;
    for(crt=lista->prim;crt;crt=crt->urm)
    {
        insert(&l,crt->n);
    }
    return l;
}

int main()
{
    Lista lista1,lista2;
    init(&lista1);
    adaugaSfarsit(&lista1,6);
    adaugaSfarsit(&lista1,4);
    adaugaSfarsit(&lista1,5);
    adaugaSfarsit(&lista1,9);
    adaugaSfarsit(&lista1,7);
    adaugaSfarsit(&lista1,3);
    adaugaSfarsit(&lista1,11);
    afisare(&lista1);
    lista2=sortare(&lista1);
    afisare(&lista2);
    eliberare(&lista1);
    return 0;
}