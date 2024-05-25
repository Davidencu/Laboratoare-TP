#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define CHUNK 10
#define SIZE 100
#define MAX_SIZE 200

int top=-1;

typedef struct
{
    char s[100];
    int line;
}s;

s stack[MAX_SIZE];


char **citire(int size)
{
    char **s=NULL;
    if((s=(char **)malloc(size*sizeof(char *)))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<SIZE;i++)
    {
        if((s[i]=(char *)malloc(SIZE*sizeof(char)+1))==NULL)
        {
            for(int j=i-1;j>0;j--)
            {
                free(s[j]);
            }
            free(s);
            perror(NULL);
            exit(-1);
        }
        s[i][0]='\0';
    }
    return s;
}

void rewrite(FILE **fp,char **str)
{
    if(fclose(*fp)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    if((*fp=fopen("fisier.txt","w"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<SIZE;i++)
    {
        fprintf(*fp,"%s\n",str[i]);
    }
}

void push(char *str,int n,char **string,FILE **fp)
{
    if(top==MAX_SIZE-1)
    {
        printf("Stack is full\n");
        exit(-1);
    }
    top++;
    strcpy(stack[top].s,str);
    stack[top].line=n;
    strcat(string[n],str);
    rewrite(fp,string);
}

char *undo(char **string,FILE **fp)
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        exit(-1);
    }
    int n=stack[top].line;
    int nr=strstr(string[n],stack[top].s)-string[n];
    string[n][nr]='\0';
    top--;
    rewrite(fp,string);
    return stack[top].s;
}

void my_free(char **s,int size)
{
    for(int i=0;i<size;i++)
    {
        free(s[i]);
    }
    free(s);
}

int main(void)
{
    FILE *fp=NULL;
    char **string=NULL;
    if((fp=fopen("fisier.txt","w"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    string=citire(SIZE);
    push("acadea",0,string,&fp);
    push("banana ",1,string,&fp);
    push("casa",1,string,&fp);
    push("daca",3,string,&fp);
    push("fubasfhoidaf",5,string,&fp);
    undo(string,&fp);
    my_free(string,SIZE);
    if(fclose(fp)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}