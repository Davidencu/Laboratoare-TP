#include<stdio.h>

//sa se implementeze algoritmul mergesort folosind divide et impera

int v[100],a[100];

void sort(int st,int dr)
{
    int mij=(st+dr)/2;
    if(st >= dr)
    {
        return;
    }
    else
    {
        sort(st,mij);
        sort(mij+1,dr);
        int aux1=st;
        int aux2=mij+1; 
        int aux=0;
        while(aux1<=mij && aux2<=dr)
        {
            if(v[aux1]<v[aux2])
            {
                a[aux]=v[aux1];
                aux++; aux1++;
            }
            else
            {
                a[aux]=v[aux2];
                aux++; aux2++;
            }
        }
        while(aux1<=mij)
        {
            a[aux]=v[aux1];
            aux++;
            aux1++;
        }
        while(aux2<=dr)
        {
            a[aux]=v[aux2];
            aux++;
            aux2++;
        }
        for(int i=st;i<=dr;i++)
        {
            v[i]=a[i-st];
        }
    }
}

int main()
{
    int n;
    printf("n=");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("v[%d]=",i);
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