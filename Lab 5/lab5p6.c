#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

//problema 6

void extragere(int a,long *offset,char **argv,uint8_t *v)
{
    *offset=strtol(argv[2],NULL,16);
    for(int i=3;i<a;i++)
    {
        v[i-3]=(uint8_t)strtol(argv[i],NULL,16);
    }
}

int main(int argc,char **argv)
{
    FILE *fp=NULL;
    long offset;
    uint8_t v[argc-3];
    if(argc<4)
    {
        perror(NULL);
        exit(-1);
    }
    if((fp=fopen(argv[1],"rb+"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    extragere(argc,&offset,argv,v);
    if (fseek(fp, offset, SEEK_SET)==0)
    {
        fwrite(&v,sizeof(uint8_t),argc-3,fp);
    }
    if(fclose(fp)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}