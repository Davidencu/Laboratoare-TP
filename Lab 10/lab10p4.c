#include<stdio.h>

int fibo(int n)
{
    if (n==1 || n==0)
    {
        return 1;
    }
    else
    {
        return fibo(n-1)+fibo(n-2);
    }
}

int main(void)
{
    int n;
    printf("Dati n\n");
    scanf("%d",&n);
    printf("al %d-lea termen este: %d\n",n,fibo(n));
    return 0;
}