#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CHUNK 10

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