#include<stdio.h>
#include<math.h>

float f(float x,float y)
{
    return sin(x)+sin(2*x)+x-y;
}

float val(float a,float z,float y)
{
    float mij=(a+z)/2.0;
    float aux1,aux2;
    if(fabs(a-z)<(1.0/pow(2,22)))
    {
        if ((f(a,y)<0) && (f(z,y)>0))
        {
            return mij;
        }
        else 
        {
            return 0;
        }
    }
    else
    {
        aux1=val(a,mij,y);
        aux2=val(mij,z,y);
        return aux1+aux2;
    }
}

int main()
{
    float y;
    printf("Dati y: ");
    scanf("%f",&y);
    printf("valoarea cautata este %f\n",val(0,1,y));
    return 0;
}