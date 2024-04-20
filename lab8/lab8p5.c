#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Să se implementeze o listă dublu înlănțuită care gestionează un parc de automobilee. Informaţiile
relative la un automobil sunt: codul mașinii (număr între 1 si 9000), numărul de locuri (între 1 și 9), puterea (în cai
putere între 1 și 500), marca, culoarea, anul fabricaţiei maşinii (între 1800 și 2017). Parcul conține n automobile,
datele sunt citite de la tastatură. Să se scrie următoarele funcții de gestiune a mașinilor:
a) Introducerea unui automobil nou în listă la începutul listei;
b) Ștergerea unui anumit automobil din listă, al cărui cod e citit de la tastatură;
c) Afișarea întregii liste pe ecran;
d) Afișarea pe ecran doar a obiectelor cu un anumit număr de locuri, citit de la tastatură;
e) Ordonarea listei în funcție de anul fabricației.
Să se definească structura pentru o mașină cu ajutorul structurilor cu câmpuri pe biți astfel încât spațiul ocupat să
fie minim.*/

typedef struct automobil
{    
    unsigned int cod:13;
    unsigned int locuri:3;
    unsigned int putere:9;
    unsigned int an:8;
    char marca[11];
    char culoare[11];
}automobil;

typedef struct obiect
{
    automobil a;
    struct obiect *pred;
    struct obiect *urm;
}
obiect;

obiect *obiect_nou(const char *text1,const char *text2,int cod,int l,int p,int an)
{
    obiect *c=(obiect*)malloc(sizeof(obiect));
    if(!c)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    strcpy(c->a.marca,text1);
    strcpy(c->a.culoare,text2);
    c->a.cod=cod;
    c->a.locuri=l;
    c->a.putere=p;
    c->a.an=an-1800;
    return c;
}

typedef struct
{
    obiect *prim;
    obiect *ultim;
}lista;

void lista_init(lista *p)
{
    p->prim=p->ultim=NULL;
}

void lista_adauga(lista *p,obiect *c)
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

void lista_sterge(lista *p,obiect *c)
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

obiect *lista_cauta(lista *p,int cod)
{
    obiect *c;
    for(c=p->prim;c;c=c->urm)
    {
        if (c->a.cod==cod) return c;
    }
    return NULL;
}


void afisare(lista *p)
{
    obiect *c;
    for(c=p->prim;c;c=c->urm)
    {
        printf("obiectul cu codul %d are marca %s, este de culoare %s,are %d locuri, %d cai putere si este fabricat in anul %d\n",c->a.cod,c->a.marca,c->a.culoare,c->a.locuri,c->a.putere,c->a.an+1800);
    }
}

void afisare_cond(lista *p,int l)
{
    obiect *c;
    for(c=p->prim;c;c=c->urm)
    {
        if(c->a.locuri==l)
        printf("obiectul cu codul %d are marca %s, este de culoare %s,are %d locuri, %d cai putere si este fabricat in anul %d\n",c->a.cod,c->a.marca,c->a.culoare,c->a.locuri,c->a.putere,c->a.an+1800);
    }
}

void sortare(lista *p)
{
    obiect *c;
    automobil aux;
    int s;
    do{
		s = 0;                             // setam faptul ca nu au avut loc schimbari la iterarea curenta
		for (c=p->prim->urm;c;c=c->urm)
		{      
			// @1 - pornim de la 1 ca sa formam perechi (v[i-1],v[i])
			if (c->pred->a.an > c->a.an)
			{             
				// daca valorile NU respecta relatia de ordine
				aux = c->pred->a;                 // interschimba valorile
				c->pred->a= c->a;
				c->a = aux;
				s = 1;                             // @2 - seteaza faptul ca a avut loc cel putin o schimbare
			}
		}
	} while (s);  
}

void lista_elibereaza(lista *p)
{
    obiect *c,*urm;
    for(c=p->prim;c;c=urm)
    {
        urm=c->urm;
        free(c);
    }
    lista_init(p);
}

int main()
{
    lista p;
    obiect *c;
    int nr=0,cod,l,pu,an;
    char text1[11],text2[11];
    lista_init(&p);
    do
    {
        printf("1. Introducere obiect nou\n");
        printf("2. Stergere obiect\n");
        printf("3. Afisarea intregii liste\n");
        printf("4. Afisare obiecte cu un anumit numar de locuri\n");
        printf("5. Sortare dupa anul fabricatiei\n");
        printf("6. Iesire\n");
        printf("optiune: ");
        scanf("%d",&nr);
        switch(nr)
        {
            case 1:
                printf("Dati marca: ");
                scanf("%10s",text1);
                printf("Dati culoarea: ");
                scanf("%10s",text2);
                printf("Dati codul: ");
                scanf("%d",&cod);
                printf("Dati nr locuri: ");
                scanf("%d",&l);
                printf("Dati puterea: ");
                scanf("%d",&pu);
                printf("Dati anul fabricatiei: ");
                scanf("%d",&an);
                c=obiect_nou(text1,text2,cod,l,pu,an);
                lista_adauga(&p,c);
            break;
            case 2:
                printf("Dati codul: ");
                scanf("%d",&cod);
                c=lista_cauta(&p,cod);
                if(c)
                {  
                    lista_sterge(&p,c);
                }   
                else
                {
                    printf("automobilul \"%d\" nu se gaseste in propozitie\n",c->a.cod);
                }
                break;
            case 3:
                afisare(&p);
            break;
            case 4:
                printf("Dati nr locuri: ");
                scanf("%d",&l);
                afisare_cond(&p,l);
            break;
            case 5:
                sortare(&p);
            break;
            case 6:
                lista_elibereaza(&p);
            break;
        }
    } while (nr!=6);
    
    return 0;
}