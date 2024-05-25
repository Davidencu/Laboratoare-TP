#include<stdio.h>

//Scrieți un program care afișează toate posibilitatile de a aranja elementele unui
//vector întreg astfel incat în șirul rezultat să nu existe 2 numere negative alaturate

int valid(int *a,int *v,int n,int k)
{
    for(int i=1;i<k;i++)
    {
        if((a[i]==a[k]))  //verificam daca indicii sunt ordonati crescator
        {
            return 0;
        }
    }
    if(k>1 && v[a[k]]<0 && v[a[k-1]]<0)
    {
        return 0;
    }
    if(k>n)
    {
        return 0;
    }
    return 1;
}

int solutie(int *a,int *v,int n,int k)
{
    if(k==n)
    {
        return 1;
    }
    return 0;
}

void afisare(int *a,int *v,int n,int k)
{
    for(int i=1;i<=k;i++)
    {
        printf("%d ",v[a[i]]);
    }
    printf("\n");
}

void back(int *a,int *v,int n,int k)
{
    for(int i=1;i<=n;i++)
    {
        a[k]=i;
        if(valid(a,v,n,k))
        {
            if(solutie(a,v,n,k))
            {
                afisare(a,v,n,k);
            }
            else
            {
                back(a,v,n,k+1);
            }
        }
    }
}

int main()
{
    int n;
    printf("Dati n: ");
    scanf("%d",&n);
    int a[n+1],v[n+1];
    for(int i=1;i<=n;i++)
    {
        printf("v[%d]=",i);
        scanf("%d",&v[i]);
    }
    back(a,v,n,1);
    return 0;
}