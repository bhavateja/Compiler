%{
	#include <iostream>
	#include <cstdio>
	#include "stack.hh"
	#include <cstdlib>
	using namespace std;
    int number;
%}

%option c++
%%

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