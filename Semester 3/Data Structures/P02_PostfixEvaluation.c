//Program to evaluate a postfix expression like 23+ = 5

#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define SIZE 40

int stack[SIZE], top=-1;
char postfix[SIZE];

//pushes each digit of the expression into the stack also the result of each operation

void push(int element)
{
  if(top==SIZE-1)
  {
    printf("Error: Stack overflow\n");
  }
  else
  {
    stack[++top]=element;
  }
}

//pops out each number of the stack also the result of each operation

int pop()
{
  if(top==-1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
  else
    return(stack[top--]);
}

//checks the validity of the entered postfix expression

int valid()
{
  int digits=0,operators=0,i;

  if(!(isdigit(postfix[0]) && isdigit(postfix[1]))) //to check if the first and second element of the expression are digits or not
    return(0);

  for(i=0;postfix[i]!='\0';i++)
  {
    if(isdigit(postfix[i])) 
      digits++;  //counts the number of digits in the expression
    else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='^')
      operators++;  //counts the number of operators in the expression
    else
      return (0);
  }

  if(digits-operators!=1)  //checks if difference between number of digits and operators is 1 or not
    return (0);

  return (1);
}

void evaluate()
{
  int i,x1,x2;
  char ch;

  for(i=0;postfix[i]!='\0';i++)
  {
    ch=postfix[i];
    if(isdigit(ch))
    {
      push(ch-'0'); //pushes the digit into the stack by subtracting ascii value of '0' from the char ch
    }
    else //checks for the type of operation to berformed
    {
        x2=pop();
        x1=pop();
        switch(ch)
        {
            case '+':push(x1+x2);break;
            case '-':push(x1-x2);break;
            case '*':push(x1*x2);break;
            case '^':push(pow(x1,x2));break;
            case '/':
                if(x2==0)
                {
                    printf("The result is: infinity\n");
                    break;
                }
                else
                    push(x1/x2);
        }
    }
  }
}

int main()
{
  char ch;
  while(1)
  {
    printf("Enter a valid postfix expression: \n");
    scanf("%s",postfix);
    if(valid())
    {
      break;
    }
    else
      printf("The postfix expression entered is invalid\n\n");
  }
    evaluate();
    int result=pop();
    if(result!=-1)
        printf("The result is: %d\n",result);
  return 0;
}
