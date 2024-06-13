#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

int valid(int *credite,int *a,int n,int k,int s,int cnt)
{
    for(int i=0;i<k;i++)
    {
        if (a[i]>=a[k])
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

int solutie(int *credite,int *a,int n,int k,int s,int cnt)
{
    if(cnt>=s)
    {
        return 1;
    }
    return 0;
}

void afisare(int *credite,int *a,int n,int k,int s,int cnt)
{
    printf("%d,",k+1);
    for(int i=0;i<=k;i++)
    {
        printf("%d ",credite[a[i]]);
    }
    printf("\n");
}

void back(int *credite,int *a,int n,int k,int s,int cnt)
{
    for(int i=0;i<n;i++)
    {
        a[k]=i;
        if(valid(credite,a,n,k,s,cnt+credite[a[k]]))
        {
            if(solutie(credite,a,n,k,s,cnt+credite[a[k]]))
            {
                afisare(credite,a,n,k,s,cnt+credite[a[k]]);
            }
            else
            {
                back(credite,a,n,k+1,s,cnt+credite[a[k]]);
            }
        }
    }
}

FILE *create(FILE *b)
{
    if((b=fopen("CREDITE.IN","wb+"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    uint32_t n;
    printf("Dati n: ");
    scanf("%d",&n);
    fwrite(&n,sizeof(uint32_t),1,b);
    uint32_t x,s;
    for(int i=0;i<n;i++)
    {
        printf("Dati nr credite: ");
        scanf("%d",&x);
        fwrite(&x,sizeof(uint32_t),1,b);
    }
    printf("Dati nr minim de credite pt a trece sesiunea: ");
    scanf("%d",&s);
    fwrite(&s,sizeof(uint32_t),1,b);
    return b;
}

FILE *create2(FILE *out)
{
    if((out=fopen("EXAMENE.OUT","wb+"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    return out;
}

void citire(FILE *b,int *n,int *credite,int *s)
{
    rewind(b);
    fread(n,sizeof(uint32_t),1,b);
    printf("n este %d\n",*n);
    for(int i=0;i<*n;i++)
    {
        fread(&credite[i],sizeof(uint32_t),1,b);
    }
    fread(s,sizeof(uint32_t),1,b);
}

void pr(int *credite,int n,int s)
{
    printf("Lista creditelor este: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",credite[i]);
    }
    printf("\n");
    printf("Nr minim credite este: %d\n",s);
}

void bsort(int *credite,int n)
{
    int s=0,aux=0;
    do
    {
        s=0;
        for(int i=0;i<n-1;i++)
        {
            if(credite[i]<credite[i+1])
            {
                s=1;
                aux=credite[i];
                credite[i]=credite[i+1];
                credite[i+1]=aux;
            }
        }
    } while (s==1);
}

int main()
{
    FILE *b=NULL,*out=NULL;
    int n,s,credite[20],a[20];
    b=create(b);
    out=create2(out);
    citire(b,&n,credite,&s);
    pr(credite,n,s);
    bsort(credite,n);
    back(credite,a,n,0,s,0);
    if(fclose(b)!=0 || fclose(out)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}