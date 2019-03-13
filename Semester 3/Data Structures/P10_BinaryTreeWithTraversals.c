//Program to implement a binary tree with traversals- preorder,inorder,postorder

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left, *right;
    int data;
} node;

node *tree = NULL; //Global pointer to hold the pointer of root node

//function to create a node

node *createNode(int data)
{
    if (data == -1) //We choose -1 to represent null so when user enters -1, its considered null
        return NULL;

    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

//Creates a binary tree with the root given as parameter

node *createTree(node *root)
{
    int data;

    if (root == NULL) //Case for first node
    {
        printf("Enter the root element: ");
        scanf("%d", &data);
        root = createNode(data);
        tree = root; //Global tree pointer holds this root value as it is the first node
    }

    printf("\n\nThe current root element is: %d\n", root->data); //Informs the current node we are at
    printf("Enter the left branch element (-1 for NULL): ");
    scanf("%d", &data);
    root->left = createNode(data); //New node is created at the left pointer

    printf("Enter the right branch element (-1 for NULL): ");
    scanf("%d", &data);
    root->right = createNode(data); //New node is created at the right pointer

    if (root->left != NULL) //If there is a node in root's left pointer, call createTree() there so it grows the left branch as required.
        createTree(root->left);

    if (root->right != NULL) //If there is a node in root's right pointer, call createTree() there so it grows the right branch as required.
        createTree(root->right);
}

//function to display the tree itself

void display(node * root,int i)
{
    int j;

    if(root!=NULL)
    {
        display(root->right,i+1);
        for(j=1;j<=i;j++) printf("\t");
        printf("%d\n",root->data);
        display(root->left,i+1);

    }

}

//function to print the tree elements in preorder

void preOrderPrint(node *root)
{
    if (root != NULL)
    {
        printf("%d  ", root->data); //Root first, left element second and then right element
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }
}

//function to print the tree elements in inorder

void inOrderPrint(node *root)
{
    if (root != NULL)
    {
        inOrderPrint(root->left); //Left first, root second, right third.
        printf("%d  ", root->data);
        inOrderPrint(root->right);
    }
}

//function to print the tree elements in postorder

void postOrderPrint(node *root)
{
    if (root != NULL)
    {
        postOrderPrint(root->left); //Left first, right second, root third.
        postOrderPrint(root->right);
        printf("%d  ", root->data);
    }
}

int main()
{
    createTree(NULL); //Creating a tree with initial root as NULL
    printf("\nDisplaying the tree:\n");
    display(tree,1);
    printf("\nPre order: ");
    preOrderPrint(tree);
    printf("\nIn order: ");
    inOrderPrint(tree);
    printf("\nPost order: ");
    postOrderPrint(tree);
    printf("\n");
    return (0);
}
