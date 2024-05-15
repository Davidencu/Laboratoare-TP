#include<stdio.h>

int suma(long n)
{
    if (n!=0)
    {
        return n%10+suma(n/10);
    }
    else
    {
        return 0;
    }
}

int main()
{
    long n;
    printf("Dati n\n");
    scanf("%ld",&n);
    printf("suma este: %d\n",suma(n));
    return 0;
}