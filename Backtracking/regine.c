#include<stdio.h>

//Să se plaseze n regine pe o tablă de şah de dimensiune nxn astfel încât oricare două
//regine să nu se atace. Conform regulilor de şah două regine se atacă dacă sunt pe
//aceeaşi linie, coloană sau diagonală

void init(int m,int n,int a[][n])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
}

int valid(int n,int *v,int k)
{
    for(int i=0;i<k;i++)
    {
        if ((v[i]==v[k]) || (v[i]==v[k]+(k-i)) || (v[i]==v[k]-(k-i)))
        {
            return 0;
        }
    }
    if(k>n-1)
    {
        return 0;
    }
    return 1;
}

int solutie(int n,int *v,int k)
{
    if(k==n-1)
    {
        return 1;
    }
    return 0;
}

void afisare(int n,int a[][n],int *v,int k)
{
    init(n,n,a);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==v[i])
            {
                a[i][j]=1;
            }
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------\n");
}

void back(int n,int a[][n],int *v,int k)
{
    for(int i=0;i<n;i++)
    {
        v[k]=i;
        if(valid(n,v,k))
        {
            if(solutie(n,v,k))
            {
                afisare(n,a,v,k);
            }
            else
            {
                back(n,a,v,k+1);
            }
        }
    }
}

int main()
{
    int n;
    printf("Dati nr de regine: ");
    scanf("%d",&n);
    int a[n][n],v[n];
    init(n,n,a);
    back(n,a,v,0);
    return 0;
}