#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CHUNK 10

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