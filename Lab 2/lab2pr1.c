#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//problema 1 proiect

double f1(double x)
{
    return (x*x*x+4)/(x*x+5);
}

double f2(double x)
{
    return x+10;
}

double f3(double x)
{
    return 2*x*x-1;
}

void tabelare(double a,double b,double n,double (*f)(double))
{
    double cnt=a;
    while(cnt<=b)
    {
        printf("f(%.03lf)=%.03lf ",cnt,f(cnt));
        cnt=cnt+(b-a)/n;
    }
    printf("\n");
}

int main(void)
{
    double a,b,p;
    printf("Dati a, b si n : ");
    scanf("%lf %lf %lf",&a,&b,&p);
    tabelare(a,b,p,f1);
    tabelare(a,b,p,f2);
    tabelare(a,b,p,f3);
    return 0;
}