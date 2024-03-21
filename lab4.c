#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CHUNK 10

// problema 4.0

typedef struct
{
    char nume[21];
    int nota;
}elev;

int main(void)
{
    elev e;
    if(fgets(e.nume,21,stdin)!=NULL)
    {
        scanf("%d",&(e.nota));
        printf("%s\n%d\n",e.nume,e.nota);
    }
    return 0;
}

//problema 4.1

typedef struct
{
    char nume[16];
    unsigned int numar:11;
    unsigned int tip:2;    //0 - .txt, 1 - .doc,2 - .xls
    unsigned int tipar:1;  //0 - normal,1 - read-only
}fisier;

int main(void)
{
    fisier f;
    char s[16];
    int aux=0,aux1=0,aux2=0;
    printf("Dati numele fisierului: ");
    if (fgets(s,16,stdin)!=NULL)
    {
        if(s[strlen(s)-1]=='\n')
        {
            s[strlen(s)-1]='\0';
        }
        printf("Dati datele fisierului\n");
        scanf("%d%d%d",&aux,&aux1,&aux2);
        strcpy(f.nume,s);
        f.numar=aux;
        f.tip=aux1;
        f.tipar=aux2;
        printf("Fisierul %s are %d octeti, este de tip ",f.nume,f.numar);
        switch(f.tip)
        {
            case 0:
                printf(".txt ");
                break;
            case 1:
                printf(".doc ");
                break;
            case 2:
                printf(".xls ");
                break;
        }
        printf("si are tipar ");
        switch(f.tipar)
        {
            case 0:
                printf("normal.\n");
                break;
            case 1:
                printf("read-only.\n");
                break;
        }
    }
    return 0;
}

//problema 4.2

typedef struct
{
    char nume[16];
    unsigned int numar:11;
    unsigned int tip:2;    //0 - .txt, 1 - .doc,2 - .xls
    unsigned int tipar:1;  //0 - normal,1 - read-only
}fisier;

void citire(fisier *f,int size)
{
    char s[16];
    int aux=0,aux1=0,aux2=0;
    for(int i=0;i<size;i++)
    {
        printf("Dati numele fisierului: ");
        if (i!=0) {getchar();}
        if (fgets(s,16,stdin)!=NULL)
        {
            if(s[strlen(s)-1]=='\n')
            {
                s[strlen(s)-1]='\0';
            }
            printf("Dati datele fisierului\n");
            scanf("%d%d%d",&aux,&aux1,&aux2);
            strcpy((f+i)->nume,s);
            (f+i)->numar=aux;
            (f+i)->tip=aux1;
            (f+i)->tipar=aux2;
        }
    }
}

void afisare(fisier *f,int size,FILE *fp)
{
    for(int i=0;i<size;i++)
    {
        fprintf(fp,"Fisierul %s are %d octeti, este de tip ",(f+i)->nume,(f+i)->numar);
        switch((f+i)->tip)
        {
            case 0:
                fprintf(fp,"%s",".txt ");
                break;
            case 1:
                fprintf(fp,"%s",".doc ");
                break;
            case 2:
                fprintf(fp,"%s",".xls ");
                break;
        }
        fprintf(fp,"si are tipar ");
        switch((f+i)->tipar)
        {
            case 0:
                fprintf(fp,"normal.\n");
                break;
            case 1:
                fprintf(fp,"read-only.\n");
                break;
        }
    }
}

