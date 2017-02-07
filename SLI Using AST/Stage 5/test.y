%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	int vars[30];
	#include "decl.h"
	#include "exptest.h"

	int yylex(void);
	extern FILE *yyin;
	#define YYSTYPE tnode *
%}


%token INT DECL ENDDECL ENDOFFILE MAIN READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE END NUM ID PLUS MINUS MUL DIV ASSGN LT LE GT GE EQ NEQ

%left PLUS MINUS
%left MUL DIV
%nonassoc LT GT LE GE EQ NEQ

%%

program : declarations mainBlock ENDOFFILE {}

declarations : DECL declList ENDDECL {}
		| DECL ENDDECL

declList : declS declList	{}
		| declS {}

declS : INT int_idList ';' 	{}

int_idList : ID ',' int_idList { Ginstall($1->NAME, INT, 1);}
		| ID '[' NUM ']' ',' int_idList {Ginstall($1->NAME,INT,$3->VALUE);}
		| ID '[' NUM ']' {Ginstall($1->NAME,INT,$3->VALUE);}
		| ID 	{Ginstall($1->NAME, INT, 1);}

mainBlock : MAIN '(' ')' '{' Slist '}' { printf("TREE CREATED\n"); evaluate($5); exit(1);}

Slist : Stmt Slist { $$ = treeCreate(-1,-1,0,'\0',NULL,$1,$2,NULL); }
	  | Stmt { $$ = $1; }

Stmt : VAR ASSGN E ';' 	{$$ = treeCreate(0,ASSGN,0,'\0',NULL,$1,$3,NULL);}
	 | READ '(' VAR ')' ';' 	{$$ = treeCreate(0,READ,0,'\0',NULL,$3,NULL,NULL);}
	 | WRITE '(' E ')' ';'	{$$ = treeCreate(0,WRITE,0,'\0',NULL,$3,NULL,NULL);}
	 | IF '(' E ')' THEN Slist ELSE Slist ENDIF ';' { $$ = treeCreate(0,IF,0,'\0',NULL,$3,$6,$8); } 
	 | WHILE '(' E ')' DO Slist ENDWHILE ';' {$$ = treeCreate(0,WHILE,0,'\0',NULL,$3,$6,NULL);}
	 ;

VAR : ID 	{$$ = $1;}
	| ID '[' E ']'  {$1->Ptr1 = $3; $$ = $1;}

E : E PLUS E 	{ $$ = treeCreate(0,PLUS,0,'\0',NULL,$1,$3,NULL); }
  | E MUL E 	{ $$ = treeCreate(0,MUL,0,'\0',NULL,$1,$3,NULL); }
  |	E LT E	{$$ = treeCreate(0,LT,0,'\0',NULL,$1,$3,NULL);}
  | E GT E	{$$ = treeCreate(0,GT,0,'\0',NULL,$1,$3,NULL);}
  |	E LE E	{$$ = treeCreate(0,LE,0,'\0',NULL,$1,$3,NULL);}
  | E GE E	{$$ = treeCreate(0,GE,0,'\0',NULL,$1,$3,NULL);}
  | E EQ E	{$$ = treeCreate(0,EQ,0,'\0',NULL,$1,$3,NULL);}
  | E NEQ E	{$$ = treeCreate(0,NEQ,0,'\0',NULL,$1,$3,NULL);}
  | '(' E ')' 	{ $$ = $1;}
  | NUM 	{ $$ = $1;}
  | VAR 	{  $$ = $1;}	 

%%


	#include "decl.c"
	#include "exptest.c"


yyerror(char const *s)
{
    printf("yerror %s",s);
}


int main(int argc, char *argv[]) {
	if(argc>1){
		FILE *fp = fopen(argv[1],"r");
		if(fp) yyin = fp;
	}
	yyparse();
	return 0;
}