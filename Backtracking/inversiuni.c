#include<stdio.h>

//sa se scrie un program care primeste un vector si
//returneaza numarul de inversiuni 
//(toate combinatiile de cate 2 elemente care sunt ordonate descrescator)

int perm(int *v,int st,int dr)
{
    int mij=(st+dr)/2,sum=0,aux1,aux2;
    if(st>=dr)
    {
        return 0;
    }
    else
    {
        aux1=perm(v,st,mij);
        aux2=perm(v,mij+1,dr);
        for(int i=st;i<=mij;i++)
        {
            for(int j=mij+1;j<=dr;j++)
            {
                if(v[i]>v[j])
                {
                    sum++;
                }
            }
        }
        return aux1+aux2+sum;
    }
}

int main()
{
    int n;
    printf("Dati n:\n");
    scanf("%d",&n);
    int v[n];
    for(int i=0;i<n;i++)
    {
        printf("v[%d]=",i);
        scanf("%d",&v[i]);
    }
    printf("%d\n",perm(v,0,n-1));
    return 0;
}