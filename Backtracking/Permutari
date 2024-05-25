#include<stdio.h>

//sa se genereze toate permutarile unui vector de n elemente date de la tastatura

int valid(int *v,int *a,int k,int n)
{
    for(int j=0;j<k;j++)
    {
        if(a[j]==a[k])
        {
            return 0;
        }
    }
    if (k>n)
    {
        return 0;
    }
    return 1;
}

int solutie(int *v,int *a,int k,int n)
{
    if (k==n-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void afisare(int *v,int *a,int k,int n)
{
    int aux;
    for(int i=0;i<n;i++)
    {
        aux=a[i];
        printf("%d ",v[aux]);
    }
    printf("\n");
}

void back(int *v,int *a,int k,int n)
{
    for(int i=0;i<n;i++)
    {
        a[k]=i;
        if (valid(v,a,k,n))
        {
            if (solutie(v,a,k,n))
            {
                afisare(v,a,k,n);
            }
            else
            {
                back(v,a,k+1,n);
            }
        }
    }
}

int main()
{
    int n;
    printf("Dati n: ");
    scanf("%d",&n);
    int v[n],a[n+1];
    for(int i=0;i<n;i++)
    {
        printf("v[%d]=",i);
        scanf("%d",&v[i]);
    }
    back(v,a,0,n);
    return 0;
}
