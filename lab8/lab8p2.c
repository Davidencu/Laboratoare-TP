#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cuvant
{
    char text[16]; // max 15 litere+terminator
    int cnt;
    struct Cuvant *pred; // inlantuire la predecesor
    struct Cuvant *urm; // inlantuire la urmator
}Cuvant;

// aloca un nou cuvant si ii seteaza campul text
// campurile pred si urm raman neinitializate

Cuvant *Cuvant_nou(const char *text)
{
    Cuvant *c=(Cuvant*)malloc(sizeof(Cuvant));
    if(!c)
    {
        printf("memorie insuficienta");
    exit(EXIT_FAILURE);
    }
    strcpy(c->text,text);
    return c;
}

typedef struct{
    Cuvant *prim; // primul cuvant din lista
    Cuvant *ultim; // ultimul cuvant din lista
}Propozitie;

// initializare propozitie noua

void Propozitie_init(Propozitie *p)
{
    p->prim=p->ultim=NULL;
}

// adauga un cuvant la sfarsitul propozitiei

Cuvant *Propozitie_cauta(Propozitie *p,const char *text)
{
    Cuvant *c;
    for(c=p->prim;c;c=c->urm)
    {
        if(!strcmp(c->text,text))return c;
    }
    return NULL;
}

void Propozitie_adauga(Propozitie *p,Cuvant *c)
{
    c->pred=p->ultim; // predecesorul cuvantului este ultimul cuvant din lista
    if(p->ultim)
    { // daca mai sunt si alte cuvinte in lista
        p->ultim->urm=c; // ultimul cuvant din lista va pointa catre noul cuvant
    }
    else
    { // altfel, daca c este primul cuvant din lista
        p->prim=c; // seteaza si inceputul listei la el
    }
    p->ultim=c; // seteaza sfarsitul listei pe noul cuvant
    c->urm=NULL; // dupa cuvantul introdus nu mai urmeaza niciun cuvant
}

void Propozitie_adauga_inceput(Propozitie *p,Cuvant *c)
{
    c->urm=p->prim; // predecesorul cuvantului este ultimul cuvant din lista
    if(p->prim)
    { // daca mai sunt si alte cuvinte in lista
        p->prim->pred=c; // ultimul cuvant din lista va pointa catre noul cuvant
    }
    else
    { // altfel, daca c este primul cuvant din lista
        p->ultim=c; // seteaza si inceputul listei la el
    }
    p->prim=c; // seteaza sfarsitul listei pe noul cuvant
    c->pred=NULL; // dupa cuvantul introdus nu mai urmeaza niciun cuvant
}

// cauta un text in propozitie si daca il gaseste returneaza un pointer la cuvantul respectiv
// daca nu-l gaseste, returneaza NULL

// sterge un cuvant din propozitie

void Propozitie_sterge(Propozitie *p,Cuvant *c)
{
    if(c->pred)
    { // cuvantul nu este primul in propozitie
        c->pred->urm=c->urm; // campul urm al predecesorului lui c va pointa la cuvantul de dupa c
    }
    else
    { // cuvantul este primul in propozitie
        p->prim=c->urm; // seteaza inceputul listei pe urmatorul cuvant de dupa c
    }
    if(c->urm)
    { // cuvantul nu este ultimul din propozitie
        c->urm->pred=c->pred; // campul pred al cuvantului de dupa c va pointa la cuvantul de dinainte de c
    }
    else
    { // cuvantul este ultimul din propozitie
        p->ultim=c->pred; // seteaza sfarsitul listei pe predecesorul lui c
    }
    free(c);
}

// elibereaza cuvintele din memorie si reinitializeaza propozitia ca fiind vida

void Propozitie_elibereaza(Propozitie *p)
{
    Cuvant *c,*urm;
    for(c=p->prim;c;c=urm)
    {
        urm=c->urm;
        free(c);
    }
    Propozitie_init(p);
}

void inserare(Propozitie *p,char *text,char *text1)
{
    int ok=0;
    Cuvant *c=p->prim;
    Cuvant *pr;
    for(;c;c=c->urm)
    {
        if(!strcmp(text1,c->text))
        {
            Cuvant *a=Cuvant_nou(text);
            if(c==p->prim)
            {
                Propozitie_adauga_inceput(p,a);
                ok=1;
            }
            else
            {
                if(c->urm)
                {
                    a->pred=pr;
                    a->urm=c;
                    pr->urm=a;
                    c->pred=a;
                    ok=1;
                }
                else
                {
                    if(ok==0)
                        Propozitie_adauga(p,c);
                }
            }
        }
        pr=c;
    }
}

int main()
{
    Propozitie p;
    int op; // optiune
    char text[16],text2[16];
    Cuvant *c;
    Propozitie_init(&p); // initializare propozitie vida
    do
    {   
        printf("1 - propozitie noua\n");
        printf("2 - afisare\n");
        printf("3 - inserare cuvant\n");
        printf("4 - stergere cuvant\n");
        printf("5 - iesire\n");
        printf("optiune: ");scanf("%d",&op);
        switch(op)
        {
            case 1:
                Propozitie_elibereaza(&p); // elibereaza posibila propozitie anterioara
                for(;;)
                {
                    scanf("%s",text);
                    // intre ultimul cuvant si punct trebuie sa existe un spatiu, pentru ca punctul sa fie considerat separat
                    if(!strcmp(text,"."))break; // atentie: "." este un sir de caractere, nu o litera (char)
                    Cuvant *c=Cuvant_nou(text);
                    Propozitie_adauga(&p,c);
                }
            break;
            case 2:
                for(c=p.prim;c;c=c->urm)
                    printf("%s ",c->text);
                  
                printf(".\n");
            break;
            case 3:
                scanf("%15s",text);
                scanf("%15s",text2);
                inserare(&p,text,text2);
                break;
            case 4:
                printf("cuvant de sters:");
                scanf("%s",text);
                c=Propozitie_cauta(&p,text);
                if(c)
                {  
                    Propozitie_sterge(&p,c);
                }   
                else
                {
                    printf("cuvantul \"%s\" nu se gaseste in propozitie\n",text);
                }
                break;
            case 5:
            break;
            default:
                printf("optiune invalida");
        }
    }
    while(op!=5);
    return 0;
}