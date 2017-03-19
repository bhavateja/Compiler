#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Gsymbol {
	char *NAME; 
	int TYPE; 		// INT OR BOOLEAN
	int SIZE; 		// Size field for arrays
	int *BINDING; 	// Address of the Identifier in Memory
	//ArgStruct *ARGLIST; // Argument List for functions
	/***Argstruct must store the name and type of each argument ***/
	struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */
}Gsymbol;

struct Gsymbol* Glookup(char *NAME); // Look up for a global identifier

void Ginstall (char *NAME, int TYPE, int SIZE); // Installation


struct Gsymbol *g_start = NULL;
struct Gsymbol *g_end = NULL;

struct Gsymbol* Glookup(char *NAME){
    printf("1\n");
    struct Gsymbol *iter = NULL;
    iter = g_start;
    while(iter != NULL){
        if(strcmp(iter->NAME, NAME)== 0) break;
        iter = iter->NEXT;
    }
    printf("2\n");
    return iter;
}

void Ginstall (char *NAME, int TYPE, int SIZE){
    if(Glookup(NAME) != NULL){
        printf("Variable %s already exists\n",NAME);
        exit(1);
        return;
    }        
    struct Gsymbol *newSymbol = malloc(sizeof(struct Gsymbol));
    newSymbol->NAME = NAME;
    newSymbol->TYPE = TYPE;
    newSymbol->SIZE = SIZE;
    newSymbol->BINDING = malloc(SIZE*sizeof(int));
    newSymbol->NEXT = NULL;
    if(g_end == NULL){
        g_end = g_start = newSymbol;
    }
    else{
        g_end->NEXT = newSymbol;
        g_end = newSymbol;
    }
    /*if(Glookup(NAME) != NULL){
        printf("Variable %s installed\n",NAME);
    }*/
}

int main(){
    char* NAME;
    scanf("%s",NAME);
    Ginstall(NAME, 1, 1);
    scanf("%s",NAME);
    Ginstall(NAME, 1, 1);
    scanf("%s",NAME);
    Ginstall(NAME, 1, 1);
}