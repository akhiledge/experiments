#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
#define SIZE 16
int a[SIZE];
int front = -1;
int rear = -1;

void enqueue(void)
{
    if(is_full())
    {
        puts("queue is full\n");
    }
    else
    {
        if(front == -1)
            front = 0;
        (rear++)%SIZE;
        puts("enter the element into queue");
        scanf("%d",&a[rear]);
    }
}
void dequeue(void)
{
    if(is_empty())
        puts("queue is empty\n");
    else
        {

            printf("value poped %d\n",a[front]);
            if(front == rear){
                front = rear = -1;
                return ;
            }
            (front++)%SIZE;
        }
}
int is_full(void)
{
    if((size()) == (SIZE))
        return 1;
    else
        return 0;
}
int is_empty(void)
{
    if((size()) == 0)
        return 1;
    else 
        return 0;
}
void pe_ek(void)
{
    if(is_empty())
        puts("queue is empty\n");
    else
        printf("element at front is %d rear is %d\n",a[front],a[rear]); 
}
void display(void)
{
    int i = 0;
    if(is_empty())
        puts("queue is empty\n");
    else
    {
        puts("Elements in stack: ");
        while(i < size())
        {
            printf("%d ",a[(i+front)%SIZE]);
            i++;
        }
    }
}
int size(void)
{
    if((front == -1) && (rear == -1))
        return 0;
    if(front > rear)
        return SIZE + rear - front + 1;
    else
        return rear - front + 1;
}
