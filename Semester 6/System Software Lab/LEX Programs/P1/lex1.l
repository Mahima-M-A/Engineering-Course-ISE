%{ 
#include<stdio.h> 
int w=0, c=0, s=0, l=0;
%}
BLANK [ ]
WORD ([a-zA-Z0-9])+
EOL (\n)
%%
{WORD} {w++; c=c+yyleng;}
{BLANK} {s++;}
{EOL} {l++;}
.  {c++;}
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
	printf("No of characters=%d\nNo of words=%d\nNo of spaces=%d\nNo of lines=%d",c,w,s,l);
	return 0; 
}
