%{
#include<stdio.h>
#include"y.tab.h"
%}
%%
"a"	{return A;}
"b"	{return B;}
\n {return NL;}
.	{return yytext[0];}
%%
int yywrap(void){return 1;}