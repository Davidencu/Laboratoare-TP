#include<stdio.h>

void citire(int *v,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("v[%d]= ",i);
        scanf("%d",&v[i]);
    }
}

void afisare(int *v,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
}

int binary(int *v,int a,int z,int elem)
{
    int mijl=(a+z)/2;
    if(v[mijl]>elem && a!=z)
    {
        printf("%d - %d \n",a,z);
        return binary(v,a,mijl-1,elem);
    }
    else
    {
        if(v[mijl]<elem && a!=z)
        {
            printf("%d - %d \n",a,z);
            return binary(v,mijl,z,elem);
        }
        else
        {
            if(v[mijl]==elem)
            {
                return 1;
            }
            return 0;
        }
    }
}

int main(void)
{
    int size,q;
    printf("Dimenssiunea vectorului v: size=");
    scanf("%d",&size);
    int v[size];
    citire(v,size);
    afisare(v,size);
    printf("Dati elementul de cautat: ");
    scanf("%d",&q);
    printf("%d\n",binary(v,0,size-1,q));
    return 0;
}