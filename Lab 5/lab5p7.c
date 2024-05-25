#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

//problema 7

int checkk(uint8_t *v,uint8_t *w,int n)
{
    int ok=1;
    for(int i=0;i<n;i++)
    {
        if(v[i]!=w[i])
        {
            ok=0;
        }
    }
    return ok;
}

void extragere(int a,char **argv,uint8_t *v)
{
    for(int j=2;j<a;j++)
    {
        v[j-2]=(uint8_t)strtol(argv[j],NULL,16);
    }
}

void cautare(FILE *fp,uint8_t *v,int size)
{
    uint8_t w[size];
    int a;
    fseek(fp,0,SEEK_END); //returneaza 0 ca s-a reusit
    int end=ftell(fp); //end primeste pozitia cursorului care acum este la capatul fisierului
    for(int i=0;i<end-size+1;i++)
    {
        fseek(fp,i,SEEK_SET);
        fread(&w,sizeof(uint8_t),size,fp);
        if(checkk(v,w,size))
        {   
            a=ftell(fp); //a primeste pozitia pe care vrem sa o aflam
            printf("%d\n",a);
        }
    }
}

int main(int argc,char **argv)
{
    FILE *fp=NULL;
    uint8_t v[argc-2];
    if(argc<3)
    {
        perror(NULL);
        exit(-1);
    }
    if((fp=fopen(argv[1],"rb+"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    extragere(argc,argv,v);
    cautare(fp,v,argc-2);
    if(fclose(fp)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}