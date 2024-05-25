#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//problema 2 proiect

int f1(char *s)
{
    return strlen(s);
}

int f2(char *s)
{
    int nr=0;
    for(int i=0;i<strlen(s);i++)
    {
        if (strchr("AEIOUaeiou",s[i])!=0)
        {
            nr++;
        }
    }
    return nr;
}

int f3(char *s)
{
    int nr=0;
    for(int i=0;i<strlen(s);i++)
    {
        if (s[i]>='A' && s[i]<='Z')
        {
            nr++;
        }
    }
    return nr;
}

int f4(char *s)
{
    int len=strlen(s);
    return s[len-1]-s[0];
}

int main(int argc,char **argv)
{
    FILE *fp=NULL;
    if((fp=fopen("CUVINTE.TXT","w"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    if (argc == 1)
    {
        printf("nu exista cuvinte\n");
        exit(-1);
    }
    int (*f[4])(char *)={f1,f2,f3,f4};
    for(int i=1;i<argc;i++)
    {
        printf("Cuvantul %s este de lungime %d, are %d vocale, are %d litere mari,iar diferenta dintre caractere este %d\n",argv[i],f[0](argv[i]),f[1](argv[i]),f[2](argv[i]),f[3](argv[i]));
        fprintf(fp,"Cuvantul %s este de lungime %d, are %d vocale, are %d litere mari,iar diferenta dintre caractere este %d\n",argv[i],f[0](argv[i]),f[1](argv[i]),f[2](argv[i]),f[3](argv[i]));
    }
    if(fclose(fp)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}