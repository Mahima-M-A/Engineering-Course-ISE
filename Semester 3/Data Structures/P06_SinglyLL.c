//Program to implement singly linked list

#include<stdio.h>
#include<stdlib.h>

int count=0,val;  //'count' counts the number of nodes present in the list 

typedef struct node
{
    int value;
    struct node *next;
}node;

//function to print the menu

void menu()
{
    printf("\nMENU:\n");
    printf("0.Menu:\n");
    printf("1.Insert Begin\n");
    printf("2.Insert End\n");
    printf("3.Search Node\n");
    printf("4.Insert After\n");
    printf("5.Insert Before\n");
    printf("6.Display\n");
    printf("7.Delete Begin\n");
    printf("8.Delete Last\n");
    printf("9.Delete any node\n");
    printf("-1.Quit\n");
}

//function to print the contents of the list

void printDetails(node *head)
{
    if(head==NULL)
    {
        printf("Linked list is empty!\n\n");
    }
    else
    {
        node *ptr=head;
        printf("\nTotal number of nodes present: %d\n",count);
        while(ptr!=NULL)
        {
            printf(" Value:%d -> ",ptr->value);
            ptr=ptr->next;
        }
    }
}

//function to create a node of the list

node * createNode(node *next,int val)
{
    node *newNode=(node*)malloc(sizeof(node));
    newNode->value=val;
    newNode->next=next;
    count++;
    return newNode;
}

//function to insert at the beginning

node * insertBegin(node *head,int val)
{
    if(head==NULL)
        printf("\nFirst node to inserted\n");
    node * newNode=createNode(head,val);
    head=newNode;
    return head;

}

//function to insert at the end

node * insertEnd(node *head,int val)
{
    if(head==NULL)
        return NULL;
    else
    {
        node *ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        node *newNode=createNode(NULL,val);
        ptr->next=newNode;
        return head;
    }
}

//function to search for a number in the list
//returns the pointer to the node which contains that number else returns NULL

node *search(node *head,int val)
{
    node *ptr=head;
    if(head==NULL)
        return NULL;
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->value==val)
                return ptr;
            else
                ptr=ptr->next;
        }
        return NULL;
    }
}

//function to insert after an existing node

node * insertAfter(node *head,node *after,int val)
{
    if(head==NULL || after==NULL)
        return NULL;
    node *ptr=head;
    while(ptr!=after)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    {
        node *newNode=createNode(ptr->next,val);
        ptr->next=newNode;
        return head;
    }
    else
        return NULL;
}

//function to insert before an existing node

node * insertBefore(node *head,node *before,int val)
{
    if(before==NULL || head==NULL)
        return NULL;
    if(before==head)
    {
        head=insertBegin(head,val);
        return head;
    }
    node *ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->next==before)
            break;
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    {
        node *newNode=createNode(ptr->next,val);
        ptr->next=newNode;
        return head;
    }
    else
        return NULL;
}

//function to delete the first node

node * deleteBegin(node *head)
{
    if(head==NULL)
        return NULL;
    node *ptr=head;
    /*printf("Current head address:%d",head);
    printf("Node that will be deleted is of value:%d",head->value);*/
    head=head->next;
    //printf("Head is reassigned as %d",head);
    ptr->next=NULL;
    free(ptr);
    count--;
    return head;
}

//function to delete the last node

node * deleteLast(node *head)
{
    if(head==NULL)
        return NULL;
    node *lastnodeptr=head;
    node *secondlastnodeptr=NULL;
    while(lastnodeptr->next!=NULL)
    {
        secondlastnodeptr=lastnodeptr;
        lastnodeptr=lastnodeptr->next;
    }
    if(secondlastnodeptr!=NULL)
        secondlastnodeptr->next=NULL;
    if(lastnodeptr==head)
        head=NULL;
    free(lastnodeptr);
    count--;
    return head;
}

//function to delete a particular node

node * deleteAny(node *head,node *sptr)
{
    if(sptr==NULL)
        return NULL;
    if(sptr==head)
    {
        head=deleteBegin(head);
        return head;
    }
    if(sptr->next==NULL)
    {
        head=deleteLast(head);
        return head;
    }
    node *ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->next==sptr)
            break;
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    {
        ptr->next=sptr->next;
        sptr->next=NULL;
        free(sptr);
        count--;
    }
    return head;
}

int main()
{
    node *head=NULL;
    node *sptr=NULL;
    int ch;
    menu();
    while(1)
    {
        printf("\nEnter choice(0-9 or -1 to quit):");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: menu();
                break;
            case 1: printf("Enter a number:");
                    scanf("%d",&val);
                    head=insertBegin(head,val);
                    printDetails(head);
                break;
            case 2: printf("Enter a number:");
                    scanf("%d",&val);
                    head=insertEnd(head,val);
                    printDetails(head);
                break;
            case 3: printf("\nEnter the value to be searched for:");
                    scanf("%d",&val);
                    sptr=search(head,val);
                    if(sptr!=NULL)
                        printf("\n%d is found\n",sptr->value);
                    else
                        printf("\n%d is not found\n",val);
                break;
            case 4: printf("\nEnter the value after which we need to insert:");
                    scanf("%d",&val);
                    sptr=search(head,val);
                    if(sptr!=NULL)
                    {
                        printf("\nEnter the value to be inserted:");
                        scanf("%d",&val);
                        head=insertAfter(head,sptr,val);
                        printDetails(head);
                    }
                    else
                        printf("\n%d not found hence could not insert!",val);
                break;
             case 5: printf("\nEnter the value before which we need to insert:");
                    scanf("%d",&val);
                    sptr=search(head,val);
                    if(sptr!=NULL)
                    {
                        printf("\nEnter the value to be inserted:");
                        scanf("%d",&val);
                        head=insertBefore(head,sptr,val);
                        if(head!=NULL)
                            printDetails(head);
                    }
                    else
                        printf("\n%d not found hence could not insert!",val);
                break;
            case 6: if(head!=NULL)
                        printDetails(head);
                    else
                        printf("\nNo nodes!");
                break;
            case 7: head=deleteBegin(head);
                    printDetails(head);
                break;
            case 8: head=deleteLast(head);
                    printDetails(head);
                break;
            case 9: printf("\nEnter the value to be deleted:");
                    scanf("%d",&val);
                    sptr=search(head,val);
                    if(sptr!=NULL)
                    {
                        head=deleteAny(head,sptr);
                        printDetails(head);
                    }
                    else
                        printf("\n%d is not found hence could not be deleted!",val);
                break;
            case -1: exit(0);
        }
    }
}
