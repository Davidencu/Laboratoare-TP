#include<stdio.h>
#include<stdlib.h>

void read_matrix(int m,int n,int a[][n])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}

void multiply(int m,int n,int p,int a[][n], int b[][p],int c[][p])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<p;j++)
        {
            c[i][j]=0;
            for(int k=0;k<n;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}

void print(int m,int n,int a[][n])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int m,n,p;
    printf("Dati m,n si p ");
    scanf("%d %d %d",&m,&n,&p);
    int a[m][n],b[n][p],c[m][p];
    read_matrix(m,n,a);
    read_matrix(n,p,b);
    multiply(m,n,p,a,b,c);
    print(m,p,c);
    return 0;
}