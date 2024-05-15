#include<stdio.h>

int maxx(long n)
{
    if (n!=0)
    {
        if(n%10>maxx(n/10))
        {
            return n%10;
        }
        else
        {
            return maxx(n/10);
        }
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    long n;
    printf("Dati n\n");
    scanf("%ld",&n);
    printf("cifra maxima este: %d\n",maxx(n));
    return 0;
}