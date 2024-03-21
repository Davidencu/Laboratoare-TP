#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CHUNK 10

// problema 4.0

typedef struct
{
    char nume[21];
    int nota;
}elev;

int main(void)
{
    elev e;
    if(fgets(e.nume,21,stdin)!=NULL)
    {
        scanf("%d",&(e.nota));
        printf("%s\n%d\n",e.nume,e.nota);
    }
    return 0;
}