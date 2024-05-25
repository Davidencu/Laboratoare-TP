#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

//problema 6

char *concat(int n,...)
{
    char *s=malloc(sizeof(char));
    s[0]='\0';
    char aux[20];
    int cnt=0;
    int len=0;
    va_list va;
    va_start(va,n);
    for(int i=0;i<n;i++)
    {
        strcpy(aux,va_arg(va,char *));
        len=strlen(aux)+1;
        cnt+=len;
        if((s=realloc(s,(cnt+1)*sizeof(char)))==NULL)
        {
            perror(NULL);
            exit(-1);
        }
        strcat(s,aux);
        strcat(s," ");
    }
    return s;
    va_end(va);
}

int main()
{
    char *s=concat(3,"ana","are","mere");
    printf("%s\n",s);
    free(s);
    return 0;
}