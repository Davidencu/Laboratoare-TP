#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

int main(int argc,char **argv)
{
    int nr;
    if(argc<3)
    {
        perror(NULL);
        exit(-1);
    }
    else
    {
        nr=atoi(argv[1]);
        switch(nr)
        {
            case 0:
                int s=0;
                for(int i=2;i<argc;i++)
                {
                    s=s+strlen(argv[i]);
                }
                printf("%d\n",s);
            case 1:
                char a[58]={0};
                for(int i=2;i<argc;i++)
                {
                    for(int j=0;j<strlen(argv[i]);j++)
                    {
                        if(isalpha(argv[i][j]))
                        {
                            a[argv[i][j]-'A']++;
                        }
                    }
                }
                for(int i=0;i<58;i++)
                {
                    if(isalpha(i+'A') && a[i]!=0)
                    {
                        printf("%c - de %d ori\n",i+'A',a[i]);
                    }
                }
        }
    }
    return 0;
}