%{ 
#include<stdio.h> 
int id=0, op=0, clines=0; 
%} 
OPERATOR "+"|"-"|"*"|"/"
%%
"//".* {clines++;}
"/*"[^"*/"]*"*/" {clines++;}
{OPERATOR} {op++;}
= ;
[ \t\n] ;
[0-9]+[a-zA-Z0-9_]* ;
[a-zA-Z_][a-zA-Z0-9_]* {id++; ECHO; printf("\n");}
[!@#$^&%()}{|;.<>?:"'~`\[\]]+[a-zA-Z0-9_]* ; 
. ;
%%

int yywrap() { return 1 ; }

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		printf("Usage: <./a.out> <sourcefile>\n");
		exit(0);
	}
	yyin=fopen(argv[1],"r");

	yylex();
	printf("No of identifiers=%d\nNo of operators=%d\nNo of comment lines=%d\n",id,op,clines);
	return 0; 
}
