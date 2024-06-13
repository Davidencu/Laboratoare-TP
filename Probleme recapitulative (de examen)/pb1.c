#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int valid(int *a,int *v,int n,int s,int k,int cnt)
{
    for(int i=0;i<k;i++)
    {
        if(v[a[i]]>v[a[k]])
        {
            return 0;
        }
    }
    if(cnt>s)
    {
        return 0;
    }
    return 1;
}

int solutie(int *a,int *v,int n,int s,int k,int cnt)
{
    if(cnt==s)
    {
        return 1;
    }
    return 0;
}

void afisare(int *a,int *v,int n,int s,int k,int cnt)
{
    int f[100];
    memset(f,0,100*sizeof(int));
    for(int i=0;i<=k;i++)
    {
        f[v[a[i]]]++;
    }
    for(int i=1;i<100;i++)
    {
        if(f[i]!=0)
        {
            printf("%d*%d ",f[i],i);
        }
    }
    printf("\n");
}

void back(int *a,int *v,int n,int s,int k,int cnt)
{
    for(int i=0;i<n;i++)
    {
        a[k]=i;
        if(valid(a,v,n,s,k,cnt+v[a[k]]))
        {
            if(solutie(a,v,n,s,k,cnt+v[a[k]]))
            {
                afisare(a,v,n,s,k,cnt);
            }
            else
            {
                back(a,v,n,s,k+1,cnt+v[a[k]]);
            }
        }
    }
}

int main()
{
    FILE *fp1=NULL;//,*fp2=NULL;
    int n,s;
    if((fp1=fopen("N.TXT","r"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    //if((fp2=fopen("REZULTATE.TXT","w"))==NULL)
    //{
    //    perror(NULL);
    //    exit(-1);
    //}
    fscanf(fp1,"%d",&n);
    int v[n],a[150];
    for(int i=0;i<n;i++)
    {
        fscanf(fp1,"%d",&v[i]);
    }
    fscanf(fp1,"%d",&s);
    back(a,v,n,s,0,0);
    if(fclose(fp1)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    //if(fclose(fp2)!=0)
    //{
    //    perror(NULL);
    //    exit(-1);
    //}
    return 0;
}
