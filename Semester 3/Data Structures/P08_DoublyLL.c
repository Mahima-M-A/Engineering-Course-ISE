//Program to implement the doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int value;
    struct node *next;
}*head,*newNode,*tail,*searchptr,*pointer, *after, *before;

int count = 0;//To count the number of nodes created

/* Generic function to create a new node */
void createNewNode()
{
    int data;

    newNode =(struct node *)malloc(1*sizeof(struct node));
    newNode->prev = NULL;
    newNode->next = NULL;
    printf("\n Enter value to create new node : ");
    scanf("%d", &data);
    newNode->value = data;
    count++;
}

/*  To insert at beginning */

void insertBegin()
{
    if (head == NULL)
    {
        createNewNode();
        head = newNode;
        tail = head;
    }
    else
    {
        createNewNode();
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}//end insertBegin

/* To insert at end */

void insertEnd()
{
    if (head == NULL)
    {
        createNewNode();
        head = newNode;
        tail = head;
    }
    else
    {
        createNewNode();
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}//end insertEnd

/* Function to insert before a value searched */

void insertBefore()
{
    after = searchptr->prev;

    if(searchptr == head)
    {
        insertBegin();
    }
    else
    {
        createNewNode();
        searchptr->prev = newNode;
        newNode->next = searchptr;
        after->next = newNode;
        newNode->prev = after;
    }

}//end insertBefore

/* Function to insert after a value searched */

void insertAfter()
{
    before = searchptr->next;

    if(searchptr == tail)
    {
        insertEnd();
    }
    else
    {
        createNewNode();
        searchptr->next = newNode;
        newNode->prev = searchptr;
        before->prev = newNode;
        newNode->next = before;
    }

}//end insertBefore

//function to display the contents of the list

void printAll()
{
    pointer = head;

    if (pointer == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("\n Linked list contains : ");

    while (pointer->next != NULL)
    {
        printf(" %d ", pointer->value);
        pointer = pointer->next;
    }
    printf(" %d ", pointer->value);
}//end printAll

//function to search for a number in the list
//returns the pointer to the containing the number else returns NULL

struct node * mysearch(int data)
{
    searchptr = head;

    if (searchptr == NULL)
    {
        printf("\n Error : List is empty to search for data");
        return NULL;
    }

    while (searchptr != NULL)
    {
        if (searchptr->value == data)
        {
            return searchptr;
        }
        else
            searchptr = searchptr->next;
    }
    return NULL;
}//end mysearch

/* Function to
 --- delete node at beginning
 --- delete node for a given value
 --- delete node at end
 */
 
void deleteNode()
{
    pointer = head;

        if(searchptr == head)
        {
            head = searchptr->next;
            free(searchptr);
            return;
        }
        if(searchptr == tail)
        {
            tail = searchptr->prev;
            tail->next = NULL;
            free(searchptr);
            return;
        }

            before = searchptr->next;
            after = searchptr->prev;
            before->prev = after->next;
            after->next = before;
            free(searchptr);
            return;

}//end deleteNode

int main()
{
    int ch;

    head = NULL;
    newNode = NULL;
    tail = NULL;
    searchptr = NULL;
    int data;

    printf("\n 1 - Insert begin");
    printf("\n 2 - Insert at end");
    printf("\n 3 - Insert before a value");
    printf("\n 4 - Insert after a value");
    printf("\n 5 - Search node");
    printf("\n 6 - Delete a value");
    printf("\n 7 - Display");
    printf("\n -1 - Quit");

    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                insertBegin();printAll();
                break;
            case 2:
                insertEnd();printAll();
                break;
            case 3:printf("\n Enter value to insert before : ");
                scanf("%d", &data);
                searchptr = mysearch(data);
                if(searchptr != NULL)
                {
                    insertBefore();printAll();
                }
                else printf("\n value %d not found to insert before!!", data );
                break;
            case 4:
                printf("\n Enter value to insert after : ");
                scanf("%d", &data);
                searchptr = mysearch(data);
                if(searchptr != NULL)
                {
                    insertAfter();printAll();
                }
                else printf("\n value %d not found to insert after!!", data );
                break;
            case 5:
                printf("\n Enter element to search : ");
                scanf("%d", &data);
                searchptr = mysearch(data);
                if(searchptr == NULL) printf("\n value %d not found!!", data );
                else printf("\n %d value found!!",searchptr->value );
                break;
            case 6:
                printf("\n Enter value to delete: ");
                scanf("%d", &data);
                searchptr = mysearch(data);
                if(searchptr != NULL)
                {
                    deleteNode();
                    printAll();
                }
                else printf("\n value %d not found to delete!!", data );
                break;
            case 7:
                printAll();
                break;
            case -1:
                exit(0);
            default:
                printf("\n Wrong choice menu");
        }//end switch
    }//end while
}//end main
