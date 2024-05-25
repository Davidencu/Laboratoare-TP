#include<stdio.h>
#include<stdlib.h>

int **matrix_read(int n)
{
    int **m=NULL;
    if((m=(int **)malloc(n*sizeof(int *)))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<n;i++)
    {
        if((m[i]=(int *)malloc(n*sizeof(int)))==NULL)
        {
            for(int j=i-1;j>=0;j--)
            {
                free(m[j]);
            }
            free(m);
            perror(NULL);
            exit(-1);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&m[i][j]);
        }
    }
    return m;
}

void search(int **a,int **b,int m,int n)
{
    int ok,t=0;
    for(int i=0;i<m-n+1;i++)
    {
        for(int j=0;j<m-n+1;j++)
        {
            ok=1;
            for(int k=0;k<n;k++)
            {
                for(int l=0;l<n;l++)
                {
                    if(b[k][l]!=a[i+k][j+l])
                    {
                        ok=0;
                    }
                }
            }
            if (ok==1)
            {
                t++;
                printf("(%d,%d) ",i,j);
            }
        }
    }
    if (t==0)
    {
        printf("nu apare\n");
    }
}

void matrix_free(int **a,int n)
{
    for(int i=0;i<n;i++)
    {
        free(a[i]);
    }
    free(a);
}

int main(void)
{
    int n,m,**m1=NULL,**m2=NULL;
    printf("Dati m si n: ");
    scanf("%d %d",&n,&m);
    m1=matrix_read(n);
    m2=matrix_read(m);
    search(m1,m2,n,m);
    matrix_free(m1,n);
    matrix_free(m2,m);
    printf("\n");
    return 0;
}