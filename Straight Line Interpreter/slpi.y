%{
	#include <stdio.h>
	#include <stdlib.h>
	#define YYSTYPE int
	int vars[30];
	int yylex(void);
%}

%token NUM ID PLUS MUL ASSGN READ WRITE SEPAR END
%left PLUS MINUS
%left MUL DIV

%%

Slist : Stmt Slist END {exit(1);}
	  | Stmt END { exit(1); }
Stmt : ID ASSGN E ';' 	{ vars[$1] = $3; }
	 | READ '(' ID ')' ';' 	{ scanf("%d",&vars[$3]); }
	 | WRITE '(' E ')' ';'	{ printf("%d",$3); }
	 ;
E : E PLUS E 	{$$ = $1+$3;}
  | E MUL E 	{$$ = $1*$3;}
  | '(' E ')' 	{$$ = $2;}
  | NUM 	{$$ = $1;}
  | ID 	{ $$ = vars[$1];}	 


%%

yyerror(char const *s)
{
    printf("yerror %s",s);
}


int main(void) {
	yyparse();
	return 0;
}