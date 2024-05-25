#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//tema 2

//problema 1

typedef struct
{
    char nume[20];
    int nota;
} S;

void citire(S *pt,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Dati numele: ");
        getchar();
        fgets(pt[i].nume,20,stdin);
        if(pt[i].nume[strlen(pt[i].nume)-1]=='\n')
        {
            pt[i].nume[strlen(pt[i].nume)-1]=0;
        }
        printf("Dati nota: ");
        scanf("%d",&pt[i].nota);
    }
}

int comp(const void *elem1,const void *elem2)
{
    int a=0;
    const S *p1=(const S*)elem1;
    const S *p2=(const S*)elem2;
    if (p1->nota>p2->nota)
    {
        return -1;
    }
    else
    {
        if (p1->nota < p2 ->nota)
        {
            return 1;
        }
        else
        {
            a= strcmp(p1->nume,p2->nume);
            return a;
        }
    }
}



int main(void)
{
    int n;
    printf("Dati n: ");
    scanf("%d",&n);
    S student[n];
    citire(student,n);
    qsort(student,n,sizeof(S),comp);
    for(int i=0;i<n;i++)
    {
        printf("%s, %d\n",student[i].nume,student[i].nota);
    }
    return 0;
}
