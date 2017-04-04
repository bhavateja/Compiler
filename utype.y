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

	#include "typetables.h"
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
	struct tnode *tUse_Iter = NULL;
	struct Gsymbol *gUse = NULL;
	struct Lsymbol *lUse = NULL;
	struct ArgList *argUse = NULL;

	char *currDataType = NULL;
	struct Fieldlist *curr_FieldList = NULL;
	struct Typetable *variable_type;

	int yylex(void);
	extern FILE *yyin;
	extern int line;
	#define YYSTYPE tnode *
%}


%token INIT TYPEI ENDTYPEI FREE ALLOC EXIT FIELD NULL_NODE BEGINNING END FUNC RETURN MOD AND OR NOT CONST TRUE FALSE INT BOOL DECL ENDDECL ENDOFFILE MAIN READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE NUM ID PLUS MINUS MUL DIV ASSGN LT LE GT GE EQ NEQ

%left AND OR 
%left PLUS MINUS
%left MUL DIV MOD
%nonassoc LT GT LE GE EQ NEQ NOT

%%

program : Init TypeDefBlock GDefBlock funcDefBlock mainBlock ENDOFFILE {}
		| Init TypeDefBlock GDefBlock mainBlock ENDOFFILE {}

Init : {
	TypeTableCreate();	
};

TypeDefBlock : TYPEI TypeDefList ENDTYPEI            { printf("Type Definitions\n"); }
			|
			;

TypeDefList : TypeDefList TypeDef
			| TypeDef
			;

TypeDef : dataTypeName '{' FieldDeclList '}'         { 
												
												//printf("NEW TYPE %s::\n",currDataType);

												Tinstall(currDataType,curr_FieldList);
												struct Fieldlist *temp_FieldIter = temp_current_flist;
												struct Typetable *curr_Tentry = Tlookup(currDataType);

												int fieldIndex = 1;
												while(temp_FieldIter != NULL){
													if(temp_FieldIter ->TYPE == NULL){
														temp_FieldIter ->TYPE = curr_Tentry;
													}
													temp_FieldIter -> fieldIndex = fieldIndex;
													fieldIndex ++;
													//printf("%s - type %s, ",temp_FieldIter->NAME,temp_FieldIter->TYPE->NAME);
													temp_FieldIter = temp_FieldIter->NEXT;
												}
												//printf("\n");
												curr_FieldList = temp_current_flist = NULL;
												free(currDataType);
												currDataType = NULL;

										   }
		;

dataTypeName : ID {
		currDataType = malloc(sizeof(char)*20);
		strcpy(currDataType, $1->NAME);
};

FieldDeclList : FieldDeclList FieldDecl
			| FieldDecl
			;

FieldDecl : TypeName ID ';' {
	
	struct Typetable *t_entry = Tlookup($1->NAME);

	if($1->TYPE == NULL && strcmp($1->NAME, currDataType)!=0){
		printf("Undefined data type\n");
		exit(1);
	}
	curr_FieldList = Finstall($2->NAME);
	curr_FieldList -> TYPE = t_entry;

}
			;

TypeName : INT 			{$$ = treeCreate(VAR_TYPE_INT,0,0,"integer",NULL,NULL,NULL,NULL); variable_type = VAR_TYPE_INT;   }
		| BOOL 			{$$ = treeCreate(VAR_TYPE_BOOL,0,0,"boolean",NULL,NULL,NULL,NULL); variable_type = VAR_TYPE_BOOL; }
		| ID            {
							variable_type = Tlookup($1->NAME);
							$$ = treeCreate(variable_type,0,0,$1->NAME,NULL,NULL,NULL,NULL);
						}
		;


GDefBlock : DECL GDefList ENDDECL 					{  fp = fopen("intermediate.xsm","w+"); 	write_header(); }
		|              								{  fp = fopen("intermediate.xsm","w+"); 	write_header(); }
		;

GDefList : GDefList GDecl
		| GDecl

GDecl : TypeName GIdList ';' 						{ printf("%s Global\n",$1->TYPE->NAME); updateGentriesTo($1->TYPE);  }

