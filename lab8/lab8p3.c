#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cuvant
{
    char text[101]; // max 100 litere+terminator
    struct Cuvant *pred; // inlantuire la predecesor
    struct Cuvant *urm; // inlantuire la urmator
}Cuvant;

/*Să se scrie un program care primește un nume de fișier în linia de comandă. Programul va citi toate
liniile din fișier într-o listă care este mereu sortată în ordine alfabetică. O linie poate avea maxim 1000 de caractere.
Pentru ca lista să fie mereu sortată alfabetic, adăugarea unei linii noi se face prin inserarea ei la poziția corectă din
listă, astfel încât să se mențină proprietatea de sortare. În final se va afișa lista.*/

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

void Propozitie_adauga_sfarsit(Propozitie *p,Cuvant *c)
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

void insert(Propozitie *p,char *text)
{
    Cuvant *c=p->prim,*u,*a=Cuvant_nou(text);
    if(p->prim==NULL)
    {
        Propozitie_adauga_sfarsit(p,a);
    }
    else
    {
        u=c->urm;
        if(strcmp(a->text,p->prim->text)<0)
        {
            Propozitie_adauga_inceput(p,a);
        }
        while(c&&u)
        {
            if(strcmp(a->text,c->text)>0 && strcmp(a->text,u->text)<0)
            {
                a->urm=u;
                a->pred=c;
                c->urm=a;
                u->pred=a;
            }
            c=u;
            u=c->urm;
        }
        if(strcmp(a->text,p->ultim->text)>0)
        {
            Propozitie_adauga_sfarsit(p,a);
        }
    }
}

void afisare(Propozitie *p)
{
    Cuvant *c;
    for(c=p->prim;c;c=c->urm)
    {
        printf("%s",c->text);
    }
}

int main()
{
    FILE *fp=NULL;
    Propozitie p;
    char s[1001];
    if((fp=fopen("data.txt","r"))==NULL)
    {
        perror(NULL);
        exit(EXIT_FAILURE);
    }
    Propozitie_init(&p);
    while(fgets(s,1001,fp)!=NULL)
    {
        insert(&p,s);
    }
    afisare(&p);
    Propozitie_elibereaza(&p);
    if(fclose(fp)!=0)
    {
        perror(NULL);
        exit(EXIT_FAILURE);
    }
    return 0;
}