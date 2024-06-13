#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

int v[15][15];

int valid(int *a,int n,int a0,int k)
{
    if(k>a0-1)
    {
        return 0;
    }
    if(k>=1)
    {
        if(k%2)
        {
            if(v[a[k]-1][a[k-1]-1]==1)
            {
                if(k>=3)
                {
                    if(a[k]!=a[k-3])
                    {
                        return 1;
                    }
                    return 0;
                }
                return 1;
            }
            return 0;
        }
        
        if(k%2==0)
        {
            if(a[k]==a[k-1])
            {
                return 1;
            }
            return 0;
        }
    }
    return 1;
}

int solutie(int *a,int n,int a0,int k)
{
    if(k==a0-1)
    {
        return 1;
    }
    return 0;
}

void afisare(int *a,int n,int a0,int k)
{
    for(int i=0;i<=k;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void back(int *a,int n,int a0,int k)
{
    for(int i=1;i<=6;i++)
    {
        a[k]=i;
        if(valid(a,n,a0,k))
        {
            if(solutie(a,n,a0,k))
            {
                afisare(a,n,a0,k);
            }
            else
            {
                back(a,n,a0,k+1);
            }
        }
    }
}

FILE *creare(FILE *in)
{
    if((in=fopen("DOMINO.IN","wb+"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    return in;
}

void scriere(FILE *in)
{
    uint32_t n,x,y,a0;
    printf("n=");
    scanf("%d",&n);
    fwrite(&n,sizeof(uint32_t),1,in);
    for(int i=0;i<n;i++)
    {
        printf("x=");
        scanf("%d",&x);
        printf("y=");
        scanf("%d",&y);
        fwrite(&x,sizeof(uint32_t),1,in);
        fwrite(&y,sizeof(uint32_t),1,in);
    }
    printf("a=");
    scanf("%d",&a0);
    fwrite(&a0,sizeof(uint32_t),1,in);
}

void citire(FILE *in,int *n,int *a0)
{
    uint32_t x,y;
    rewind(in);
    fread(n,sizeof(uint32_t),1,in);
    for(int i=0;i<*n;i++)
    {
        fread(&x,sizeof(uint32_t),1,in);
        fread(&y,sizeof(uint32_t),1,in);
        v[x-1][y-1]=1;
        v[y-1][x-1]=1;
    }
    fread(a0,sizeof(uint32_t),1,in);
}



int main()
{
    int n,a0;
    FILE *in=NULL;
    in=creare(in);
    scriere(in);
    citire(in,&n,&a0);
    int a[a0];
    back(a,n,2*a0,0);
    if(fclose(in)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}