#include<stdio.h>
#include<stdlib.h>

// problema 8.5

void matrix_read(int n,int a[][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%d",*(a+i)+j);
        }
    }
}

void ssum(int n,int a[][n],int *v1,int *v2)
{
    int s1;
    for(int j=0;j<n;j++)
    {
        *(v2+j)=0;
    }
    for(int i=0;i<n;i++)
    {
        s1=0;
        for(int j=0;j<n;j++)
        {
            *(v2+j)=*(v2+j)+*(*(a+i)+j);
            s1=s1+*(*(a+i)+j);
        }
        *(v1+i)=s1;
    }
}

void afisare(int *v1,int *v2,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(v1+i));
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(v2+i));
    }
    printf("\n");
}

int main(void)
{
    int n;
    printf("Dati n: ");
    scanf("%d",&n);
    int a[n][n],v1[n],v2[n];
    matrix_read(n,a);
    ssum(n,a,v1,v2);
    afisare(v1,v2,n);
    return 0;
}
