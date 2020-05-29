%{
#include "y.tab.h"
%}

%%
[a-zA-Z] {return letter;}
[0-9] {return digit;}
[\n] {return nl;}
[_]  {return unscore;}
.    {return yytext[0];}
%%

int yywrap(void){return 1;}
