typedef struct Gsymbol {
	char *NAME; 
	int TYPE; 		// INT OR BOOLEAN
	int SIZE; 		// Size field for arrays
	int *BINDING; 	// Address of the Identifier in Memory
	int stack_addr;
	//ArgStruct *ARGLIST; // Argument List for functions
	/***Argstruct must store the name and type of each argument ***/
	struct Lsymbol *localSymTable;
	struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */
}Gsymbol;

struct Gsymbol* Glookup(char *NAME); // Look up for a global identifier

void Ginstall (char *NAME, int TYPE, int SIZE); // Installation



typedef struct Lsymbol {
	char *NAME; 
	int TYPE; 
	int SIZE;
	int BINDING; 
	int index;
	struct Lsymbol *NEXT; 
}Lsymbol;

struct Lsymbol *Llookup(char *NAME);

void Linstall(char *NAME, int TYPE, int SIZE);

void clearLentry();

