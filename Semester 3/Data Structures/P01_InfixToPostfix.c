//Program to convert the given infix expression to postfix expression

#include<stdio.h>
#include<ctype.h>
#define SIZE 40

char stack[SIZE];
int top=-1;
char infix[SIZE],postfix[SIZE];

void push(char element) //to push each operator into the stack
{
	if(top==SIZE-1)
		printf("Error: Stack overflow");
	else
	{
		stack[++top] = element;
	}
}

char pop() //to pop each operator from the stack
{
	if(top==-1)
	{
		printf("Error: Stack underflow");
		return('0');
	}
	else
	{
		return(stack[top--]);
	}
}

char peak() //to return the top of the stack
{
	if(top==-1)
		return('0');
	else
		return (stack[top]);

}

int priority(char x) //to check the priority or precedence of the operator
{
	switch(x)
	{
		case '(':
			return 1;
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 3;
    case '^':
      return 4;
		default:
			return -1;
	}
}

void intopostfix() //to convert infix expression to postfix expression
{
	int i,j=-1;
	for(i=0;infix[i]!='\0';i++)
	{
		if(infix[i]=='(') 
			push(infix[i]); //to push '(' into the stack

		else if(isalnum(infix[i]))
			postfix[++j] = infix[i];  //to add the operands into the postfix array

		else if(infix[i]==')') //to start popping from the stack 
		{
			while(peak()!='(') //to pop until '(' is encountered
			{
				postfix[++j]=pop(); //to add the operators into the postfix array
			}
			pop(); //pops '(' from the stack
		}
		else 
		{
			while(priority(peak())>=priority(infix[i])) //to check for the operator's priority
			{
				postfix[++j] = pop(); //to add the operators into the postfix array
			}
			push(infix[i]); //pushes the operator
		}
	}
	while(top!=-1)
	{
		postfix[++j] = pop(); //to pop out operators from the stack(if any)
	}
}

int valid() //to check for the validity of the infix expression
{
    if(!isalnum(infix[0])) //to check if first char is an operand or not
        return 0;
        
	int i,open=0,close=0,operands=0,operators=0;
	for(i=0;infix[i]!='\0';i++)
	{
		if(isalnum(infix[i]))
			operands++; //to count the no. of operands
      
		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^')
			operators++; //to count the no. of operators
      
		else if(infix[i]=='(')
			open++; //to count the no. of '('
      
		else if(infix[i]==')')
				close++; //to count the no. of ')'
        
		else
			return(0); //invalid if anything else is presnt
	}
	if((open!=close)||(digits-operators!=1)) //validity condition
		return(0);
	return(1);
}

int main()
{
	while(1)
	{
		printf("Enter the infix expression : ");
		scanf("%s",infix);
		if(valid())
			break;
		else
			printf("Invalid expression\n\n");
	}

	intopostfix();
	printf("Initial infix expression : %s\n",infix);
	printf("Final postfix expression : %s",postfix);
	return 0;
}
