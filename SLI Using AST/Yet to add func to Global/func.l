%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
    int number;
    int line;
%}

%%
<<EOF>> 		{return ENDOFFILE;}
"return"		{return RETURN;}
"decl" 			{return DECL;}
"enddecl" 		{return ENDDECL;}
"int" 			{return INT;}
"bool" 			{return BOOL;}
"," 			{return *yytext;}
"main" 			{return MAIN;}
[0-9]+ 			{number = atoi(yytext); yylval = treeCreate(INT,CONST,number,'\0',NULL,NULL,NULL,NULL); return NUM;}
"true" 			{yylval = treeCreate(BOOL,CONST,1,'\0',NULL,NULL,NULL,NULL); return TRUE;}
"false" 		{yylval = treeCreate(BOOL,CONST,0,'\0',NULL,NULL,NULL,NULL); return FALSE;}
"%" 			{return MOD;}
"+"				{return PLUS;}
"-"				{return MINUS;}
"*"				{return MUL;}
"/"				{return DIV;}
"=" 			{return ASSGN;}
"!=" 			{return NEQ;}
"==" 			{return EQ;}
"<" 			{return LT;}
">" 			{return GT;}
"<=" 			{return LE;}
">=" 			{return GE;}
"&&" 			{return AND;}
"||" 			{return OR;}
"!" 			{return NOT;}
";" 			{return *yytext;}
"read" 			{return READ;}
"write" 		{return WRITE;}
"if" 			{return IF;}
"then" 			{return THEN;}
"else" 			{return ELSE;}
"endif" 		{return ENDIF;}
"while" 		{return WHILE;}
"do" 			{return DO;}
"endwhile" 		{return ENDWHILE;}
[a-zA-Z][a-zA-Z0-9]* {yylval = treeCreate(0,ID,0,strdup(yytext),NULL,NULL,NULL,NULL); return ID;}
" " 		{}
"[" 		{return *yytext;}
"]" 		{return *yytext;}
[\t] 		{}
[()] 		{return *yytext;}
[{}] 		{return *yytext;}
[\n] 		{line++;}
. 			{yyerror("unknown character");exit(1);}

%%

int yywrap(void) {
	return 1;
}