#include<stdio.h>

//Se dă un vector x cu n elemente numere naturale, ordonate crescător, și un
//vector y cu m elemente, de asemenea numere naturale. Verificați pentru
//fiecare element al vectorului y dacă apare în x. Se va folosi tehnica Divide et
//Impera.

int c(int *x,int a,int z,int elem)
{
    int mij=(a+z)/2;
    int aux1,aux2;
    if (a==z)
    {
        if(x[a]==elem)
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
        aux1=c(x,a,mij,elem);
        aux2=c(x,mij+1,z,elem);
        return aux1+aux2;
    }
}

int cautare(int *x,int *y,int a,int z,int n1)
{
    int mij=(a+z)/2;
    int aux1,aux2;
    if (a==z)
    {
        if(c(x,0,n1-1,y[a]))
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
        aux1=cautare(x,y,a,mij,n1);
        aux2=cautare(x,y,mij+1,z,n1);
        return aux1&aux2;
    }
}

int main()
{
    int n1,n2;
    printf("Dati nr de elemente ale vectorilor x si y: ");
    scanf("%d%d",&n1,&n2);
    int x[n1],y[n2];
    for(int i=0;i<n1;i++)
    {
        printf("x[%d]=",i);
        scanf("%d",&x[i]);
    }
    for(int i=0;i<n2;i++)
    {
        printf("y[%d]=",i);
        scanf("%d",&y[i]);
    }
    printf("%d\n",cautare(x,y,0,n2-1,n1));
    return 0;
}
