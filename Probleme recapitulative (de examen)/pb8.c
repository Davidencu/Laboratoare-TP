#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

typedef struct //notatiile p[i].nume si (p+i)->nume sunt echivalente
{
    unsigned int zi:5;
    unsigned int luna:4;
    unsigned int an:11;
}data_nasterii;

typedef union
{
    unsigned int nrcopii:5;
    unsigned int timp:7;
    char init[2];
    double inaltime;
}caracteristica;

typedef struct
{
    unsigned int sc:2;
    char nume[21];
    char prenume[21];
    data_nasterii dn;
    caracteristica c;
}persoana;

void citire(persoana *p,int n,FILE *fp)
{
    int aux1,aux2,aux3,aux4,aux5;
    float aux6;
    char aux7;
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&aux1);
        p[i].sc=aux1;
        fscanf(fp,"%20s",(p+i)->nume);
        fscanf(fp,"%20s",(p+i)->prenume);
        fscanf(fp,"%d",&aux2);
        p[i].dn.zi=aux2;
        fscanf(fp,"%d",&aux3);
        p[i].dn.luna=aux3;
        fscanf(fp,"%d",&aux4);
        p[i].dn.an=aux4;
        switch((p+i)->sc)
        {
            case 0:
                fscanf(fp,"%d",&aux5);
                (p+i)->c.nrcopii=aux5;
                break;
            case 1:
                fscanf(fp,"%f",&aux6);
                (p+i)->c.inaltime=aux6;
                break;
            case 2:
                fscanf(fp,"%d",&aux5);
                (p+i)->c.timp=aux5;
                break;
            case 3:
                fscanf(fp,"%1s",&aux7);
                (p+i)->c.init[0]=aux7;
                (p+i)->c.init[1]='\0';
                break;
            default:
                break;
        }
    }
}

int varsta(int zi,int luna,int an)
{
    int aux;
    aux=(2024-an)*365+(6-luna)*30+(13-zi);
    return aux/365;
}

void afisare(persoana *p,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\n");
        int v=varsta(p[i].dn.zi,p[i].dn.luna,p[i].dn.an);
        printf("persoana care poseda numele %s si prenumele %s\neste nascuta in data %d.%d.%d (avand %d ani)\neste ",(p+i)->nume,(p+i)->prenume,(p+i)->dn.zi,(p+i)->dn.luna,(p+i)->dn.an,v);
        switch((p+i)->sc)
        {
            case 0:
                printf("casatorita avand %d copii\n",(p+i)->c.nrcopii);
                break;
            case 1:
                printf("necasatorita avand inaltimea %f cm\n",(p+i)->c.inaltime);
                break;
            case 2:
                printf("divortata de %d ani\n",(p+i)->c.timp);
                break;
            case 3:
                printf("vaduva avand initiala fostului partener %c\n",(p+i)->c.init[0]);
                break;
        }
    }
}



int main()
{
    FILE *fp=NULL;
    
    if((fp=fopen("DATE.TXT","r"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    int n;
    fscanf(fp,"%d",&n);
    persoana p[n];
    citire(p,n,fp);
    afisare (p,n);
    if(fclose(fp)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}