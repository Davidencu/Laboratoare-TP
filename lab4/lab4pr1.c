#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define CHUNK 10

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