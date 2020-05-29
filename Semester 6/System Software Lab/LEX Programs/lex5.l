%{
#include<stdio.h>
int pcount = 0, ncount = 0, pdec = 0, ndec = 0;
%}

%%
[/+]?[0-9]+ {pcount++;}
[/-][0-9]+ {ncount++;}
[/+]?[0-9]+[/.][0-9]+ {pdec++;}
[/-][0-9]+[/.][0-9]+ {ndec++;}
%%

int yywrap() { return 1 ; }

int main()
{
	printf("Enter numbers: ");
	yylex();
	printf("Number of positive numbers are : %d \n Number of negative numbers are : %d \n",pcount,ncount);
	printf("Number of positive decimals are : %d \n Number of negative decimals are : %d \n",pdec,ndec);
	return 0;
}
