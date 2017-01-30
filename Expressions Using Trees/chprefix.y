%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define YYSTYPE char*
	int yylex(void);
%}

%token NUM NAME PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END	{
				printf("%s\n",$1);
				exit(1);
			}
		;

expr : expr PLUS expr		{$$ = (char*)malloc(200*sizeof(char)); strcat($$,"+"); strcat($$,$1); strcat($$,$3);}
     | expr MINUS expr  	{$$ = (char*)malloc(200*sizeof(char)); strcat($$,"-"); strcat($$,$1); strcat($$,$3);}
     | expr MUL expr	{ $$ = (char*)malloc(200*sizeof(char)); strcat($$,"*"); strcat($$,$1); strcat($$,$3);}
     | expr DIV expr	{ $$ = (char*)malloc(200*sizeof(char)); strcat($$,"/"); strcat($$,$1); strcat($$,$3); }
	 | '(' expr ')'		{$$ = strdup($2);}
	 | NAME			{$$ = strdup($1); }
	 ;

%%

yyerror(char const *s)
{
    printf("yerror %s",s);
}


int main(void) {
	yyparse();
	return 0;
}