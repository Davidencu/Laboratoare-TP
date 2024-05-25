#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

//problema 11

float algebra(int argc,char **argv)
{
    int i=2;
    float nr=atof(argv[1]);
    float aux;
    char str[3];
    while(i<argc)
    {
        strcpy(str,argv[i]);
        aux=atof(argv[i+1]);
        if(strcmp(str,"add")==0)
        {
            nr=nr+aux;
        }
        if(strcmp(str,"sub")==0)
        {
            nr=nr-aux;
        }
        if(strcmp(str,"mul")==0)
        {
            nr=nr*aux;
        }
        if(strcmp(str,"div")==0)
        {
            nr=nr/aux;
        }
        i+=2;
    }
    return nr;
}

int main(int argc, char **argv)
{
    if(argc<2)
    {
        perror(NULL);
        exit(-1);
    }
    else
    {
        float a=algebra(argc,argv);
        printf("%f\n",a);
    }
    return 0;
}