#include<stdio.h>

//sa se genereze toate combinarile de n luate cate k ale unui vector de n elemente date de la tastatura

int valid(int *v,int *a,int k,int n,int k0)
{
    for(int j=0;j<k;j++)
    {
        if(a[j]>=a[k])
        {
            return 0;
        }
    }
    if (k>k0-1)
    {
        return 0;
    }
    return 1;
}

int solutie(int *v,int *a,int k,int n,int k0)
{
    if (k==k0-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void afisare(int *v,int *a,int k,int n,int k0)
{
    int aux;
    for(int i=0;i<k0;i++)
    {
        aux=a[i];
        printf("%d ",v[aux]);
    }
    printf("\n");
}

void back(int *v,int *a,int k,int n,int k0)
{
    for(int i=0;i<n;i++)
    {
        a[k]=i;
        if (valid(v,a,k,n,k0))
        {
            if (solutie(v,a,k,n,k0))
            {
                afisare(v,a,k,n,k0);
            }
            else
            {
                back(v,a,k+1,n,k0);
            }
        }
    }
}

int main()
{
    int n,k0;
    printf("Dati n si k: ");
    scanf("%d%d",&n,&k0);
    int v[n],a[n+1];
    for(int i=0;i<n;i++)
    {
        printf("v[%d]=",i);
        scanf("%d",&v[i]);
    }
    back(v,a,0,n,k0);
    return 0;
}