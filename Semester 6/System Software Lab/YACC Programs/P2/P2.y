%{
#include<stdio.h>
#include<stdlib.h>
%}

%token digit letter nl unscore
%%
stmt:variable nl {printf("valid identifier\n");exit(0);}
;
variable:letter alphanumeric
;
alphanumeric:letter alphanumeric
|digit alphanumeric
|unscore alphanumeric
|letter
|digit
|unscore
;
%%
int yyerror(char * msg)
{
	printf("Invalid\n");
	exit(0);
}

int main()
{
	printf("enter variable name: ");
	yyparse();
	return 0;
}

