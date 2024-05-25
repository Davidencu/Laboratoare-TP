#include<stdio.h>

//Se citesc doua numere naturale n si k. Generati si afisati toate toate numerele naturale formate din
//n cifre care contin exact k cifre de 1.

int valid(int *a,int k,int n,int cnt)
{
    int nr=0;
    for(int j=0;j<=k;j++)
    {
        if(a[0]==0)
        {
            return 0;
        }
        if(a[j]==1)
        {
            nr++;
        }
    }
    if (nr>cnt || k>n-1)
    {
        return 0;
    }
    return 1;
}

int solutie(int *a,int k,int n,int cnt)
{
    int nr=0;
    for(int j=0;j<=k;j++)
    {
        if(a[j]==1)
        {
            nr++;
        }
    }
    if (k==n-1 && nr==cnt)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void afisare(int *a,int k,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void back(int *a,int k,int n,int cnt)
{
    for(int i=0;i<10;i++)
    {
        a[k]=i;
        if (valid(a,k,n,cnt))
        {
            if (solutie(a,k,n,cnt))
            {
                afisare(a,k,n);
            }
            else
            {
                back(a,k+1,n,cnt);
            }
        }
    }
}

int main()
{
    int n,k;
    printf("Dati n si k: ");
    scanf("%d%d",&n,&k);
    int a[n];
    back(a,0,n,k);
    return 0;
}
