#include<stdio.h>

//Să se genereze toate funcţiile injective f:{1,2,…,n}--> {1,2,…,m}

int valid(int *a,int m,int n,int k)
{
    for(int i=1;i<k;i++)
    {
        if(a[i]==a[k])
        {
            return 0;
        }
    }
    if(k>n)
    {
        return 0;
    }
    return 1;
}

int solutie(int *a,int m,int n,int k)
{
    if(k==n)
    {
        return 1;
    }
    return 0;
}

void afisare(int *a,int m,int n,int k)
{
    for(int i=1;i<=k;i++)
    {
        printf("f(%d)=%d\n",i,a[i]);
    }
    printf("................\n");
}

void back(int *a,int m,int n,int k)
{
    for(int i=1;i<=m;i++)
    {
        a[k]=i;
        if(valid(a,m,n,k))
        {
            if(solutie(a,m,n,k))
            {
                afisare(a,m,n,k);
            }
            else
            {
                back(a,m,n,k+1);
            }
        }
    }
}

int main()
{
    int n,m;
    printf("Dati m si n: ");
    scanf("%d%d",&m,&n);
    int a[n+1];
    back(a,m,n,1);
    return 0;
}