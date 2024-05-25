#include<stdio.h>
#include<stdlib.h>

void matrix_read(int a[][4],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}

void check_for_products(int a[][4],int n)
{
    int ok=1,nr=0;
    for(int i=0;i<n;i++)
    {
        ok=1;
        for(int j=1;j<4;j++)
        {
            if(a[i][j]<=a[i][j-1])
            {
                ok=0;
            }
        }
        if (ok) 
        {
            nr++;
            printf("%d ",i);
        }
    }
    if(nr==0)
    {
        printf("niciun produs");
    }
}

int main(void)
{
    int n;
    printf("Dati n : ");
    scanf("%d",&n);
    int a[n][4];
    matrix_read(a,n);
    check_for_products(a,n);
    return 0;
}