#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CHUNK 10

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