%{
#include<stdio.h>
%}
%token A B
%left A B

%%
S: A S|S B| ;
%%


int yyerror(char *msg)
{
	printf("\nInvalid Expression\n");
	exit(0);
}

int main()
{
	printf("Enter an Expression: ");
	yyparse();
	printf("\nValid Expression\n");
	return 0;
}
