#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

//problema 9

int main(int argc,char **argv)
{
    float sum=0,nr;
    for(int i=1;i<argc;i++)
    {
        nr=atof(argv[i]);
        sum+=nr;
    }
    if(argc==1)
    {
        printf("0\n");
    }
    else
    {
        printf("%f\n",sum);
    }
}