GIdList : GIdList ',' GId 							{ 	}
		| GId 										{ 	}

GId : ID 											{ printf("%s %s\n",variable_type->NAME,$1->NAME); Ginstall($1->NAME,variable_type,1);					}
	| ID '[' NUM ']'								{ 

													  if(variable_type!=VAR_TYPE_INT && variable_type!=VAR_TYPE_BOOL){
													  	printf("Arrays of User defined types are not allowed\n");
													  	exit(1);
													  }
													  printf("%s %s\n",variable_type->NAME,$1->NAME);
													  Ginstall($1->NAME,variable_type,$3->VALUE);	
													  struct Gsymbol *arrGentry = NULL;
													  arrGentry = Glookup($1->NAME);
													  arrGentry->isArray_func = 1;
	
													}

	| ID '(' ArgList ')' 							{

													  Ginstall($1->NAME,NULL,0);
													  struct Gsymbol *funcGentry = NULL;
													  funcGentry = Glookup($1->NAME);

													  funcGentry->Args = arg_start;
													  funcGentry->isArray_func = 2;

													  arg_start = arg_end = NULL;	
													}

ArgList : ArgList ',' Arg 							
		| Arg

Arg : TypeName ID 										{ ArgInstall($2->NAME, variable_type); }


funcDefBlock : funcDefBlock func  
		| func                   

