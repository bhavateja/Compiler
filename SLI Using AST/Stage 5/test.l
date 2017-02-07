%{
	#include <stdio.h>
	#include "y.tab.h"
	#include <stdlib.h>
	#include <string.h>
    int number;
%}

%%
<<EOF>> {return ENDOFFILE;}
"decl" {return DECL;}
"enddecl" {return ENDDECL;}
"int" {return INT;}
"," {return *yytext;}
"main" {return MAIN;}
[0-9]+ {number = atoi(yytext); yylval = treeCreate(0,NUM,number,'\0',NULL,NULL,NULL,NULL); return NUM;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"=" {return ASSGN;}
"!=" {return NEQ;}
"==" {return EQ;}
"<" {return LT;}
">" {return GT;}
"<=" {return LE;}
">=" {return GE;}
";" { return *yytext;}
"read" {return READ;}
"write" {return WRITE;}
"if" {return IF;}
"then" {return THEN;}
"else" {return ELSE;}
"endif" {return ENDIF;}
"while" {return WHILE;}
"do" {return DO;}
"endwhile" {return ENDWHILE;}
[a-zA-Z][a-zA-Z0-9]* {yylval = treeCreate(0,ID,0,strdup(yytext),NULL,NULL,NULL,NULL); return ID;}
" " {}
"[" {return *yytext;}
"]" {return *yytext;}
[\t] {}
[()] {return *yytext;}
[{}] {return *yytext;}
[\n] {}
. {yyerror("unknown character");exit(1);}

%%

int yywrap(void) {
	return 1;
}