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

int check(Lista *lista1,Lista *lista2)
{
    elem *crt1,*crt2;
    int cnt1=0,cnt2=0,nr1=0,nr2=0,ok=0;
    for(crt1=lista1->prim;crt1;crt1=crt1->urm)
    {
        ok=0;
        for(crt2=lista2->prim;crt2;crt2=crt2->urm)
        {
            if(crt1->n==crt2->n)
            {
                if (ok==0) 
                {
                    nr1++;
                    ok=1;
                }
            }
        }
        cnt1++;
    }
    for(crt2=lista2->prim;crt2;crt2=crt2->urm)
    {
        ok=0;
        for(crt1=lista1->prim;crt1;crt1=crt1->urm)
        {
            if(crt1->n==crt2->n)
            {
                if (ok==0) 
                {
                    nr2++;
                    ok=1;
                }
            }
        }
        cnt2++;
    }
    if(nr1==cnt1 && nr2==cnt2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    Lista lista1,lista2;
    init(&lista1); init(&lista2);
    adaugaSfarsit(&lista1,1);
    adaugaSfarsit(&lista1,5);
    adaugaSfarsit(&lista1,4);
    adaugaSfarsit(&lista1,3);
    adaugaSfarsit(&lista1,7);
    adaugaSfarsit(&lista1,9);
    adaugaSfarsit(&lista1,4);
    adaugaSfarsit(&lista2,9);
    adaugaSfarsit(&lista2,7);
    adaugaSfarsit(&lista2,3);
    adaugaSfarsit(&lista2,5);
    adaugaSfarsit(&lista2,4);
    adaugaSfarsit(&lista2,1);
    afisare(&lista1);
    afisare(&lista2);
    printf("%d\n",check(&lista1,&lista2));
    eliberare(&lista1);
    eliberare(&lista2);
    return 0;
}