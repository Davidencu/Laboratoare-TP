#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//problema 1

#define MAX_SIZE 100
int top=-1;
int stack[MAX_SIZE];

void push(int item)
{
    if(top == MAX_SIZE-1)
    {
        printf("Stiva este plina\n");
        return;
    }
    stack[++top]=item;
}

int pop()
{
    if(top == -1)
    {
        printf("Stiva este goala\n");
        return -1;
    }
    return stack[top--];
}

void display()
{
    if(top==-1)
    {
        printf("Stiva este goala\n");
        return;
    }
    printf("Elementele din stiva sunt: ");
    for(int i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main(void)
{
    push(10);
    push(15);
    push(20);
    display();
    printf("Elementul extras din stiva: %d\n",pop());
    display();
    return 0;
}

//problema 2

#define MAX_SIZE 100
int front=-1,rear = -1;
int queue[MAX_SIZE];

void enqueue(int item)
{
    if(rear == MAX_SIZE-1)
    {
        printf("Coada este plina\n");
        return;
    }
    if(front == -1) front=0;
    queue[++rear]=item;
}

int dequeue() 
{
    if(front == -1 || front > rear) 
    {
        printf("Coada este goala\n");
        return -1;
    }
    return queue[front++];
}

void display()
{
    if (front == -1 || front>rear)
    {
        printf("Coada este goala\n");
        return;
    }
    printf("Elementele din coada sunt: ");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(35);
    enqueue(0);
    display();
    printf("Elementul extras din coada: %d\n",dequeue());
    display();
    printf("Elementul extras din coada: %d\n",dequeue());
    display();
    return 0;
}

//problema 3

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

//problema 4

#define MAX_SIZE 100

int front=-1,rear=-1;

typedef struct
{
    int numar;
    char mesaj[257];
} q;

q queue[MAX_SIZE];

void enqueue(int nr,char *m)
{
    if(rear == MAX_SIZE-1)
    {
        printf("Coada este plina\n");
        exit(-1);
    }
    if(front == -1) front=0;
    rear++;
    queue[rear].numar=nr;
    strcpy(queue[rear].mesaj,m);
}

q dequeue() 
{
    if(front == -1 || front > rear) 
    {
        printf("Coada este goala\n");
        exit(-1);
    }
    return queue[front++];
}

void display()
{
    {
    if (front == -1 || front>rear)
    {
        printf("Coada este goala\n");
        return;
    }
    for(int i=front;i<=rear;i++)
    {
        printf("%d\n%s\n",queue[i].numar,queue[i].mesaj);
    }
}

}

int main(void)
{
    enqueue(1,"Scrisoare nu este a mea");
    enqueue(4,"Scrisoarea este a persoanei 2");
    enqueue(2,"Persoana 4 minte");
    enqueue(5,"Exact unul dintre persoanele 1 sau 4 are dreptate");
    enqueue(6,"Nimeni dintre noi nu spune adevarul");
    enqueue(10,"Eu am scrisoarea");
    dequeue();
    dequeue();
    display();
    return 0;
}
