#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

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


void inversare(Lista *lista)
{
    elem *p,*c,*u;
    int cnt=0;
    c=lista->prim;
    u=c->urm;
    while(c!=NULL && c->urm!=NULL)
    {
        u=c->urm;
        if(cnt==0)
        {
            c->urm=NULL;
        }
        else
        {
            c->urm=p;
        }
        p=c;
        c=u;
        cnt++;
    }
    c->urm=p;
    lista->prim=c;
}

int main()
{
    Lista lista1;
    init(&lista1);
    adaugaSfarsit(&lista1,1);
    adaugaSfarsit(&lista1,3);
    adaugaSfarsit(&lista1,5);
    adaugaSfarsit(&lista1,4);
    adaugaSfarsit(&lista1,0);
    afisare(&lista1);
    inversare(&lista1);
    afisare(&lista1);
    eliberare(&lista1);
    return 0;
}