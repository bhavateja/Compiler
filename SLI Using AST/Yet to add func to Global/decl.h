typedef struct Gsymbol {
	char *NAME; 
	int TYPE; 		// INT OR BOOLEAN
	int SIZE; 		// Size field for arrays
	int *BINDING; 	// Address of the Identifier in Memory
	int stack_addr;
	int Label;
	struct ArgList *Args; // Argument List for functions
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


typedef struct ArgList {
	int TYPE;
	char *NAME;
	struct ArgList *NEXT;
	struct tnode *Ptr1;
	int index;
}ArgList;

void ArgInstall(char *NAME, int TYPE);

struct ArgList* ArgLookup(char *NAME);

int assignIndex(struct ArgList *Args);

void clearArgList();

void funcArgAdd(struct tnode* T);
