
struct tnode* createNode() {
    struct tnode* temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->ptr1 = temp->ptr2 = NULL;
    temp->TYPE = -1;
    return temp;
}

struct tnode* tokenNode(int TYPE, int NUM, char ch){
	struct tnode* temp;
	temp = createNode();
	if(TYPE == 1){
		// CONSTANT
		temp->TYPE = 1;
		temp->NODETYPE = 1;
		temp->VALUE = NUM;
	}
	else if(TYPE == 2){
		// IDENTIFIER
		temp->TYPE = 2;
		temp->NODETYPE = 1;
		temp->IDENTIFIER = ch;
	}
	else if(TYPE == 3){
		// OPERATOR
		temp->TYPE = 3;
		temp->OPERATOR = ch;
	}
	else{
		// IO Operations
		temp->TYPE = 4;
		temp->io = NUM;			// 1. READ;  2. WRITE
	}
	return temp;
}


int evaluateExpr(struct tnode* t){
    int x,y;

    if((t->TYPE) == 1){
        return t->VALUE;
    }
    else if(t->TYPE == 2){
    	//printf("%d ",vars[(t->IDENTIFIER) -'a'+1]);
    	return vars[(t->IDENTIFIER) -'a'];
    }
    else{
        switch((t->OPERATOR)){
            case '+' : 
                       x = evaluateExpr(t->ptr1);
                       y = evaluateExpr(t->ptr2);

                       return x+y;
                       break;
            case '-' : // printf("-");
                       x = evaluateExpr(t->ptr1);
                       y = evaluateExpr(t->ptr2);
                       return x-y;
                       break;
            case '*' : 
                         //printf("*");
                       x = evaluateExpr(t->ptr1);
                       y = evaluateExpr(t->ptr2);
                        return x*y;
                        break;
            case '/' : 
                         //printf("/");
                       x = evaluateExpr(t->ptr1);
                       y = evaluateExpr(t->ptr2);
                       return x/y;
            		   break;
        }
    }

}


void evaluate(struct tnode* T){
	if(T == NULL) return;
	if(T->STMT == -1){
		// Evaluate ptr1 first, then go to ptr2
		evaluate(T->ptr1);
		evaluate(T->ptr2);
	}
	else if(T->STMT == 1){
		// Statement
		if(T->TYPE == 4){
			// Read or Write Stmts

			if(T->io == 1){
				scanf("%d",& vars[(T->ptr1)->IDENTIFIER -'a']);
				//printf("%d\n",vars[(T->IDENTIFIER) - 'a' +1]);
			}
			else{
				printf("%d\n",evaluateExpr(T->ptr1));
			}
		}
		else{
			// Assignment Statement
			vars[(T->ptr1)->IDENTIFIER -'a'] = evaluateExpr(T->ptr2);
		}

	}
	else{
		// Expression
		//////////////////////// Control Never Comes Here
	}
}