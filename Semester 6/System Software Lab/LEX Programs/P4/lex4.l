%{
#include<stdio.h>
int vowel = 0,consonant = 0,number = 0,line = 0,special = 0;
%}

%%
[ ] ;
[aeiouAEIOU] {vowel++;}
[a-zA-Z] {consonant++;}
[0-9] {number++;}
. {special++;}
\n {line++;}
%%

int yywrap() { return 1 ; }

int main(int argc, char *argv[])
{
	if(argc!=2){
		printf("Usage: <./a.out> <sourcefile>\n");
		exit(0);
	}
	yyin=fopen(argv[1],"r");
	yylex();
	printf("Number of vowels are %d \nNumber of consonants are %d \nNumber of numbers are %d \nNumber of special are %d \nNumber of lines are %d \n ",vowel,consonant,number,special,line);
	return 0; 
}
