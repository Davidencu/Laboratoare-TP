#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<math.h>

FILE *creere(FILE *fp)
{
    uint32_t n;
    if((fp=fopen("N.IN","w+"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    scanf("%d",&n);
    fwrite(&n,sizeof(uint32_t),1,fp);
    rewind(fp);
    return fp;
}

void citire(FILE *fp,int *n)
{
    fread(n,sizeof(uint32_t),1,fp);
}

float d(int x)
{
    float aux=(float)x;
    return sin(aux)+powf(2,aux);
}

float e(int x)
{
    float aux=(float)x;
    return powf(3,aux);
}

float f(int x)
{
    float aux=(float)x;
    return aux;
}

float g(int x)
{
    float aux=(float)x;
    return 1+2*aux+3*aux*aux+4*aux*aux*aux;
}

float b(float (*d)(int), float (*e)(int),int x)
{
    return d(x)*e(x);
}

float c(float (*f)(int),float (*g)(int),int x)
{
    return f(x)/g(x);
}

float a(float (*b)(float (*)(int), float (*)(int),int), float (*c)(float (*)(int), float (*)(int),int),float(*d)(int),float(*e)(int),float(*f)(int),float(*g)(int),int x)
{
    return b(d,e,x)+c(f,g,x);
}

int main()
{
    FILE *fp=NULL,*out=NULL;
    fp=creere(fp);
    int x;
    if((out=fopen("REZULTATE.TXT","w"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    citire(fp,&x);
    float v4=d(x),v5=e(x),v6=f(x),v7=g(x);
    float v2=b(d,e,x);
    float v3=c(f,g,x);
    float v1=a(b,c,d,e,f,g,x);
    fprintf(out,"%f %f %f %f %f %f %f",v1,v2,v3,v4,v5,v6,v7);
    if(fclose(fp)!=0 || fclose(out)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}