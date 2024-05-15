#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define GR 1.61803398875

float golden_ratio(float gr,float err)
{
    if (fabs(gr-GR)<err)
    {
        return gr;
    }
    else
    {
        return golden_ratio(1+1/gr,err);
    }
}

int main()
{
    float f,nr;
    scanf("%f",&f);
    nr=golden_ratio(1,f);
    printf("Aproximarea este %f. \n",nr);
    return 0;
}