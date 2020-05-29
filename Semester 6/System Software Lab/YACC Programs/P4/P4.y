%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A B NL
%left A B NL
%%
stmt: S NL {printf("\nValid Expression\n"); exit(0);}
;
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
	return 0;
}
