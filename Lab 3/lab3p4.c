#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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