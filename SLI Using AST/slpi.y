%{
	#include <bits/stdc++.h>
	int vars[30];
	#include "exptree.h"
	#include "exptree.c"
    using namespace std;

	int yylex();
	#define YYSTYPE tnode *

	void yyerror(char const *s){
		printf("yerror %s",s);
	}


%}


%token NUM ID PLUS MUL ASSGN READ WRITE SEPAR END

%left PLUS MINUS
%left MUL DIV

%%

program : Slist END { evaluate($1); exit(1); }

Slist : Stmt Slist { $$ = createNode(); $$->STMT = -1; $$->ptr1 = $1; $$->ptr2 = $2; }
	  | Stmt { $$ = $1;}

Stmt : ID ASSGN E ';' 	{$2->ptr1 = $1; $2->ptr2 = $3; $$ = $2; $$->STMT = 1;}
	 | READ '(' ID ')' ';' 	{$1->ptr1 = $3; $$ = $1; $$->STMT = 1;}
	 | WRITE '(' E ')' ';'	{$1->ptr1 = $3; $$ = $1; $$->STMT = 1;}
	 ;

E : E PLUS E 	{ $2->ptr1 = $1; $2->ptr2 = $3; $$ = $2; $$->STMT = 2;}
  | E MUL E 	{ $2->ptr1 = $1; $2->ptr2 = $3; $$ = $2; $$->STMT = 2;}
  | '(' E ')' 	{ $$ = $2; $$->STMT = 2;}
  | NUM 	{ $$ = $1; $$->STMT = 2;}
  | ID 	{ $$ = $1; $$->STMT = 2; }	 


%%


int main(int argc, char *argv[]) {
	
	yyparse();
	return 0;
}