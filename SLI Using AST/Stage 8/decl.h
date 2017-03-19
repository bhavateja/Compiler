typedef struct Gsymbol {
	char *NAME; 
	int TYPE; 		// INT OR BOOLEAN
	int SIZE; 		// Size field for arrays
	int *BINDING; 	// Address of the Identifier in Memory
	int stack_addr;
	//ArgStruct *ARGLIST; // Argument List for functions
	/***Argstruct must store the name and type of each argument ***/
	struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */
}Gsymbol;

struct Gsymbol* Glookup(char *NAME); // Look up for a global identifier

void Ginstall (char *NAME, int TYPE, int SIZE); // Installation

//int typeValidity(struct Gsymbol* Left, struct tnode* Right); // Type Check Left and Right

/*
struct Lsymbol {
	char *NAME; 
	int TYPE; 
	int BINDING; 
	struct Lsymbol *NEXT; 
}

struct Lsymbol *Llookup(char *NAME);

void Linstall(char *NAME, int TYPE);
*/