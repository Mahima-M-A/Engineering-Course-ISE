%{
#include<stdio.h>
#include<stdlib.h>
%}

%token num nl

%%
stmt:num nl {printf("Valid expression\n");exit(0);};
%%

int yyerror(char *msg)
{
	printf("Invalid expression\n");
	exit(0);
}

int main()
{
	printf("Enter expression: ");
	yyparse();
	return 0;
}

