//Program to implement an ordered doubly linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* prev;
    int value;
    struct node* next;
}*newNode=NULL,*head=NULL,*ptr=NULL,*tail=NULL,*lptr=NULL;

void insert();
//function to create a node

void create()
{
    int val;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value:");
    scanf("%d",&val);
    newNode->value=val;
    newNode->next=NULL;
    newNode->prev=NULL;
    insert();
}

//function to insert a node at a valid position

void insert()
{
    if(head==NULL)  //to check if it is a first node or not
    {
        head=newNode;
        tail=head;
    }
    else if(head->value>newNode->value)  //to check if a value is less than the first node's value
    {
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
    else if(tail->value<newNode->value)  //to check if a value is greater than the last node's value
    {
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
    else  //to traverse the list, to find out the apt position for insertion
    {
        ptr=head;
        while(ptr->value<newNode->value)
        {
            ptr=ptr->next;

        }
        ptr->prev->next=newNode;
        newNode->prev=ptr->prev;
        ptr->prev=newNode;
        newNode->next=ptr;
    }
}

//function to display the contents of the list

void print()
{
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->value);
        ptr=ptr->next;
    }
}

void main()
{
    int n;
    printf("\nEnter the total number of elements you want to insert:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        create();
    printf("\nSorted LL:\n");
    print();
}
