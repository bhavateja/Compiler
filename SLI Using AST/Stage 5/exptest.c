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

    if((t->NODETYPE) == NUM){
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
                       return x/y;
            		   break;
        }
    }
}

void evaluate(struct tnode* T){
	int *addr;
	struct Gsymbol* entry;
	if(T == NULL) return;
	if(T->TYPE == -1){
		// Evaluate ptr1 first, then go to ptr2
		evaluate(T->Ptr1);
		evaluate(T->Ptr2);
	}
	else if(T->TYPE == 0){
		// Statement
		switch(T->NODETYPE){
			case READ: 
				addr =  get_Id_Addr(T->Ptr1);
				scanf("%d",addr);
				break;
			
			case WRITE:
				printf("%d\n",evaluateExpr(T->Ptr1));
				break;

			case ASSGN:
				// Assignment Statement 
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
	else{
		// Expression
		//////////////////////// Control Never Comes Here
	}
	
}