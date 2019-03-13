//Program to implement linear queue and its operations insert,delete and display on integers following FIFO

#include<stdio.h>
#include<stdlib.h>
#define SIZE 4

int q[SIZE];
int front=-1,rear=-1,ele;

void delete();
void insert();
void display();

void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Insert,\n2.Delete,\n3.Display,\n-1.Exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case -1:
                exit(0);
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    }
}

//function to insert a number into the queue at the rear end

void insert()
{
    if(rear==SIZE-1)
        printf("\nQueue is full\n");
    else
    {
        printf("\nEnter a number: ");
        scanf("%d",&ele);
        if(front==-1)
            front=0;
        q[++rear]=ele;
        printf("\n%d enqueued",q[rear]);

    }
}

//function to delete a number from the queue at the front end

void delete()
{
    int data;
    if(rear==-1 || front>rear)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        data=q[front];
        printf("\nDeleted Element:%d\n",data);
        front++;
        if(front == rear+1)
        {
            //resetting front and rear
            front = -1;
            rear = -1;
        }
    }
}

//function to display the contents of the queue 

void display()
{
    if(rear==-1 || front>rear)
        printf("\nQueue is empty\n");
    else
    {
        printf("\nQueue contains:\n");
        for(int i=front;i<=rear;i++)
            printf("%d\n",q[i]);
    }
}
