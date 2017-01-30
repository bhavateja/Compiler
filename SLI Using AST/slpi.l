%{
	#include <bits/stdc++.h>
    using namespace std;

	#include "y.tab.h"
    int number;
%}

%%

[0-9]+ {number = atoi(yytext); yylval = tokenNode(1,number); return NUM;}
"+"	{ yylval = tokenNode(3, -1, yytext[0]); return PLUS;}
"-"	{yylval = tokenNode(3, -1, yytext[0]); return MINUS;}
"*"	{ yylval = tokenNode(3, -1, yytext[0]); return MUL;}
"/"	{yylval = tokenNode(3, -1, yytext[0]);return DIV;}
"=" {yylval = tokenNode(3, -1, yytext[0]);return ASSGN;}
";" { return *yytext;}
"read" {yylval = tokenNode(4, 1, '\0');return READ;}
"write" {yylval = tokenNode(4, 2, '\0'); return WRITE;}
[a-z] { yylval = tokenNode(2, -1, yytext[0]); return ID;}
" " {}
[\t] {}
[()] {return *yytext;}
[\n] {return END;}
. {yyerror("unknown character");exit(1);}

%%

int yywrap(void) {
	return 1;
}