func : TypeName ID '(' ArgList ')' '{' LDefBlock BEGINNING Slist retStmt END '}'  {
																
																printf("Here\n");
																struct Gsymbol* funcGentry = Glookup($2->NAME);

																printf("%s for %s\n",funcGentry->TYPE->NAME,$2->NAME);

																if(strcmp(funcGentry->TYPE->NAME,$1->TYPE->NAME)!=0){
																	printf("FUNCTION Return Type Error\n");
																	exit(1);
																}

																funcGentry->localSymTable = l_start;																	
																funcGentry->Label = label_counter+1;
																
																//printf("%d %d %d\n",$9->Ptr1->TYPE,INT,BOOL);

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

																printf("args correct\n");

																if($10->Ptr1->TYPE != $1->TYPE){
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

																printf("Before Codegen\n");
															 	code_gen($9); 
																printf("After Codegen\n");

															 	regs1 = code_gen($10->Ptr1);

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

																printf("FUNC Decl done\n");

															}

mainBlock : INT MAIN '(' ')' '{' LDefBlock BEGINNING Slist retStmt END '}' 	    { 
																
																
																Ginstall("main",VAR_TYPE_INT,0);

																arg_start = arg_end = NULL;

																struct Gsymbol* mainGentry = Glookup("main");
																mainGentry->localSymTable = l_start;																	
																mainGentry->Label = 0;
																mainGentry->Args = arg_start;
																
																
																fprintf(fp,"L0:\n");

																fprintf(fp,"PUSH BP\n");
																fprintf(fp,"MOV BP, SP\n");
																fprintf(fp,"ADD SP, %d\n",idx);

															 	code_gen($8);

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

retStmt : RETURN E ';'				{$$ = treeCreate(NULL,RETURN,0,'\0',NULL,$2,NULL,NULL);}

LDefBlock : DECL LDefList ENDDECL 	{printf("Local DEcls done\n");}
		|               			{printf("Local DEcls done\n");}

LDefList :  LDefList LDecl
		| LDecl

LDecl : TypeName LIdList ';'

LIdList : LIdList ',' LId
		| LId
		;

LId : ID 											{ Linstall($1->NAME,variable_type,1); 			}
	| ID '[' NUM ']'								{ 

													  if(variable_type!=VAR_TYPE_INT && variable_type!=VAR_TYPE_BOOL){
													  	printf("Arrays of User defined types are not allowed\n");
													  	exit(1);
													  }
													  Linstall($1->NAME,variable_type,$3->VALUE);	

													}
	;

Slist : Stmt Slist { $$ = treeCreate(NULL,-1,0,'\0',NULL,$1,$2,NULL); }
	  | Stmt { $$ = $1; }
	  ;

Stmt : EXIT '(' ')' ';'                             {   $$ = treeCreate(NULL,EXIT,0,'\0',NULL,NULL,NULL,NULL);   }
	 | VAR ASSGN E ';' 								{   userDefNodesTypeCheck($1,$3); $$ = treeCreate(NULL,ASSGN,0,'\0',NULL,$1,$3,NULL);  }
	 | Field ASSGN E ';'                            {   userDefNodesTypeCheck($1,$3); $$ = treeCreate(NULL,ASSGN,0,'\0',NULL,$1,$3,NULL);  }
	 | VAR ASSGN INIT '(' ')' ';'                   {   $$ = treeCreate(NULL,ASSGN,0,'\0',NULL,$1,$3,NULL);  }
	 | Field ASSGN ALLOC '(' ')' ';'                { 	$$ = treeCreate(NULL,ASSGN,0,'\0',NULL,$1,$3,NULL);  }
	 | VAR ASSGN ALLOC '(' ')' ';'                  { 	$$ = treeCreate(NULL,ASSGN,0,'\0',NULL,$1,$3,NULL);  }
	 | FREE '(' ID ')' ';'                          { 	$$ = treeCreate(NULL,FREE,0,'\0',NULL,$3,NULL,NULL); }  
	 | FREE '(' Field ')' ';'                       { 	$$ = treeCreate(NULL,FREE,0,'\0',NULL,$3,NULL,NULL); }  
	 | READ '(' VAR ')' ';' 						{ 	$$ = treeCreate(NULL,READ,0,'\0',NULL,$3,NULL,NULL); }
	 | READ '(' Field ')' ';'                       { 	$$ = treeCreate(NULL,READ,0,'\0',NULL,$3,NULL,NULL); }  
	 | WRITE '(' E ')' ';'							{   $$ = treeCreate(NULL,WRITE,0,'\0',NULL,$3,NULL,NULL);}
	 | IF '(' E ')' THEN Slist ELSE Slist ENDIF ';' {  	printf("IF\n"); $$ = treeCreate(NULL,IF,0,'\0',NULL,$3,$6,$8);       } 
	 | IF '(' E ')' THEN Slist ENDIF ';'            { 	printf("IF\n"); $$ = treeCreate(NULL,IF,0,'\0',NULL,$3,$6,NULL);     } 
	 | WHILE '(' E ')' DO Slist ENDWHILE ';' 		{   $$ = treeCreate(NULL,WHILE,0,'\0',NULL,$3,$6,NULL);  }
	 ;

Field : ID '.' ID       { 	
							argUse = ArgLookup($1->NAME);
							gUse = Glookup($1->NAME);
							lUse = Llookup($1->NAME);

							if(argUse!=NULL) {
								curr_FieldList = FLookup(argUse->TYPE,$3->NAME);
								$1->TYPE = argUse->TYPE;
							}
							else if(lUse!=NULL) {
								curr_FieldList = FLookup(lUse->TYPE,$3->NAME);
								$1->TYPE = lUse->TYPE;
							}
							else if(gUse!=NULL) {
								curr_FieldList = FLookup(gUse->TYPE,$3->NAME);
								$1->TYPE = gUse->TYPE;
							}
							else{
								printf("Undeclared Variable %s\n",$1->NAME);
								exit(1);
							}

							if(curr_FieldList == NULL){
								printf("%s field error\n",$3->NAME);
								exit(1);
							}

							$$ = treeCreate(curr_FieldList->TYPE, FIELD, 0, '\0', NULL, $1, $3, NULL);

						}

	  | Field '.' ID    {
	                        curr_FieldList = FLookup($1->TYPE,$3->NAME);
							$$ = treeCreate(curr_FieldList->TYPE, FIELD, 0, '\0', NULL, $1, $3, NULL);
	  					}

	  ;

VAR  : ID 			    { updateEntry($1);  $$ = $1;}
     | ID '[' E ']'     { typeCheckNode($3,VAR_TYPE_INT); updateEntry($1); $1->Ptr1 = $3; $$ = $1;}

E : E PLUS E 	{ typeCheckNodes($1,$3,VAR_TYPE_INT);  $$ = treeCreate(VAR_TYPE_INT,PLUS,0,'\0',NULL,$1,$3,NULL);    	}
  | E MUL E 	{ typeCheckNodes($1,$3,VAR_TYPE_INT);  $$ = treeCreate(VAR_TYPE_INT,MUL,0,'\0',NULL,$1,$3,NULL); 		}
  | E MINUS E   { typeCheckNodes($1,$3,VAR_TYPE_INT);  $$ = treeCreate(VAR_TYPE_INT,MINUS,0,'\0',NULL,$1,$3,NULL);   	}
  | E DIV E 	{ typeCheckNodes($1,$3,VAR_TYPE_INT);  $$ = treeCreate(VAR_TYPE_INT,DIV,0,'\0',NULL,$1,$3,NULL);     	}
  | E MOD E 	{ typeCheckNodes($1,$3,VAR_TYPE_INT);  $$ = treeCreate(VAR_TYPE_INT,MOD,0,'\0',NULL,$1,$3,NULL);     	}
  |	E LT E		{ typeCheckNodes($1,$3,VAR_TYPE_INT);  $$ = treeCreate(VAR_TYPE_BOOL,LT,0,'\0',NULL,$1,$3,NULL);		}
  | E GT E		{ typeCheckNodes($1,$3,VAR_TYPE_INT);  $$ = treeCreate(VAR_TYPE_BOOL,GT,0,'\0',NULL,$1,$3,NULL);		}
  |	E LE E		{ typeCheckNodes($1,$3,VAR_TYPE_INT);  $$ = treeCreate(VAR_TYPE_BOOL,LE,0,'\0',NULL,$1,$3,NULL);		}
  | E GE E		{ typeCheckNodes($1,$3,VAR_TYPE_INT);  $$ = treeCreate(VAR_TYPE_BOOL,GE,0,'\0',NULL,$1,$3,NULL);		}
  | E EQ E		{ /*typeCheckNodesEq($1,$3);*/             $$ = treeCreate(VAR_TYPE_BOOL,EQ,0,'\0',NULL,$1,$3,NULL);		}
  | E NEQ E		{ /*typeCheckNodesEq($1,$3);  */           $$ = treeCreate(VAR_TYPE_BOOL,NEQ,0,'\0',NULL,$1,$3,NULL);		}
  | E AND E 	{ /*typeCheckNodes($1,$3,VAR_TYPE_BOOL);*/ $$ = treeCreate(VAR_TYPE_BOOL,AND,0,'\0',NULL,$1,$3,NULL); 		}
  | E OR E 		{ /*typeCheckNodes($1,$3,VAR_TYPE_BOOL);*/ $$ = treeCreate(VAR_TYPE_BOOL,OR,0,'\0',NULL,$1,$3,NULL);  		}
  | NOT E 		{ /*typeCheckNode($2,VAR_TYPE_BOOL); */	   $$ = treeCreate(VAR_TYPE_BOOL,NOT,0,'\0',NULL,$2,NULL,NULL);  	}
  | '(' E ')' 	{ $$ = $1;}
  | NUM 		{ $$ = $1; $$->TYPE = VAR_TYPE_INT;  }
  | TRUE		{ $$ = $1; $$->TYPE = VAR_TYPE_BOOL; }
  | FALSE		{ $$ = $1; $$->TYPE = VAR_TYPE_BOOL; }
  | VAR 		{ $$ = $1; }
  | Field       { $$ = $1; }
  | NULL_NODE   { $$ = $1; }
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
  										if(strcmp(checkT->TYPE->NAME, checkA->TYPE->NAME)!=0){
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

  									printf("Here2\n");
  								}


funCallArgs : funCallArgs ',' E 	{ funcArgAdd($3);         }
			| E 					{ funcArgAdd($1);   	  }

%%


	#include "decl.c"
	#include "exptest.c"
	#include "label.c"
	#include "codegen.c"
	#include "typetables.c"

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