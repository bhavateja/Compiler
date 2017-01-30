%{
	#include <stdio.h>
	#include <stdlib.h>
	#define YYSTYPE int
	int yylex(void);
%}

%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END	{
				exit(1);
			}
		;

expr : expr PLUS expr		{printf("+ ");}
     | expr MINUS expr  	{printf("- ");}
     | expr MUL expr	{printf("* ");}
     | expr DIV expr	{printf("/ ");}
	 | '(' expr ')'		{$$ = $2;}
	 | NUM			{$$ = $1; printf("%d ",$1);}
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