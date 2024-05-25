#include<stdio.h>
#include<stdlib.h>

void friends(int n,int a[][n])
{
    int f;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("Dati prietenii lui %d : ",i);
        while(scanf("%d",&f) && f!=-1)
        {
            a[i][f]=1;
        }
    }
}

void count(int n, int a[][n])
{
    int cnt;
    for(int i=0;i<n;i++)
    {
        cnt=0;
        for(int j=0;j<n;j++)
        {
            cnt+=a[i][j];
        }
        if (cnt!=1)
        {
            printf("Persoana %d are %d prieteni\n",i,cnt);
        }
        else
        {
            printf("Persoana %d are 1 prieten\n",i);
        }
    }
}

int main(void)
{
    int n;
    printf("Dati nr. de persoane: ");
    scanf("%d",&n);
    int a[n][n];
    friends(n,a);
    count(n,a);
    return 0;
}