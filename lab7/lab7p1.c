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

//problema 1

int verif(Lista *lista1, Lista *lista2)
{
    elem *crt1,*crt2;
    int ok=1;
    for(crt1=lista1->prim,crt2=lista2->prim;crt1&&crt2;crt1=crt1->urm,crt2=crt2->urm)
    {
        if((crt1->n != crt2->n) || (crt1->urm==NULL && crt2->urm!=NULL) || (crt1->urm!=NULL && crt2->urm==NULL))
            ok=0;
    }
    return ok;
}

int main()
{
    Lista lista1,lista2,lista3;
    init(&lista1); init(&lista2);
    adaugaSfarsit(&lista1,1);
    adaugaSfarsit(&lista1,3);
    adaugaSfarsit(&lista1,5);
    adaugaSfarsit(&lista1,5);
    adaugaSfarsit(&lista2,1);
    adaugaSfarsit(&lista2,3);
    adaugaSfarsit(&lista2,5);
    adaugaSfarsit(&lista2,5);
    afisare(&lista1);
    afisare(&lista2);
    if(verif(&lista1,&lista2))
    {
        printf("Ambele liste sunt identice\n");
    }
    else
    {
        printf("Listele nu sunt identice\n");
    }
    eliberare(&lista1);
    eliberare(&lista2);
    eliberare(&lista3);
    return 0;
}
