struct tnode* createEmptyNode() {
    struct tnode* temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->Ptr1 = temp->Ptr2 = temp->Ptr3 = NULL;
    temp->TYPE = NULL;
    return temp;
}

struct tnode *treeCreate(struct Typetable *TYPE,int NODETYPE,int VALUE,char *NAME, struct tnode* Args,struct tnode* Ptr1,struct tnode* Ptr2, struct tnode* Ptr3){
	
	struct tnode* temp;
	temp = createEmptyNode();
	temp->TYPE = TYPE;
	temp->NODETYPE = NODETYPE;
	temp->VALUE = VALUE;
	temp->NAME = NAME;
	temp->Args = Args;
	temp->Ptr1 = Ptr1;
	temp->Ptr2 = Ptr2;
	temp->Ptr3 = Ptr3;
	temp->NEXT = NULL;
	return temp;
}

void updateEntry(struct tnode* T){
	struct Gsymbol *entry = NULL;
	struct Lsymbol *temp = NULL;
	struct ArgList *temp1 = NULL;
	temp1 = ArgLookup(T->NAME);
	if(temp1 == NULL){
		temp = Llookup(T->NAME);
		if(temp == NULL){
			entry = Glookup(T->NAME);
			if(entry == NULL){
				printf("Undeclared Variable %s\n",T->NAME);
				exit(1);
			}
			else{
				T->TYPE = entry->TYPE;
				T->Gentry = entry;
			}
		}
		else{
			T->TYPE = temp->TYPE;
			T->Lentry = temp;
		}
	}
	else{
		T->TYPE = temp1->TYPE;
	}
}

void typeCheckNodes(struct tnode* LEFT, struct tnode* RIGHT, struct Typetable *TYPE){
	//printf("%d %d %d\n",LEFT->TYPE, RIGHT->TYPE, INT);
	if(strcmp(LEFT->TYPE->NAME,RIGHT->TYPE->NAME)==0 && strcmp(LEFT->TYPE->NAME,TYPE->NAME)==0) return;
	printf("TYPE ERROR LINE :: %d\n",1+line);
	exit(1);
}


void typeCheckNode(struct tnode* LEFT, struct Typetable *TYPE){
	//printf("%d %d\n",LEFT->TYPE, INT_BOOL);
	if(strcmp(LEFT->TYPE->NAME,TYPE->NAME)==0) return;
	printf("TYPE ERROR LINE :: %d\n",1+line);
	exit(1);
}

void typeCheckNodesEq(struct tnode* LEFT, struct tnode* RIGHT){
	if(strcmp(LEFT->TYPE->NAME,RIGHT->TYPE->NAME)==0) return;
	printf("TYPE ERROR LINE :: %d\n",1+line);
	exit(1);	
}


void userDefNodeTypeCheck(struct tnode* T, char *NAME){
	if(strcmp(T->TYPE->NAME,NAME) == 0) return;
	else{
		printf("Type Error\n");
		exit(1);
	}
}


void userDefNodesTypeCheck(struct tnode* T1, struct tnode* T2){
	if(T2->TYPE == NULL) return;
	if(strcmp(T1->TYPE->NAME,T2->TYPE->NAME) == 0) return;
	else{
		printf("Type Error\n");
		exit(1);
	}

}