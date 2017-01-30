struct tnode* makeLeafNode(int n){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->flag = 0;
    temp->op = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->flag = 1;
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    return temp;
}


int evaluate(struct tnode *t){
    int x,y;
    if((t->op) == NULL){
        printf("%d ",t->val);
        return t->val;
    }
    else{
        switch(*(t->op)){
            case '+' : printf("+");
                       x = evaluate(t->left);
                       y = evaluate(t->right);

                       return x+y;
                       break;
            case '-' :  printf("-");
                       x = evaluate(t->left);
                       y = evaluate(t->right);
                       return x-y;
                       break;
            case '*' : 
                         printf("*");
                       x = evaluate(t->left);
                       y = evaluate(t->right);
                        return x*y;
                        break;
            case '/' : 
                         printf("/");
                       x = evaluate(t->left);
                       y = evaluate(t->right);
                       return x/y;
            break;
        }
    }
}


