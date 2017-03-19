%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	int idx = 0;
	int regs1 = 0;
	int regs2 = 0;
	FILE *fp = NULL; 

	int reg_num = 0;
	int label_counter = 0;

	FILE *target = NULL;
	#include "decl.h"
	#include "exptest.h"
	#include "label.h"
	#include "codegen.h"

	struct Lsymbol *l_start = NULL;
	struct Lsymbol *l_end = NULL;
	struct ArgList *arg_start = NULL;
	struct ArgList *arg_end = NULL;

	struct tnode *funcArg_start = NULL;
	struct tnode *funcArg_end = NULL;
	struct Gsymbol *gUse = NULL;

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

program : GDefBlock funcDefBlock mainBlock ENDOFFILE {}

funcDefBlock : funcDefBlock func
		| func

func : Type ID '(' ArgList ')' '{' LDefBlock Slist retStmt '}'  {
	
																struct Gsymbol* funcGentry = Glookup($2->NAME);
																funcGentry->localSymTable = l_start;																	
																funcGentry->Label = label_counter+1;
																
																printf("%d %d %d\n",$9->Ptr1->TYPE,INT,BOOL);

																assignIndex(arg_start);
																
																struct Gsymbol *checkG = NULL;
																struct ArgList *check1 = NULL;
																struct ArgList *check2 = NULL;
																check1 = arg_start;
																check2 = funcGentry->Args;

																while(check1!=NULL && check2!=NULL){
																	if(check1->TYPE != check2->TYPE){
																		printf("Check the type of Arguments :: %s\n",funcGentry->NAME);
																		exit(1);
																	}
																	if(strcmp(check1->NAME,check2->NAME)!=0){
																		printf("Change of Argument Names for %s\n",funcGentry->NAME);
																		exit(1);
																	}
																	checkG = Glookup(check1->NAME);
																	if((checkG!=NULL) && (checkG->isArray_func == 2)){
																		printf("Arg Name %s in %s is same as the name of function %s\n",check1->NAME,$2->NAME,checkG->NAME);
																		exit(1);
																	}
																	check1 = check1->NEXT;
																	check2 = check2->NEXT;
																}

																if(check1!=NULL || check2!=NULL){
																	printf("check the number of Arguments for %s\n",$2->NAME);
																	exit(1);
																}

																if($9->Ptr1->TYPE != $1->TYPE){
																	printf("Return Type Check for %s\n",$2->NAME);
																	exit(1);
																}


																funcGentry->Args = arg_start;

																//printf("%d, %d, %d\n",INT,funcGentry->TYPE,$1->TYPE);

																fprintf(fp,"L%d:\n",label_counter+1);
																label_counter ++;

																fprintf(fp,"PUSH BP\n");
																fprintf(fp,"MOV BP, SP\n");
																fprintf(fp,"ADD SP, %d\n",idx);

															 	code_gen($8); 

															 	regs1 = code_gen($9->Ptr1);

															 	regs2 = allocate_register();
															    
															    fprintf(fp,"SUB SP, %d\n",idx);

															    fprintf(fp,"MOV R%d, BP\n",regs2);
															    fprintf(fp,"SUB R%d, 2\n",regs2);
															    fprintf(fp,"MOV [R%d], R%d\n",regs2,regs1);
															    register_deallocate();
															    register_deallocate();

															    fprintf(fp,"POP BP\n");
															    fprintf(fp,"RET\n");

															    printf("Intermediate Code Generated\n");

																l_start = l_end = NULL;
																idx = 0;
																arg_start = arg_end = NULL;

															}

GDefBlock : DECL GDefList ENDDECL 					{ fp = fopen("intermediate.xsm","w+"); write_header(); }
		| DECL ENDDECL								{ fp = fopen("intermediate.xsm","w+"); write_header(); }

GDefList : GDefList GDecl
		| GDecl

GDecl : Type GIdList ';' 							{ updateGentriesTo($1->TYPE); }

GIdList : GIdList ',' GId 							{ 	}
		| GId 										{ 	}

