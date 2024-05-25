#include<stdio.h>

int sgn(int a,int b)
{
    int nr;
    if (a>b)
        nr=1;
    else
        {
            if (a<b)
                nr=-1;
            else
                nr=0;
        }
    return nr;
}

int verif(int a,int z,int alt,int *v) //alt poate fi 1 sau -1
{
    int c=(a+z)/2;
    int aux1,aux2;
    if (a==z)
    {
        return alt;
    }
    else
    {
        aux1=verif(a,c,alt,v);
        aux2=verif(c+1,z,alt,v);
        return alt * (aux1==aux2 && aux1==sgn(v[c],v[c+1]) && aux1==alt);
    }
}

int main()
{
    int n,aux1=0,aux2=0;
    printf("Dati n: ");
    scanf("%d",&n);
    int v[n];
    for(int i=0;i<n;i++)
    {
        printf("v[%d]=",i);
        scanf("%d",&v[i]);
    }
    aux1=verif(0,n-1,-1,v);
    aux2=verif(0,n-1,1,v);
    if (aux1==-1)
    {
        printf("Sirul este ordonat crescator\n");
    }
    else
    {
        if (aux2==1)
        {
            printf("Sirul este ordonat descrescator\n");
        }
        else
        {
            printf("Sirul nu este ordonat\n");
        }
    }
    return 0;
}