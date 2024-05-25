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
