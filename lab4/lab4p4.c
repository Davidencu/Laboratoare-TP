#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CHUNK 10

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