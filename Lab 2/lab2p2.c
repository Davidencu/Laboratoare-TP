#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void read(int *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("v[%d]=",i);
        scanf("%d",&v[i]);
    }
}

int negative(int n)
{
    return n<0;
}

void test(int *v,int *size,int (*cond)(int))
{
    for(int i=0;i<*size;i++)
    {
        if(!cond(v[i]))
        {
            for(int j=i;j<*size-1;j++)
            {
                v[j]=v[j+1];
            }
            *size=*size-1;
            i=i-1;
        }
    }
}

void print_array(int *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
}

int main(void)
{
    int size;
    printf("Dati marimea vectorului : ");
    scanf("%d",&size);
    int v[size];
    read(v,size);
    print_array(v,size);
    test(v,&size,negative);
    print_array(v,size);
    return 0;
}