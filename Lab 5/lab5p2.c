#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

//problema 2

void citire(int m,int n, int a[][n])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("a[%d][%d]=",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}

void scriere(int m,int n,int a[][n],FILE *fp2)
{
    if((fp2=fopen("fisier2.bin","wb"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    fwrite(&m,sizeof(int),1,fp2);
    fwrite(&n,sizeof(int),1,fp2);
    fwrite(*a,sizeof(int),m*n,fp2);
    if(fclose(fp2)!=0)
    {
        perror(NULL);
        exit(-1);
    }
}

int main(void)
{
    int m,n;
    FILE *fp2=NULL;
    printf("Dati m si n : ");
    scanf("%d%d",&m,&n);
    int a[m][n];
    citire(m,n,a);
    scriere(m,n,a,fp2);
}