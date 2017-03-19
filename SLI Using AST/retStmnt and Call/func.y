%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	int idx = 0;
	FILE *fp = NULL; 

	FILE *target = NULL;
	#include "decl.h"
	#include "exptest.h"
	#include "label.h"
	#include "codegen.h"

	struct Lsymbol *l_start = NULL;
	struct Lsymbol *l_end = NULL;

	int yylex(void);
	extern FILE *yyin;
	extern int line;
	#define YYSTYPE tnode *

	int variable_type;
%}


%token FUNC RETURN MOD AND OR NOT CONST TRUE FALSE INT BOOL DECL ENDDECL ENDOFFILE MAIN READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE END NUM ID PLUS MINUS MUL DIV ASSGN LT LE GT GE EQ NEQ

%left AND OR 
%left PLUS MINUS
%left MUL DIV
%nonassoc LT GT LE GE EQ NEQ NOT MOD

%%

program : GDefBlock mainBlock ENDOFFILE {}

GDefBlock : DECL GDefList ENDDECL 					{ fp = fopen("intermediate.xsm","w+"); write_header(); }
		| DECL ENDDECL								{ fp = fopen("intermediate.xsm","w+"); write_header(); }

GDefList : GDefList GDecl
		| GDecl

GDecl : Type GIdList ';'

GIdList : GIdList ',' GId 							{ 	}
		| GId 										{ 	}

GId : ID 											{ Ginstall($1->NAME,variable_type,1);					}
	| ID '[' NUM ']'								{ Ginstall($1->NAME,variable_type,$3->VALUE);			}
	| ID '(' ArgList ')'

ArgList : ArgList ',' Arg
		| Arg

Arg : Type ID

Type : INT 											{ variable_type = INT; }
	| BOOL											{ variable_type = BOOL;}


mainBlock : Type MAIN '(' ')' '{' LDefBlock Slist retStmt '}' 	    { 
																
																Ginstall("main",variable_type,0);
																struct Gsymbol* mainGentry = Glookup("main");
																mainGentry->localSymTable = l_start;																	
																
																fprintf(fp,"L0:\n");

																fprintf(fp,"PUSH BP\n");
																fprintf(fp,"MOV BP, SP\n");
																fprintf(fp,"ADD BP, 1\n");
																fprintf(fp,"ADD SP, %d\n",idx);

															 	code_gen($7); 
															    
															    fprintf(fp,"SUB SP, %d\n",idx);
															    fprintf(fp,"POP BP\n");
															    fprintf(fp,"RET\n");

															    printf("Intermediate Code Generated\n");
															    fclose(fp);


																l_start = l_end = NULL;
														
															    parse1();
															    printf("Label Table Created\n");
															    parse2();
															    printf("Target Code Generated\n");

																exit(1);
															}

retStmt : RETURN E ';'				{$$ = treeCreate(0,RETURN,0,'\0',NULL,$2,NULL,NULL);}

LDefBlock : DECL LDefList ENDDECL 	{}
		| DECL ENDDECL				{}

LDefList :  LDefList LDecl
		| LDecl

LDecl : Type LIdList ';'

LIdList : LIdList ',' LId
		| LId

LId : ID 											{ Linstall($1->NAME,variable_type,1); 			}
	| ID '[' NUM ']'								{ Linstall($1->NAME,variable_type,$3->VALUE);	}


Slist : Stmt Slist { $$ = treeCreate(-1,-1,0,'\0',NULL,$1,$2,NULL); }
	  | Stmt { $$ = $1; }

Stmt : VAR ASSGN E ';' 								{ typeCheckNode($1,$3->TYPE);  $$ = treeCreate(0,ASSGN,0,'\0',NULL,$1,$3,NULL);}
	 | READ '(' VAR ')' ';' 						{ 						  	   $$ = treeCreate(0,READ,0,'\0',NULL,$3,NULL,NULL);}
	 | WRITE '(' E ')' ';'							{ typeCheckNode($3,INT);	   $$ = treeCreate(0,WRITE,0,'\0',NULL,$3,NULL,NULL);}
	 | IF '(' E ')' THEN Slist ELSE Slist ENDIF ';' { typeCheckNode($3,BOOL); 	   $$ = treeCreate(0,IF,0,'\0',NULL,$3,$6,$8); } 
	 | WHILE '(' E ')' DO Slist ENDWHILE ';' 		{ typeCheckNode($3,BOOL); 	   $$ = treeCreate(0,WHILE,0,'\0',NULL,$3,$6,NULL);}
	 ;

VAR : ID 			{  updateEntry($1); $$ = $1;}
	| ID '[' E ']'  {  typeCheckNode($3,INT); updateEntry($1); $1->Ptr1 = $3; $$ = $1;}

E : E PLUS E 	{ typeCheckNodes($1,$3,INT);  $$ = treeCreate(INT,PLUS,0,'\0',NULL,$1,$3,NULL); }
  | E MUL E 	{ typeCheckNodes($1,$3,INT);  $$ = treeCreate(INT,MUL,0,'\0',NULL,$1,$3,NULL); 	}
  | E MINUS E   { typeCheckNodes($1,$3,INT);  $$ = treeCreate(INT,MINUS,0,'\0',NULL,$1,$3,NULL);  }
  | E DIV E 	{ typeCheckNodes($1,$3,INT);  $$ = treeCreate(INT,DIV,0,'\0',NULL,$1,$3,NULL);  }
  | E MOD E 	{ typeCheckNodes($1,$3,INT);  $$ = treeCreate(INT,MOD,0,'\0',NULL,$1,$3,NULL);  }
  |	E LT E		{ typeCheckNodes($1,$3,INT);  $$ = treeCreate(BOOL,LT,0,'\0',NULL,$1,$3,NULL);	}
  | E GT E		{ typeCheckNodes($1,$3,INT);  $$ = treeCreate(BOOL,GT,0,'\0',NULL,$1,$3,NULL);	}
  |	E LE E		{ typeCheckNodes($1,$3,INT);  $$ = treeCreate(BOOL,LE,0,'\0',NULL,$1,$3,NULL);	}
  | E GE E		{ typeCheckNodes($1,$3,INT);  $$ = treeCreate(BOOL,GE,0,'\0',NULL,$1,$3,NULL);	}
  | E EQ E		{ typeCheckNodesEq($1,$3);    $$ = treeCreate(BOOL,EQ,0,'\0',NULL,$1,$3,NULL);	}
  | E NEQ E		{ typeCheckNodesEq($1,$3);    $$ = treeCreate(BOOL,NEQ,0,'\0',NULL,$1,$3,NULL);	}
  | E AND E 	{ typeCheckNodes($1,$3,BOOL); $$ = treeCreate(BOOL,AND,0,'\0',NULL,$1,$3,NULL); }
  | E OR E 		{ typeCheckNodes($1,$3,BOOL); $$ = treeCreate(BOOL,OR,0,'\0',NULL,$1,$3,NULL);  }
  | NOT E 		{ typeCheckNode($2,BOOL); 	  $$ = treeCreate(BOOL,NOT,0,'\0',NULL,$2,NULL,NULL);   }
  | '(' E ')' 	{ $$ = $1;}
  | NUM 		{ $$ = $1;}
  | TRUE		{ $$ = $1;}
  | FALSE		{ $$ = $1;}
  | VAR 		{ $$ = $1;}	 

%%


	#include "decl.c"
	#include "exptest.c"
	#include "label.c"
	#include "codegen.c"

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