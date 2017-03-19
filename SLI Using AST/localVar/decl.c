struct Gsymbol *g_start = NULL;
struct Gsymbol *g_end = NULL;



struct Gsymbol* Glookup(char *NAME){
    struct Gsymbol *iter = NULL;
    iter = g_start;
    while(iter != NULL){
        if(strcmp(iter->NAME, NAME)== 0) break;
        iter = iter->NEXT;
    }
    return iter;
}

int curr_stack = 4096;

void Ginstall (char *NAME, int TYPE, int SIZE){
    if(Glookup(NAME) != NULL){
        printf("Variable %s already exists\n",NAME);
        exit(1);
        return;
    }        
    struct Gsymbol *newSymbol = malloc(sizeof(struct Gsymbol));
    newSymbol->NAME = NAME;
    newSymbol->TYPE = TYPE;
    newSymbol->SIZE = SIZE;
    newSymbol->stack_addr = curr_stack;
    curr_stack += SIZE;
    newSymbol->NEXT = NULL;
    if(g_end == NULL){
        g_end = g_start = newSymbol;
    }
    else{
        g_end->NEXT = newSymbol;
        g_end = newSymbol;
    }
}

/////////////////////////////////////////////////CURRENT SYMBOL TABLE LOCAL DECLARED IN .y FILE

struct Lsymbol* Llookup(char *NAME){
    struct Lsymbol *iter = NULL;
    iter = l_start;
    while(iter != NULL){
        if(strcmp(iter->NAME, NAME)== 0) break;
        iter = iter->NEXT;
    }
    return iter;
}

void Linstall (char *NAME, int TYPE, int SIZE){
    if(Llookup(NAME) != NULL){
        printf("Variable %s already exists\n",NAME);
        exit(1);
        return;
    }        
    struct Lsymbol *newSymbol = malloc(sizeof(struct Lsymbol));
    newSymbol->NAME = NAME;
    newSymbol->TYPE = TYPE;
    newSymbol->SIZE = SIZE;
    newSymbol->NEXT = NULL;
    if(l_end == NULL){
        l_end = l_start = newSymbol;
        newSymbol->index = idx;
    }
    else{
        l_end->NEXT = newSymbol;
        newSymbol->index = idx;
        l_end = newSymbol;
    }
    idx+=SIZE;
}

void clearLentry(){
    l_end = l_start = NULL;
    idx = 0;
}


