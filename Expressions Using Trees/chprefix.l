%{
	#include <stdio.h>
	#include "y.tab.h"
	#include <stdlib.h>
	#include <string.h>
    int number;
%}

%%

[a-z]+ { yylval = strdup(yytext);  return NAME;}
[0-9]+ {number = atoi(yytext); yylval = number; return NUM;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
[\t] {}
[()] {return *yytext;}
[\n] {return END;}
. {yyerror("unknown character");exit(1);}

%%

int yywrap(void) {
	return 1;
}