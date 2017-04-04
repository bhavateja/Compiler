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
"initialize"    {yylval = treeCreate(NULL,INIT,1,'\0',NULL,NULL,NULL,NULL); return INIT;}
"alloc"         {yylval = treeCreate(NULL,ALLOC,1,'\0',NULL,NULL,NULL,NULL); return ALLOC;}
"free"			{yylval = treeCreate(NULL,FREE,1,'\0',NULL,NULL,NULL,NULL); return FREE;}
"exit"          {yylval = treeCreate(NULL,EXIT,1,'\0',NULL,NULL,NULL,NULL); return EXIT;}
"begin"         {return BEGINNING;}
"null"          {yylval = treeCreate(NULL,NULL_NODE,-1,'\0',NULL,NULL,NULL,NULL); return NULL_NODE;}
"end"           {return END;}
"type"          {return TYPEI;}
"endtype"       {return ENDTYPEI;}
"return"		{return RETURN;}
"decl" 			{return DECL;}
"enddecl" 		{return ENDDECL;}
"int" 			{return INT;}
"bool" 			{return BOOL;}
"," 			{return *yytext;}
"."             {return *yytext;}
"main" 			{return MAIN;}
[0-9]+ 			{number = atoi(yytext); yylval = treeCreate(NULL,CONST,number,'\0',NULL,NULL,NULL,NULL); return NUM;}
"true" 			{yylval = treeCreate(NULL,CONST,1,'\0',NULL,NULL,NULL,NULL); return TRUE;}
"false" 		{yylval = treeCreate(NULL,CONST,0,'\0',NULL,NULL,NULL,NULL); return FALSE;}
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
[a-zA-Z][a-zA-Z0-9]* {yylval = treeCreate(NULL,ID,0,strdup(yytext),NULL,NULL,NULL,NULL); return ID;}
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