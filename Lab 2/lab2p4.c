#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void tabelare(double a,double b,double n,double (*f)(double))
{
    double cnt=a;
    while(cnt<=b)
    {
        printf("f(%.3lf)=%.3lf ",cnt,f(cnt));
        cnt=cnt+(b-a)/n;
    }
    printf("\n");
}

int main(void)
{
    double a,b,n;
    printf("Dati a, b si n : ");
    scanf("%lf %lf %lf",&a,&b,&n);
    tabelare(a,b,n,cos);
    tabelare(a,b,n,sqrt);
    tabelare(a,b,n,fabs);
    return 0;
}