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
    newSymbol->BINDING = malloc(SIZE*sizeof(int));
    *newSymbol->BINDING = 0;
    newSymbol->NEXT = NULL;
    if(g_end == NULL){
        g_end = g_start = newSymbol;
    }
    else{
        g_end->NEXT = newSymbol;
        g_end = newSymbol;
    }
}