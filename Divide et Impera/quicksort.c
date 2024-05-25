#include<stdio.h>

//Sa se implementeze algoritmul quicksort folosind divide et impera

int v[1001],a1[1001],a2[1001];

void sort(int st,int dr)
{
    int aux1=0,aux2=0,aux=v[dr];
    if(st>=dr)
    {
        return;
    }
    else
    {
    for(int i=st;i<dr;i++)
    {
        if(v[i]<v[dr])
        {
            a1[aux1++]=v[i];
        }
        else
        {
            a2[aux2++]=v[i];
        }
    }
    for(int i=0;i<aux1;i++)
    {
        v[i+st]=a1[i];
    }
    v[aux1+st]=aux;
    for(int i=0;i<aux2;i++)
    {
        v[i+st+aux1+1]=a2[i];
    }
    sort(st,st+aux1-1);
    sort(st+aux1+1,dr);
    }
}

int main()
{
    int n;
    printf("Dati n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("v[%i]=",i);
        scanf("%d",&v[i]);
    }
    sort(0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
    return 0;
}