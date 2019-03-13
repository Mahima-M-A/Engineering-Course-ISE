//Program to implement circular linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *head = NULL, *searchPtr = NULL, *ptr = NULL, *newNode = NULL;

//function to print the menu

 void displayMenu()
{
    printf("\n\n ----------------  MENU  ----------------\n");
    printf("0. Display Menu\n");
    printf("1. Insert at the BEGINNING\n");
    printf("2. Insert at the END\n");
    printf("3. Insert BEFORE\n");
    printf("4. Insert AFTER\n");
    printf("5. DELETE an element\n");
    printf("6. Display the linked list\n");
    printf("-1. Exit\n");
}

//function to create a node

 void createNode() 
{
    int data;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->link = NULL;
}

//function to insert at the beginning

 void insertBegin()
{
    createNode();
     if (head == NULL)
    {
        head = newNode;
        head->link = head; //Linked to itself if its the only node
        return;
    }
     ptr = head;
    while (ptr->link != head) // Loop to find the last node
        ptr = ptr->link;
     newNode->link = head;
    head = newNode;
    ptr->link = head; // The last node's link is updated to the new head
}

//function to insert at the end

 void insertEnd()
{
    if (head == NULL) // Case when the list is empty
    {
        insertBegin();
        return;
    }
     createNode();
     ptr = head;
    while (ptr->link != head) // Loop to find the last node
        ptr = ptr->link;
     ptr->link = newNode;
    newNode->link = head; //Circular linking
}

//function to search for a particular number in the list 
//Returns the pointer to the node which contains the data that was searched for. Else returns NULL

 struct node *searchNode(int element) 
{
    if (head == NULL)
    {
        return NULL;
    }
     if (head->data == element)
        return head;
     ptr = head->link;
    while (ptr != head)
    {
        if (ptr->data == element)
            return ptr;
         ptr = ptr->link;
    }
    return NULL;
}

//function to insert a node before an existing node

 void insertBefore()
{
    ptr = head;
     if (searchPtr == head) //Case when the user wants to insert before the first node itself
    {
        insertBegin();
        return;
    }
     while (ptr->link != searchPtr) //Loop to search for the node which stands before the node before which the data has to be entered
        ptr = ptr->link;
     createNode();
    ptr->link = newNode;
    newNode->link = searchPtr;
}

//function to insert a node after an existing node

 void insertAfter()
{
    ptr = head;
     createNode();
    newNode->link = searchPtr->link;
    searchPtr->link = newNode;
}

//function to delete a node at any location

 void deleteNode()
{
    struct node *temp;
    if (searchPtr == head) // Case when the head is to be deleted
    {
        ptr = head;
        temp = head;
         while (ptr->link != head) // Loop to find the last node
            ptr = ptr->link;
         //Now ptr holds the last node
        head = head->link;
        ptr->link = head;
         free(temp);
        return;
    }
     ptr = head;
    while (ptr->link != searchPtr) //To search for the previous node, that lies before the node to be deleted.
        ptr = ptr->link;
    ptr->link = searchPtr->link;
    free(searchPtr);
}

//function to display the contents of the list

 void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
     else
    {
        ptr = head->link;
        printf("Head's link: %x\n", head);
        printf("Data: %d    Link: %x\n", head->data, head->link);
        while (ptr != head)
        {
            printf("Data: %d    Link: %x\n", ptr->data, ptr->link);
            ptr = ptr->link;
        }
    }
}

 int main()
{
    int menu;
    int element;
    displayMenu();
    while (1)
    {
        printf("Enter your choice: ");
        scanf(" %d", &menu);
        switch(menu)
        {
            case 0:
                displayMenu();
                break;
            case 1:
                insertBegin();
                display();
                break;
             case 2:
                insertEnd();
                display();
                break;
             case 3:
                printf("Enter the element you want to insert before: ");
                scanf("%d", &element);
                searchPtr = searchNode(element);
                 if (searchPtr == NULL)
                    printf("The element doesn't exist in the list\n");
                 else
                    insertBefore();
                display();
                 break;
             case 4:
                printf("Enter the element you want to insert before: ");
                scanf("%d", &element);
                searchPtr = searchNode(element);
                 if (searchPtr == NULL)
                    printf("The element doesn't exist in the list\n");
                 else
                    insertAfter();
                display();
                 break;
             case 5:
                printf("Enter the element you want to delete: ");
                scanf("%d", &element);
                searchPtr = searchNode(element);
                 if (searchPtr == NULL)
                    printf("The element doesn't exist in the list\n");
                 else
                    deleteNode();
                display();
                break;
             case 6:
                display();
                break;
            case -1:
                exit(0);
                break;
            default:
                printf("Wrong choice\n\n\n");
                break;
        }
    }
    return 0;
}
