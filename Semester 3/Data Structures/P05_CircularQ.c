//Program to implement circular queue and its operations(insert,delete and display) of integers

#include<stdio.h>
#include<stdlib.h>
#define SIZE 4

int q[SIZE],front=-1,rear=-1;

//function to insert a number into the queue

void insert()
{
    int ele;
    if((front==0 && rear==SIZE-1) ||(rear+1==front))
        printf("Queue is full!\n\n");
    else
    {
        printf("Enter a number:");
        scanf("%d",&ele);
        if(front==-1)
            front=0;
        if(rear==SIZE-1 && front!=0)
            rear=-1;
        q[++rear]=ele;
        printf("Enqueued element:%d\n\n",q[rear]);
    }
}
//function to delete a number from the queue

void delete()
{
    int data;
    if(front==-1 && rear==-1)
        printf("Queue is empty!\n\n");
    else
    {
        data=q[front++];
        printf("Deleted element:%d\n\n",data);
        if(front==rear+1)
        {
            rear=-1;
            front=-1;
        }
        if(front==SIZE)
            front=0;
    }
}

//function to display contents of the queue

void display()
{
    if(front==-1 && rear==-1)
        printf("Queue is empty!\n\n");
    else
    {
        printf("Queue contains:\n");
        if(front<=rear)
            for(int i=front;i<=rear;i++)
                printf("%d\n",q[i]);
        else
        {
            for(int i=0;i<=rear;i++)
                printf("%d\n",q[i]);
            for(int i=front;i<SIZE;i++)
                printf("%d\n",q[i]);
        }
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("Menu:\n1.insert,\n2.delete,\n3.display,\n4.exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert();
                break;
            case 2: delete();
                break;
            case 3: display();
                break;
            case 4: exit(0);
                break;
            default: printf("Invalid choice!\n\n");
        }
    }
}
