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

int cautare(Lista *lista,int n)
{
    elem *crt;
    int ok=0;
    if(lista->prim==lista->ultim)
    {
        return 0;
    }
    for(crt=lista->prim;crt->urm;crt=crt->urm)
    {
        if(crt->n==n)
        {
            ok=1;
            break;
        }
    }
    return ok;
}

 //parcurgem ambele liste o singura data, si daca un element exista
 //deja in lista dorita, nu il adaugam

Lista reuniune(Lista *lista1, Lista *lista2)
{
    Lista r;
    init(&r);
    elem *crt1=lista1->prim;
    elem *crt2=lista2->prim;
    for(;crt1;crt1=crt1->urm)
    {
        if(cautare(&r,crt1->n)==0)
        {
            adaugaSfarsit(&r,crt1->n);
        }
    }
    for(;crt2;crt2=crt2->urm)
    {
        if(cautare(&r,crt2->n)==0)
        {
            adaugaSfarsit(&r,crt2->n);
        }
    }
    return r;
}

int main()
{
    Lista lista1,lista2,lista3;
    init(&lista1); init(&lista2);
    adaugaSfarsit(&lista1,7);
    adaugaSfarsit(&lista1,9);
    adaugaSfarsit(&lista1,8);
    adaugaSfarsit(&lista1,8);
    adaugaSfarsit(&lista1,2);
    adaugaSfarsit(&lista1,1);
    adaugaSfarsit(&lista1,5);
    adaugaSfarsit(&lista2,1);
    adaugaSfarsit(&lista2,7);
    adaugaSfarsit(&lista2,8);
    adaugaSfarsit(&lista2,10);
    adaugaSfarsit(&lista2,12);
    adaugaSfarsit(&lista2,10);
    afisare(&lista1);
    afisare(&lista2);
    lista3=reuniune(&lista1,&lista2);
    afisare(&lista3);
    eliberare(&lista1);
    eliberare(&lista2);
    eliberare(&lista3);
    return 0;
}