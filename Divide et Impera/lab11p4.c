#include<stdio.h>

//Se consideră o matrice cu m linii și n coloane, numere naturale. Folosind
//metoda Divide et Impera, determinați suma numerelor pare din matrice

int suma(int a1,int a2,int z1,int z2,int n,int a[][n])
{
    int aux1,aux2,e1,e2,m1,m2,m3,m4;
    e1=n*a1+a2;
    e2=n*z1+z2;
    int mij=(e1+e2)/2;
    if(e1==e2)
    {
        if(!(a[a1][a2]%2))
        {
            return a[a1][a2];
        }
        else
        {
            return 0;
        }
    }
    else
    {
        m1=mij/n;
        m2=mij%n;
        m3=(mij+1)/n;
        m4=(mij+1)%n;
        aux1=suma(a1,a2,m1,m2,n,a);
        aux2=suma(m3,m4,z1,z2,n,a);
        return aux1+aux2;
    }
}

void citire(int m,int n,int v[][n])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("v[%d][%d]=",i,j);
            scanf("%d",&v[i][j]);
        }
    }
}

int main()
{
    int m,n;
    printf("Dati m si n: ");
    scanf("%d%d",&m,&n);
    int v[m][n];
    citire(m,n,v);
    printf("suma este %d\n",suma(0,0,m-1,n-1,n,v));
    return 0;
}
