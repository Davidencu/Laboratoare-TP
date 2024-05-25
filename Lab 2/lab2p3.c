#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//problema 3

void read(float *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("v[%d]=",i);
        scanf("%f",&v[i]);
    }
}

int comp1(const void *elem1,const void *elem2)
{
    const float *a=(const float*)elem1;
    const float *b=(const float*)elem2;
    if(*a<*b)
    {
        return -1;
    }
    if(*a>*b)
    {
        return 1;
    }
    return 0;

}

int comp2(const void *key,const void *elem)
{
    const float *k=(const float*)key;
    const float *e=(const float*)elem;
    if(*e<*k)
    {
        return 1;
    }
    if(*e>*k)
    {
        return -1;
    }
    return 0;
}

void print_array(float *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%f ",v[i]);
    }
    printf("\n");
}

int main(void)
{
    int size;
    float x;
    printf("Dati marimea vectorului : ");
    scanf("%d",&size);
    printf("Dati x: ");
    scanf("%f",&x);
    float v[size];
    read(v,size);
    print_array(v,size);
    qsort(v,size,sizeof(float),comp1);
    print_array(v,size);
    if(bsearch(&x,v,size,sizeof(float),comp2)==NULL)
    {
        printf("x nu a fost gasit\n");
    }
    else
    {
        printf("ok\n");
    }
    return 0;
}