//Program to create a BST with following operations- insert,display,traverse(preorder,inorder,postorder) 

#include<stdio.h>
#include<stdlib.h>


/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
     int key;
     struct node* left;
     struct node* right;
};

//Function to insert the tree elements in a sorted manner

struct node* insert(struct node*r, int x)
{
	if (r == NULL)
	{
            r = (struct node*)malloc(sizeof(struct node));
            r->key = x;
            r->left = r->right = NULL;
            return r;
	}
	else if (x < r->key)
            r->left = insert(r->left, x);
	else if (x > r->key)
            r->right = insert(r->right, x);
	return r;
}

//function to display the tree itself

void display(struct node * root,int i)
{
    int j;

    if(root!=NULL)
    {
        display(root->right,i+1);
        for(j=1;j<=i;j++) printf("\t");
        printf("%d\n",root->key);
        display(root->left,i+1);
    }
}

//function to display the tree elements in postorder

void printPostorder(struct node* node)
{
     if (node == NULL)
        return;

     // first recur on left subtree
     printPostorder(node->left);

     // then recur on right subtree
     printPostorder(node->right);

     // now deal with the node
     printf("%d ", node->key);
}

//function to display the tree elements in inorder

void printInorder(struct node* node)
{
     if (node == NULL)
          return;

     /* first recur on left child */
     printInorder(node->left);

     /* then print the data of node */
     printf("%d ", node->key);

     /* now recur on right child */
     printInorder(node->right);
}

//function to display the tree elements in preorder

void printPreorder(struct node* node)
{
     if (node == NULL)
          return;

     /* first print data of node */
     printf("%d ", node->key);

     /* then recur on left sutree */
     printPreorder(node->left);

     /* now recur on right subtree */
     printPreorder(node->right);
}

/* Driver program to test above functions*/
int main()
{
    struct node* root = NULL;
    int x, c = 1, z;
    int element;
  
    while(1)
    {
        printf("\n1 Insert an element ");
        printf("\n2 Display");
        printf("\n3 To print the preorder");
        printf("\n4 To print the inorder");
        printf("\n5 To print the postorder");
        printf("\n-1 Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
                printf("\nEnter the item:");
                scanf("%d", &z);
                root = insert(root,z);
                break;
            case 2: 
                if(root == NULL)
                    printf("\nTree empty");
                else
                {
                    printf("\n Display Root is %d",root->key);
                    printf("\n");
                    display(root,1);
                }
                break;
            case 3:
                printf("\nPreorder traversal of binary tree is \n");
                printPreorder(root);
                break;
            case 4:
                printf("\nInorder traversal of binary tree is \n");
                printInorder(root);
                break;
            case 5:
                printf("\nPostorder traversal of binary tree is \n");
                printPostorder(root);
                break;
            case -1:
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }
    return 0;
}
