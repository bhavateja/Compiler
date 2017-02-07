struct tnode* createEmptyNode() {
    struct tnode* temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->Ptr1 = temp->Ptr2 = temp->Ptr3 = NULL;
    temp->TYPE = -1;
    return temp;
}

struct tnode *treeCreate(int TYPE,int NODETYPE,int VALUE,char *NAME, struct tnode* ArgList,struct tnode* Ptr1,struct tnode* Ptr2, struct tnode* Ptr3){
	
	struct tnode* temp;
	temp = createEmptyNode();
	temp->TYPE = TYPE;
	temp->NODETYPE = NODETYPE;
	temp->VALUE = VALUE;
	temp->NAME = NAME;
	temp->ArgList = ArgList;
	temp->Ptr1 = Ptr1;
	temp->Ptr2 = Ptr2;
	temp->Ptr3 = Ptr3;
	return temp;
}

int* get_Id_Addr(struct tnode* T){
	int idx = 0;
	if(T->Ptr1 != NULL) idx = evaluateExpr(T->Ptr1);
	return (Glookup(T->NAME)->BINDING + idx);
}

int evaluateExpr(struct tnode* t){
    int x,y;

    if((t->NODETYPE) == CONST){
        return t->VALUE;
    }
    else if(t->NODETYPE == ID){ 
		return *get_Id_Addr(t);
    }
    else{
        switch((t->NODETYPE)){
			case EQ :
					   x = evaluateExpr(t->Ptr1);
					   y = evaluateExpr(t->Ptr2);
					   if(x == y) return 1;
					   else return 0;
					   break;

			case LT :
					   x = evaluateExpr(t->Ptr1);
					   y = evaluateExpr(t->Ptr2);
					   if(x<y) return 1;
					   else return 0;
					   break;

			case GT :
					   x = evaluateExpr(t->Ptr1);
					   y = evaluateExpr(t->Ptr2);
					   if(x>y) return 1;
					   else return 0;
					   break;	

			case NEQ :
					   x = evaluateExpr(t->Ptr1);
					   y = evaluateExpr(t->Ptr2);
					   if(x != y) return 1;
					   else return 0;
					   break;

			case LE :
					   x = evaluateExpr(t->Ptr1);
					   y = evaluateExpr(t->Ptr2);
					   if(x<=y) return 1;
					   else return 0;
					   break;

			case GE :
					   x = evaluateExpr(t->Ptr1);
					   y = evaluateExpr(t->Ptr2);
					   if(x>=y) return 1;
					   else return 0;
					   break;						   	   

            case PLUS : 
                       x = evaluateExpr(t->Ptr1);
                       y = evaluateExpr(t->Ptr2);
                       return x+y;
                       break;

            case MINUS : // printf("-");
                       x = evaluateExpr(t->Ptr1);
                       y = evaluateExpr(t->Ptr2);
                       return x-y;
                       break;
            case MUL : 
                         //printf("*");
                       x = evaluateExpr(t->Ptr1);
                       y = evaluateExpr(t->Ptr2);
                        return x*y;
                        break;
            case DIV : 
                         //printf("/");
                       x = evaluateExpr(t->Ptr1);
                       y = evaluateExpr(t->Ptr2);
                       if(y == 0){
                       	printf("Div by zero\n");
                       	exit(1);
                       }
                       return x/y;
            		   break;
            case MOD : 
                         //printf("/");
                       x = evaluateExpr(t->Ptr1);
                       y = evaluateExpr(t->Ptr2);
 
                       return x%y;
            		   break;

            case AND :		
                       x = evaluateExpr(t->Ptr1);
                       y = evaluateExpr(t->Ptr2);
                       return x && y;

            case OR :		
                       x = evaluateExpr(t->Ptr1);
                       y = evaluateExpr(t->Ptr2);
                       return x || y;

            case NOT :		
                       x = evaluateExpr(t->Ptr1);
                       return !x;


                      
        }
    }
}

void evaluate(struct tnode* T){
	int *addr;
	int val;
	struct Gsymbol* entry;
	if(T == NULL) return;
	if(T->TYPE == -1){
		// Evaluate ptr1 first, then go to ptr2
		evaluate(T->Ptr1);
		evaluate(T->Ptr2);
	}
	else{
		// Statement
		switch(T->NODETYPE){
			case READ: 
				addr =  get_Id_Addr(T->Ptr1);
				scanf("%d",addr);
				break;
			
			case WRITE:
				if(T->Ptr1->TYPE == BOOL){
					if(T->Ptr1->NODETYPE == CONST){
						if(T->Ptr1->VALUE == 0) printf("False\n");
						else printf("True\n");
					}
					else{
						val = evaluateExpr(T->Ptr1);
						if(val == 0) printf("False\n");
						else printf("True\n");
					}
				}
				else printf("%d\n",evaluateExpr(T->Ptr1));
				break;

			case ASSGN:
				// Assignment Statement 
				if(T->Ptr1->TYPE == BOOL){
					if(T->Ptr2->TYPE != BOOL){
						printf("TYPE ASSIGN ERROR\n");
						exit(1);
					}
				}
				*get_Id_Addr(T->Ptr1) = evaluateExpr(T->Ptr2);
				break;

			case IF:
				if(evaluateExpr(T->Ptr1)) evaluate(T->Ptr2);
				else evaluate(T->Ptr3);
				break;

			case WHILE :
				while(evaluateExpr(T->Ptr1)){
					evaluate(T->Ptr2);
				}	
				break;	
		}
	}
	
}

void updateEntry(struct tnode* T){
	struct Gsymbol *entry = NULL;
	entry = Glookup(T->NAME);
	if(entry == NULL){
		printf("Undeclared Variable %s\n",T->NAME);
		exit(1);
	}
	T->TYPE = entry->TYPE;
	T->Gentry = entry;
}

void typeCheckNodes(struct tnode* LEFT, struct tnode* RIGHT, int INT_BOOL){
	//printf("%d %d %d\n",LEFT->TYPE, RIGHT->TYPE, INT);
	if(LEFT->TYPE == RIGHT->TYPE && LEFT->TYPE == INT_BOOL) return;
	printf("TYPE ERROR LINE :: %d\n",1+line);
	exit(1);
}


void typeCheckNode(struct tnode* LEFT, int INT_BOOL){
	//printf("%d %d\n",LEFT->TYPE, INT_BOOL);
	if(LEFT->TYPE == INT_BOOL) return;
	printf("TYPE ERROR LINE :: %d\n",1+line);
	exit(1);
}

void typeCheckNodesEq(struct tnode* LEFT, struct tnode* RIGHT){
	if(LEFT->TYPE == RIGHT->TYPE) return;
	printf("TYPE ERROR LINE :: %d\n",1+line);
	exit(1);	
}