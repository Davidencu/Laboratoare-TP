#include<stdio.h>
#include<math.h>

int numarare(int a,int z,int *v)
{
    int c=(a+z)/2;
    int aux1,aux2;
    if (a==z)
    {
        if(v[a]%2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        aux1=numarare(a,c,v);
        aux2=numarare(c+1,z,v);
        return aux1+aux2;
    }
}


int main()
{
    int n;
    printf("Dati n: ");
    scanf("%d",&n);
    int v[n];
    for(int i=0;i<n;i++)
    {
        printf("v[%d]=",i);
        scanf("%d",&v[i]);
    }
    printf("%d numere impare in array\n",numarare(0,n-1,v));
    return 0;
}
