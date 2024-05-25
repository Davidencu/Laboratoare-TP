#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

//problema 10

void criptare(char argc,char **argv)
{
    int n=atoi(argv[2]);
    
    if(strcmp(argv[1],"enc")==0)
    {
        for(int i=3;i<argc;i++)
        {
            for(int j=0;j<strlen(argv[i]);j++)
            {
                if('A'<argv[i][j] && argv[i][j]<'Z')
                {
                    argv[i][j]+=32;
                }
            }
            for(int j=0;j<strlen(argv[i]);j++)
            {
                if(n>('z'-argv[i][j]))
                {
                    argv[i][j]=argv[i][j]+n-26;
                }
                else
                {
                    argv[i][j]=argv[i][j]+n;
                }
            }
        }
    }
    if(strcmp(argv[1],"dec")==0)
    {
        for(int i=3;i<argc;i++)
        {
            for(int j=0;j<strlen(argv[i]);j++)
            {
                if('A'<argv[i][j] && argv[i][j]<'Z')
                {
                    argv[i][j]+=32;
                }
            }
            for(int j=0;j<strlen(argv[i]);j++)
            {
 
                if(n>(argv[i][j]-'a'))
                {
                    argv[i][j]=argv[i][j]-n+26;
                }
                else
                {
                    argv[i][j]=argv[i][j]-n;
                }
                
            }
        }
    }
}

int main(int argc,char **argv)
{
    if(argc<4)
    {
        perror(NULL);
        exit(-1);
    }
    criptare(argc,argv);
    for(int i=3;i<argc;i++)
    {
        printf("%s ",argv[i]);
    }
    printf("\n");
    return 0;
}