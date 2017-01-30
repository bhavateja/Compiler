typedef struct tnode{

	int STMT;								//// -1. NOT a statement  1. Statement  2. Expression
	int TYPE;								//// 1. Constant; 2. Identifier; 3. Operators 4. Read,Write
	int NODETYPE;							//// 1. INTEGER;  2. Character
	int io;									//// -1 NOTHING;  1. Read;  2.Write;
	char IDENTIFIER;
	char OPERATOR;
	int VALUE;
	struct tnode *ArgList;
	struct tnode *ptr1, *ptr2, *ptr3;
	//Gsymbol *Gentry;
	//Lsymbol *Lentry;
}tnode;

//    MAKE an empty node
struct tnode* createNode();

/* Creating nodes for identified tokens */
struct tnode* tokenNode(int TYPE, int NUM, char ch);

// Evaluate the Tree
void evaluate(struct tnode* T);

// Evaluating Expressions
int evaluateExpr(struct tnode* T);
