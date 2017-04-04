typedef struct tnode {

	struct Typetable *TYPE; 		// -1)SList  0) Stmnts
	int NODETYPE;
	char *NAME; 	// For Identifiers/Functions
	int VALUE; 		// for constants
	struct tnode *Args; // List of arguments for functions
	struct tnode *Ptr1, *Ptr2, *Ptr3;
	/* Maximum of three subtrees (3 required for IF THEN ELSE */

	struct Gsymbol *Gentry; // For global identifiers/functions
	struct Lsymbol *Lentry; // For Local variables
	struct tnode* NEXT;

}tnode;


//    MAKE an empty node
struct tnode* createEmptyNode();

/* Creating nodes for identified tokens */
struct tnode* treeCreate(struct Typetable *TYPE,int NODETYPE,int VALUE,char *NAME, struct tnode* ArgList,struct tnode* Ptr1,struct tnode* Ptr2, struct tnode* Ptr3);

void updateEntry(struct tnode* T);

void typeCheckNodes(struct tnode* LEFT, struct tnode* RIGHT, struct Typetable *TYPE);

void typeCheckNode(struct tnode* LEFT, struct Typetable *TYPE); 

void typeCheckNodesEq(struct tnode* LEFT, struct tnode* RIGHT);

void userDefNodeTypeCheck(struct tnode* T, char *NAME);

void userDefNodesTypeCheck(struct tnode* T1, struct tnode* T2);