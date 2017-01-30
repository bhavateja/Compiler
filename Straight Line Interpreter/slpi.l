%{
	#include <stdio.h>
	#include "y.tab.h"
	#include <stdlib.h>
    int number;
%}

%%

[0-9]+ {number = atoi(yytext); yylval = number; return NUM;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"=" {return ASSGN;}
";" { return *yytext;}
"read" {return READ;}
"write" {return WRITE;}
[a-z] {yylval = yytext[0] - 'a' + 1; return ID;}
" " {}
[\t] {}
[()] {return *yytext;}
[\n] {return END;}
. {yyerror("unknown character");exit(1);}

%%

int yywrap(void) {
	return 1;
}