GId : ID 											{ Ginstall($1->NAME,variable_type,1);					}
	| ID '[' NUM ']'								{ 
													  Ginstall($1->NAME,variable_type,$3->VALUE);	
													  struct Gsymbol *arrGentry = NULL;
													  arrGentry = Glookup($1->NAME);
													  arrGentry->isArray_func = 1;

													}

	| ID '(' ArgList ')' 							{

													  Ginstall($1->NAME,-3,0);
													  struct Gsymbol *funcGentry = NULL;
													  funcGentry = Glookup($1->NAME);
													  funcGentry->Args = arg_start;
													  funcGentry->isArray_func = 2;

													  arg_start = arg_end = NULL;		
													}

ArgList : ArgList ',' Arg 							
		| Arg

Arg : Type ID 										{ ArgInstall($2->NAME, variable_type); }

Type : INT 											{ $$ = treeCreate(INT,0,0,'\0',NULL,NULL,NULL,NULL); variable_type = INT; }
	| BOOL											{ $$ = treeCreate(BOOL,0,0,'\0',NULL,NULL,NULL,NULL); variable_type = BOOL;}


mainBlock : Type MAIN '(' ')' '{' LDefBlock Slist retStmt '}' 	    { 
																
																Ginstall("main",$1->TYPE,0);

																arg_start = arg_end = NULL;

																struct Gsymbol* mainGentry = Glookup("main");
																mainGentry->localSymTable = l_start;																	
																mainGentry->Label = 0;
																mainGentry->Args = arg_start;
																
																fprintf(fp,"L0:\n");

																fprintf(fp,"PUSH BP\n");
																fprintf(fp,"MOV BP, SP\n");
																fprintf(fp,"ADD SP, %d\n",idx);

															 	code_gen($7);

															    fprintf(fp,"SUB SP, %d\n",idx);
															    fprintf(fp,"POP BP\n");
															    fprintf(fp,"RET\n");

															    printf("Intermediate Code Generated\n");
															    fclose(fp);
														
															    parse1();
															    printf("Label Table Created\n");
															    parse2();
															    printf("Target Code Generated\n");

																l_start = l_end = NULL;
																idx = 0;
																arg_start = arg_end = NULL;

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
	 | WRITE '(' E ')' ';'							{ /*typeCheckNode($3,INT);*/	   $$ = treeCreate(0,WRITE,0,'\0',NULL,$3,NULL,NULL);}
	 | IF '(' E ')' THEN Slist ELSE Slist ENDIF ';' { typeCheckNode($3,BOOL); 	   $$ = treeCreate(0,IF,0,'\0',NULL,$3,$6,$8); } 
	 | WHILE '(' E ')' DO Slist ENDWHILE ';' 		{ typeCheckNode($3,BOOL); 	   $$ = treeCreate(0,WHILE,0,'\0',NULL,$3,$6,NULL);}
	 ;

VAR : ID 			{  updateEntry($1);  $$ = $1;}
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
  | ID '(' funCallArgs ')' 		{ 
  									gUse = Glookup($1->NAME);
  									if(gUse == NULL){
  										printf("Undeclared Function Call\n");
  										exit(1);
  									}
  									if(gUse->isArray_func != 2){
  										printf("%s is not declared as a function\n",$1->NAME);
  										exit(1);
  									}

  									struct tnode *checkT = funcArg_start;
  									struct ArgList *checkA = gUse->Args;

  									while(checkT != NULL && checkA!=NULL){
  										if(checkT->TYPE != checkA->TYPE){
  											printf("Mismatch of Types in function call %s\n",$1->NAME);
  											exit(1);
  										}
  										checkT = checkT->NEXT;
  										checkA = checkA->NEXT;
  									}

  									if(checkT!=NULL || checkA!=NULL){
  										printf("Check number of arguments in function call %s\n",$1->NAME);
  										exit(1);
  									}

  									$$ = treeCreate(gUse->TYPE,FUNC,0,$1->NAME,funcArg_start,NULL,NULL,NULL);
  									funcArg_start = funcArg_end = NULL;
  								}


funCallArgs : funCallArgs ',' E 	{ funcArgAdd($3);         }
			| E 					{ funcArgAdd($1);   	  }

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