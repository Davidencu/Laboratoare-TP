#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define e 2.71828182846



float ex(int n,float x,float val,float val2,float err)
{
    if(fabs(val-powf(e,x))<err)
    {
        return val;
    }
    else
    {
        return ex(n+1,x,val+val2*x/(n+1),val2*x/(n+1),err);
    }
}

int main()
{
    float x,err;
    scanf("%f",&x);
    scanf("%f",&err);
    printf("%f\n",ex(0,x,1,1,err));
    return 0;
}