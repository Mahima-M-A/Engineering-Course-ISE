%{
#include<stdio.h>
#include"y.tab.h"
%}

%%
[0-9][0-9][0-9][0-9]+ {return num;}
\n {return nl;}
. {return yytext[0];}
%%

int yywrap() {return 1;}
