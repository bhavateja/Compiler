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
    newSymbol->Args = NULL;
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

void ArgInstall(char *NAME, int TYPE){
    struct ArgList *newArg = malloc(sizeof(struct ArgList)); 
    newArg->NAME = NAME;
    newArg->TYPE = TYPE;
    newArg->NEXT = NULL;
    if(arg_start == NULL){
        arg_start = arg_end = newArg;
    }
    else{
        arg_end->NEXT = newArg;
        arg_end = newArg;
    }
}

int assignIndex(struct ArgList *Args){
    int x;
    if(Args == NULL) return -1;
    x = assignIndex(Args->NEXT);
    Args->index = x+1;
    return x+1;
}

struct ArgList* ArgLookup(char *NAME){
    struct ArgList *Use;
    Use = arg_start;
    while(Use!= NULL){
        if(strcmp(Use->NAME,NAME ) == 0) break;
        Use = Use->NEXT;
    }
    return Use;
}

void clearArgList(){
    arg_end = arg_start = NULL;
}

void funcArgAdd(struct tnode* T){
    if(funcArg_start==NULL){
        funcArg_end = funcArg_start = T;
        return;
    }
    funcArg_end->NEXT = T;
    funcArg_end = T;
}