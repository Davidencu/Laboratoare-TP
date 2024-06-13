#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

//m>=2*n
//in functia valid ne intereseaza daca 
//  (a[k-1]!=0 && a[k]!=0) returnam 0 (nu pot fi ambele diferite de 0)
// si toate elementele sa fie mai mici decat a[k]
// la solutie, ne intereseaza ca k sa fi ajuns la m-1 (daca indexam stiva de la 0)
// citim doua variabile nr intregi din fisierul binar, deci vom avea 8 bytes

int valid(int *a,int n,int m,int k,FILE *out)
{
    if(k>=1 && (a[k-1]!=0 && a[k]!=0))
    {
        return 0;
    }
    if(a[k]!=0)
    {
        for(int i=0;i<k;i++)
        {
            if(a[i]>=a[k])
            {
                return 0;
            }
        }
    }
    if(k>m-1)
    {
        return 0;
    }
    return 1;
}

int solutie(int *a,int n,int m,int k,FILE *out)
{
    int ok=0,sum=0;
    for(int i=0;i<=k;i++)
    {
        sum=sum+a[i];
    }
    if(sum==((n*(n+1))/2))
    {
        ok=1;
    }
    if(k==m-1 && ok==1)
    {
        return 1;
    }
    return 0;
}

void afisare(int *a,int n,int m,int k,FILE *out)
{
    for(int i=0;i<=k;i++)
    {
        fprintf(out,"%d",a[i]);
    }
    fprintf(out,"\n");
}

void back(int *a,int n,int m,int k,FILE *out)
{
    for(int i=0;i<=n;i++)
    {
        a[k]=i;
        if(valid(a,n,m,k,out))
        {
            if(solutie(a,n,m,k,out))
            {
                afisare(a,m,n,k,out);
            }
            else
            {
                back(a,n,m,k+1,out);
            }
        }
    }
}

FILE *creere(FILE *fp)
{
    if((fp=fopen("SESIUNE.IN","wb+"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    return fp;
}

void scriere(FILE *fp)
{
    uint32_t m,n;
    printf("Dati n: ");
    scanf("%d",&n);
    printf("Dati m: ");
    scanf("%d",&m);
    fwrite(&n,sizeof(uint32_t),1,fp);
    fwrite(&m,sizeof(uint32_t),1,fp);
}

void citire(FILE *fp,int *m,int *n)
{
    rewind(fp);
    fread(n,sizeof(uint32_t),1,fp);
    fread(m,sizeof(uint32_t),1,fp);
}

int main()
{
    int n,m;
    FILE *fp=NULL,*out=NULL;
    fp=creere(fp);
    if((out=fopen("DEST.TXT","w+"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    scriere(fp);
    citire(fp,&m,&n);
    int a[m];
    back(a,n,m,0,out);
    if(fclose(fp)!=0 || fclose(out)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}