int main(void)
{
    FILE *fp=NULL;
    if((fp=fopen("memorie.txt","w"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    int size=0;
    printf("Dati numarul de fisiere: ");
    scanf("%d",&size);
    fisier f[size];
    citire(f,size);
    afisare(f,size,fp);
    if(fclose(fp)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}

//problema 4.3

typedef struct
{
    char nume[16];
    unsigned int numar:11;
    unsigned int tip:2;    //0 - .txt, 1 - .doc,2 - .xls
    unsigned int tipar:1;  //0 - normal,1 - read-only
}fisier;

fisier *citire(int size)
{
    fisier *f=NULL;
    char s[16];
    int aux=0,aux1=0,aux2=0,i=0,cs=0;
    while(i<size)
    {
        if(i==cs)
        {
            cs=cs+CHUNK;
            if((f=(fisier *)realloc(f,cs*sizeof(fisier)))==NULL)
            {
                perror(NULL);
                exit(-1);
            }
        }
        printf("Dati numele fisierului: ");
        getchar();
        if (fgets(s,16,stdin)!=NULL)
        {
            if(s[strlen(s)-1]=='\n')
            {
                s[strlen(s)-1]='\0';
            }
            printf("Dati datele fisierului\n");
            scanf("%d%d%d",&aux,&aux1,&aux2);
            strcpy((f+i)->nume,s);
            (f+i)->numar=aux;
            (f+i)->tip=aux1;
            (f+i)->tipar=aux2;
        }
        i++;
    }
    return f;
}

void afisare(fisier *f,int size,FILE *fp)
{
    for(int i=0;i<size;i++)
    {
        fprintf(fp,"Fisierul %s are %d octeti, este de tip ",(f+i)->nume,(f+i)->numar);
        switch((f+i)->tip)
        {
            case 0:
                fprintf(fp,".txt ");
                break;
            case 1:
                fprintf(fp,".doc ");
                break;
            case 2:
                fprintf(fp,".xls ");
                break;
        }
        fprintf(fp,"si are tipar ");
        switch((f+i)->tipar)
        {
            case 0:
                fprintf(fp,"normal.\n");
                break;
            case 1:
                fprintf(fp,"read-only.\n");
                break;
        }
    }
}

int main(void)
{
    FILE *fp=NULL;
    if((fp=fopen("memorie.txt","w"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    int size=0;
    printf("Dati numarul de fisiere: ");
    scanf("%d",&size);
    fisier *f=citire(size);
    afisare(f,size,fp);
    if(fclose(fp)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    free(f);
    return 0;
}

//problema 4.4

typedef struct
{
    unsigned int nr_picioare:10;
    unsigned int varsta:11;
    unsigned int pericol:1;
    char specie[9];
    float greutate;
} animal;

int main()
{
    animal a;
    int aux=0,aux1=0,aux2=0;
    printf("Dati nr. de picioare: ");
    scanf("%d",&aux);
    printf("Dati varsta: ");
    scanf("%d",&aux1);
    printf("Dati greutatea: ");
    scanf("%f",&(a.greutate));
    printf("Dati 1 daca animalul este periculos, altfel 0: ");
    scanf("%d",&aux2);
    printf("Dati specia: ");
    getchar();
    if(fgets(a.specie,9,stdin)==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    if(a.specie[strlen(a.specie)-1]=='\n')
    {
        a.specie[strlen(a.specie)-1]='\0';
    }
    a.nr_picioare=aux;
    a.varsta=aux1;
    a.pericol=aux2;
    printf("Animalul are %d picioare, are %d ani,are o greutate de %.01f kilograme,face parte din specia %s si ",a.nr_picioare,a.varsta,a.greutate,a.specie);
    switch(a.pericol)
    {
        case 1:
            printf("este periculos.\n");
            break;
        case 0:
            printf("nu este periculos.\n");
            break;
    }
    printf("Dimensiunea structurii este de %ld bytes\n",sizeof(animal));
    return 0;
}

//problema 4.5

typedef struct
{
    unsigned int grad:2;
    unsigned int reteta:1;
    unsigned int varsta_min:5;
}medicament;

void citire(medicament *m)
{
    int aux=0,aux1=0,aux2=0;
    printf("Dati gradul de periculozitate: ");
    scanf("%d",&aux);
    printf("Scrieti 1 daca se elibereaza doar pe baza de reteta,altfel 0 ");
    scanf("%d",&aux1);
    printf("Dati varsta minima de administrare: ");
    scanf("%d",&aux2);
    m->grad=aux;
    m->reteta=aux1;
    m->varsta_min=aux2;
}

void afisare(medicament *m)
{
    switch(m->grad)
    {
        case 0:
            printf("scazuta, ");
            break;
        case 1:
            printf("medie, ");
            break;
        case 2:
            printf("mare, ");
            break;
    }
    switch(m->reteta)
    {
        case 0:
            printf("nu se elibereaza pe baza de reteta, ");
            break;
        case 1:
            printf("se elibereaza doar pe baza de reteta, ");
            break;
    }
    printf("varsta minima de administrare este de %d ani.\n",m->varsta_min);
}

int main(void)
{
    medicament paracetamol;
    citire(&paracetamol);
    afisare(&paracetamol);
    return 0;
}

//problema 4.6

typedef struct
{
    unsigned int valoare:10;
    unsigned int unitate:2;
    unsigned int m:4;
} masuratoare;

void citire(masuratoare *a)
{
    long val;
    char s[6];
    int aux=0,nr=0;
    printf("Dati valoarea ");
    scanf("%ld",&val);
    printf("Dati unitatea ");
    getchar();
    if(fgets(s,6,stdin)==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    if(s[strlen(s)-1]=='\n')
    {
        s[strlen(s)-1]='\0';
    }
    if(strcmp(s,"gram")==0)
    {
        aux=0;
    }
    if(strcmp(s,"metru")==0)
    {
        aux=1;
    }
    if(strcmp(s,"litru")==0)
    {
        aux=2;
    }
    a->unitate=aux;
    while(val>=1024)
    {
        if (nr<3) val=val/10;
        else val=val/1000;
        nr++;
        if (nr>5)
        {
            printf("eroare\n");
            exit(-1);
        }
    }
    if (nr!=0) 
    {
        a->m=nr+5;
    }
    else
    {
        a->m=nr;
    }
    a->valoare=val;
}

void afisare(masuratoare *a)
{
    printf("%d ",a->valoare);
    switch(a->m)
    {
        case 0:
            break;
        case 1:
            printf("pico");
            break;
        case 2:
            printf("nano");
            break;
        case 3:
            printf("mili");
            break;
        case 4:
            printf("centi");
            break;
        case 5:
            printf("deci");
            break;
        case 6:
            printf("deca");
            break;
        case 7:
            printf("hecto");
            break;
        case 8:
            printf("kilo");
            break;
        case 9:
            printf("mega");
            break;
        case 10:
            printf("giga");
            break;
    }
    switch(a->unitate)
    {
        case 0:
            printf("gram\n");
            break;
        case 1:
            printf("metru\n");
            break;
        case 2:
            printf("litru\n");
            break;
    }
}

int main(void)
{
    masuratoare a;
    citire(&a);
    afisare(&a);
    return 0;
}

//problema 1 proiect

typedef struct
{
    unsigned int cod:14;
    unsigned int locuri:4;
    unsigned int putere:9;
    unsigned int an:8;
    char marca[15];
    char culoare[9];
}masina;

void f1(masina *m,int *size)
{
    int a0=0,a1=0,a2=0,a3=0;
    printf("Dati codul: ");
    scanf("%d",&a0);
    printf("Dati nr. de locuri: ");
    scanf("%d",&a1);
    printf("Dati puterea: ");
    scanf("%d",&a2);
    printf("Dati anul fabricatiei: ");
    scanf("%d",&a3);
    (m+*size)->cod=a0;
    (m+*size)->locuri=a1;
    (m+*size)->putere=a2;
    (m+*size)->an=a3-1800;
    printf("Dati marca: ");
    getchar();
    fgets((m+*size)->marca,15,stdin);
    if((m+*size)->marca[strlen((m+*size)->marca)-1]=='\n')
    {
        (m+*size)->marca[strlen((m+*size)->marca)-1]='\0';
    }
    printf("Dati culoarea: ");
    fgets((m+*size)->culoare,9,stdin);
    if((m+*size)->culoare[strlen((m+*size)->culoare)-1]=='\n')
    {
        (m+*size)->culoare[strlen((m+*size)->culoare)-1]='\0';
    }
    *size=*size+1;
}

void f2(masina *m,int *size)
{
    int cod;
    printf("Dati codul: ");
    scanf("%d",&cod);
    for(int i=0;i<*size;i++)
    {
        if ((m+i)->cod==cod)
        {
            for(int j=i;j<*size;j++)
            {
                m[j]=m[j+1];
            }
            i=i-1;
            *size=*size-1;
        }
    }
}

void f3(masina *m,int *size)
{
    for(int i=0;i<*size;i++)
    {
        printf("Masina nr %d are codul %d, are %d locuri,are %d cai,marca %s,este de culoare %s,si este fabricata in anul %d\n",i,(m+i)->cod,(m+i)->locuri,(m+i)->putere,(m+i)->marca,(m+i)->culoare,(m+i)->an+1800);
    }
}

void f4(masina *m,int *size)
{
    int l;
    printf("Dati nr. de locuri: ");
    scanf("%d",&l);
    for(int i=0;i<*size;i++)
    {
        if((m+i)->locuri==l)
        {
            printf("Masina nr %d are codul %d, are %d locuri,are %d cai,marca %s,este de culoare %s,si este fabricata in anul %d\n",i,(m+i)->cod,(m+i)->locuri,(m+i)->putere,(m+i)->marca,(m+i)->culoare,(m+i)->an+1800);
        }
    }
}

int f5(const void *elem1,const void *elem2)
{
    const masina *s1=(const masina *)elem1;
    const masina *s2=(const masina *)elem2;
    if (s1->an > s2->an)
    {
        return 1;
    }
    if (s1->an < s2->an)
    {
        return -1;
    }
    return 0;
}

int main(void)
{
    int n=10;
    printf("Dati numarul n de masini: ");
    scanf("%d",&n);
    masina m[n];
    int size=0;
    printf("1. Introducere automobil nou\n");
    printf("2. Stergere automobil dupa cod\n");
    printf("3. Afisare lista automobile\n");
    printf("4. Afisare automobile cu un anumit numar de locuri\n");
    printf("5. Sortare dupa anul fabricatiei\n");
    while(n!=0)
    {
        printf("Dati n: ");
        scanf("%d",&n);
        switch(n)
        {
            case 0:
                printf("Iesire\n");
                break;
            case 1:
                f1(m,&size);
                break;
            case 2:
                f2(m,&size);
                break;
            case 3:
                f3(m,&size);
                break;
            case 4:
                f4(m,&size);
                break;
            case 5:
                qsort(m,size,sizeof(masina),f5);
                break;
        }
    }
    return 0;
}

//problema 2 proiect

typedef union
{
    char isbn[14];
    int an;
}caracteristica;


typedef struct
{
    unsigned int nr_ex:10;
    unsigned int pret:9;
    unsigned int nr_pagini:10;
    unsigned int greutate:13;
    unsigned int tip:1;
    char titlu[16];
    char autor[16];
    caracteristica c;
}biblioteca;

void f1(biblioteca *b,int *size)
{
    int a0,a1,a2,a3,a4;
    char str[16];
    printf("Dati titlul: ");
    fgets((b+*size)->titlu,16,stdin);
    getchar();
    if((b+*size)->titlu[strlen((b+*size)->titlu)-1]=='\n')
    {
        (b+*size)->titlu[strlen((b+*size)->titlu)-1]='\0';
    }
    printf("Dati numele autorului: ");
    fgets(str,16,stdin);
    getchar();
    if(str[strlen(str)-1]=='\n')
    {
        str[strlen(str)-1]='\0';
    }
    getchar();
    strcpy((b+*size)->autor,str);
    printf("Dati numarul de exemplare: ");
    scanf("%d",&a0);
    printf("Dati pretul: ");
    scanf("%d",&a1);
    printf("Dati numarul de pagini: ");
    scanf("%d",&a2);
    printf("Dati greutatea: ");
    scanf("%d",&a3);
    printf("Dati 1 daca este carte si 0 daca este revista: ");
    scanf("%d",&a4);
    (b+*size)->nr_ex=a0;
    (b+*size)->pret=a1;
    (b+*size)->nr_pagini=a2;
    (b+*size)->greutate=a3;
    (b+*size)->tip=a4;
    switch((b+*size)->tip)
    {
        case 0:
            printf("Introduceti anul: ");
            scanf("%d",&(b+*size)->c.an);
            break;
        case 1:
            printf("Introduceti ISBN: ");
            fgets((b+*size)->c.isbn,14,stdin);
            getchar();
            if((b+*size)->c.isbn[strlen((b+*size)->c.isbn)-1]=='\n')
            {
                (b+*size)->c.isbn[strlen((b+*size)->c.isbn)-1]='\0';
            }
            break;
    }
    *size=*size+1;
}

void f2(biblioteca *b,int *size)
{
    for(int i=0;i<*size;i++)
    {
        if((b+i)->pret>100 && (b+i)->tip==1)
        {
            printf("%s de %s\n",(b+i)->titlu,(b+i)->autor);
        }
    }
}

void f3(biblioteca *b,int *size)
{
    for(int i=0;i<*size;i++)
    {
        printf("%d.\n%s de %s\nNumar de exemplare: %d\nPret: %d\nNumar de pagini: %d\nGreutate: %d g\n",i,(b+i)->titlu,(b+i)->autor,(b+i)->nr_ex,(b+i)->pret,(b+i)->nr_pagini,(b+i)->greutate);
        switch((b+i)->tip)
        {
            case 0:
                printf("Este reevista\n");
                printf("Anul aparitiei: %d\n",(b+i)->c.an);
                break;
            case 1:
                printf("Este carte\n");
                printf("%s",(b+i)->c.isbn);
                break;
        }
    }
}

int main()
{
    biblioteca b[10*CHUNK];
    int n=10,size=0;
    printf("1. Introducere carte noua\n");
    printf("2. Afisare cartile ale caror preturi > 100\n");
    printf("3. Afisare toate publicatiile\n");
    printf("4. Salvare in fisier\n");
    while(n!=0)
    {
        printf("Dati n: ");
        scanf("%d",&n);
        switch(n)
        {
            case 0:
                break;
            case 1:
                f1(b,&size);
                break;
            case 2:
                f2(b,&size);
                break;
            case 3:
                f3(b,&size);
                break;
            case 4:
                break;
        }
    }
    return 0;
}
