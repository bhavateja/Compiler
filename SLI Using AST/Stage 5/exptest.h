typedef struct tnode {

	int TYPE; 		// -1)SList  0) Stmnts
	int NODETYPE;
	char *NAME; 	// For Identifiers/Functions
	int VALUE; 		// for constants
	struct tnode *ArgList; // List of arguments for functions
	struct tnode *Ptr1, *Ptr2, *Ptr3;
	/* Maximum of three subtrees (3 required for IF THEN ELSE */

	struct Gsymbol *Gentry; // For global identifiers/functions
	//struct Lsymbol *Lentry; // For Local variables

}tnode;


//    MAKE an empty node
struct tnode* createEmptyNode();

/* Creating nodes for identified tokens */
struct tnode *treeCreate(int TYPE,int NODETYPE,int VALUE,char *NAME, struct tnode* ArgList,struct tnode* Ptr1,struct tnode* Ptr2, struct tnode* Ptr3);

// Evaluate the Tree
void evaluate(struct tnode* T);

// Evaluating Expressions
int evaluateExpr(struct tnode* T);
