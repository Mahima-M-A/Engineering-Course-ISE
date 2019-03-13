//Program to implement an expression tree for the postfix expression and evaluate it

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*
 Structure contains the operator and the operands for the operator
 NOTE: Operand is always a leaf node
       Operator is always a parent node
 */
struct tree
{
    char data; //char type because it can store operator or operand
    struct tree *left,*right;
};

int top=-1;
struct tree *stack[20]; //An array of structures of tree type.
/*
 Each array element is a tree node
 This node contains only the operand as data with its left and
 right as NULL, because operands are leaf nodes.
 Or
 It contains the operator as data and the operand nodes as left
 and right elements.
 */
struct tree *node; //To make a temporary operator or operand node

//Function to push the 'operand/operator node' into the stack

void push(struct tree* node)
{
    stack[++top]=node;
}

//Function to pop the 'operand/operator node' from the stack

struct tree * pop()
{
    return(stack[top--]);
}

// Checking if the 'data' in the node is an operator or operand

int check(char ch)
{
    if(ch=='+'||ch=='-'||ch=='/'||ch=='*'||ch=='^')
        return 2;
    else
        return 1;
}

/* Calculating the value of postfix expression using recursion
 NOTE: Recursive functions use its implicit stack to store the
 Activation Records (pending functions in this stack, which are
 yet to be executed).
 E.g. For the expression 23+5*
 Activation Record #1 is:
 cal(node->left)*cal(node->right);
 That is: [cal(node->left)+cal(node->right)] * cal(5)
 Activation Record #2 is:
 cal(node->left)+cal(node->right); That is: cal(2) + cal(3)
 Activation Record #2 is executed first the Activation Record #1
 Since Stack is LIFO
 */

int cal(struct tree *node)
{
    int ch;
    ch=check(node->data);
    if(ch==1)
        return node->data-48;
    /*'data' is stored as char. This is done to get the integer value of this character data. 48 is the ASCII value of character zero '0'.*/

    else if(ch==2)
    {
        if(node->data=='+')
            return cal(node->left)+cal(node->right);
        if(node->data=='-')
            return cal(node->left)-cal(node->right);
        if(node->data=='*')
            return cal(node->left)*cal(node->right);
        if(node->data=='/')
            return cal(node->left)/cal(node->right);
        if(node->data=='^')
            return pow(cal(node->left),cal(node->right));
    }
    else
        return 0;
}

/* Displaying all node in order, just to know the infix order
 of the expression you have entered. Expression input expected here
 is postfix*/

void inorder(struct tree *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%c",node->data);
        inorder(node->right);
    }
}

/* making simple operand node and pushing into stack */

void operand(char b)
{
    node=(struct tree*)malloc(sizeof(struct tree));
    node->data=b;
    node->left=NULL;
    node->right=NULL;
    push(node);
}

/* making operator node than pop-up two nodes from stack and adding into operator node and finally push node into stack  */

void operators(char a)
{
    node=(struct tree*)malloc(sizeof(struct tree));
    node->data=a;
    node->right=pop();
    node->left=pop();
    push(node);
}

int main()
{
    int i,op,result;
    char postfix[20];

    printf("Enter the expression in postfix form \n");
    fflush(stdin);
    scanf("%s",postfix);

    i=0;
    for(i=0;postfix[i]!='\0';i++)
    {
        op=check(postfix[i]); //Check if operator or operand
        if(op==1)
            operand(postfix[i]);
        else if(op==2)
            operators(postfix[i]);
    }
    result=cal(stack[top]);
    printf("\nThe value of the postfix expression you entered is %d\n",result);
    printf("\nThe inorder traversal of the tree is: ");
    inorder(stack[top]);
    printf("\n");
}
