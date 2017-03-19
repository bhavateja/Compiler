int reg_num = 0;
int label_counter = 0;

int allocate_register(){
    reg_num++;
    return reg_num;
}

void register_deallocate(){
    reg_num--;
    return;
}

void write_header(){
    fprintf(fp,"0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(fp,"MOV SP, %d\n",curr_stack-1);
    fprintf(fp,"MOV BP, %d\n",curr_stack);
    fprintf(fp,"PUSH R0\n");
    /*fprintf(fp,"CALL MAIN\nINT 10\n");*/
    return;
}

int code_gen(struct tnode* T){
    int idx;
    int reg1;
    int reg2;
    struct Gsymbol* GPtr;
    int start_label, end_label;
    if(T == NULL) return -1;
    if(T->TYPE == -1){
         // Evaluate ptr1 first, then go to ptr2
        code_gen(T->Ptr1);
        code_gen(T->Ptr2);
    }
    else{
        // Statement
        switch(T->NODETYPE){
            case PLUS:
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"ADD R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;
            
            case MINUS:
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"SUB R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;

           case MUL:
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"MUL R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;
           
           case DIV:
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"DIV R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;

           case LT:
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"LT R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;

           case GT:
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"GT R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;

           case EQ:
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"EQ R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;


           case LE:
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"LE R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;

           case GE:
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"GE R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;

           case NEQ:
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"NE R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;
        
            case CONST:
                reg1 = allocate_register();
                fprintf(fp,"MOV R%d, %d\n",reg1,T->VALUE);
                //printf("num %d\n",T->VALUE);
                return reg1;                

            case ID:
                reg1 = allocate_register(); 
                reg2 = get_stack_addr(T);
                fprintf(fp,"MOV R%d, [R%d]\n",reg1,reg2);
                register_deallocate();
                return reg1;

            case READ:
                reg1 = allocate_register();
                
                fprintf(fp,"MOV R%d, \"Read\"\n",reg1);
                fprintf(fp,"PUSH R%d\n",reg1);
                
                fprintf(fp,"MOV R%d, -1\n",reg1);
                fprintf(fp,"PUSH R%d\n",reg1);
                
                reg2 = get_stack_addr(T->Ptr1);
                fprintf(fp,"MOV R%d, R%d\n",reg1,reg2);
                fprintf(fp,"PUSH R%d\n",reg1);
                
                fprintf(fp,"PUSH R%d\n",reg1);
                fprintf(fp,"PUSH R%d\n",reg1);
                
                fprintf(fp,"CALL 0\n");
                fprintf(fp,"POP R%d\n",reg1);                
                fprintf(fp,"POP R%d\n",reg1);                
                fprintf(fp,"POP R%d\n",reg1);                
                fprintf(fp,"POP R%d\n",reg1);
                fprintf(fp,"POP R%d\n",reg1);
                register_deallocate();
                register_deallocate();
                return -1;

            case WRITE:
                reg1 = code_gen(T->Ptr1);

                fprintf(fp,"MOV [%d], R%d\n",1024,reg1);

                fprintf(fp,"MOV R%d, \"Write\"\n",reg1);
                fprintf(fp,"PUSH R%d\n",reg1);                   //FUNC CODE
                
                fprintf(fp,"MOV R%d, -2\n",reg1); 
                fprintf(fp,"PUSH R%d\n",reg1);                   //1st ARG
                fprintf(fp,"MOV R%d, 1024\n",reg1);
                fprintf(fp,"PUSH R%d\n",reg1);                   //2nd ARG ADDR of RESULT
                
                fprintf(fp,"PUSH R%d\n",reg1);                   // 3rd ARG
                fprintf(fp,"PUSH R%d\n",reg1);                   // RESULT
               
                fprintf(fp,"CALL 0\n");
                fprintf(fp,"POP R%d\n",reg1);                
                fprintf(fp,"POP R%d\n",reg1);                
                fprintf(fp,"POP R%d\n",reg1);                
                fprintf(fp,"POP R%d\n",reg1);
                fprintf(fp,"POP R%d\n",reg1);
                
 
                register_deallocate();
                return -1;    

            case IF:
                start_label = label_counter+1;
                end_label = label_counter+2;
                label_counter+=2;
                reg1 = code_gen(T->Ptr1);
                fprintf(fp,"JZ R%d, L%d\n",reg1,start_label);
                code_gen(T->Ptr2);
                fprintf(fp,"JMP L%d\n",end_label);
                ////ELSE PART
                fprintf(fp,"L%d:\n",start_label);
                code_gen(T->Ptr3);         
                fprintf(fp,"L%d:\n",end_label);   
                register_deallocate();
                return -1;

            case WHILE:
                start_label = label_counter+1;
                end_label = label_counter+2;
                label_counter+=2;
                fprintf(fp,"L%d:\n",start_label);
                reg1 = code_gen(T->Ptr1);
                fprintf(fp,"JZ R%d, L%d\n",reg1,end_label);
                code_gen(T->Ptr2);
                fprintf(fp,"JMP L%d\n",start_label);
                fprintf(fp,"L%d:\n",end_label);
                register_deallocate();
                return -1;

            case ASSGN:
                reg1 = code_gen(T->Ptr2);
                reg2 = get_stack_addr(T->Ptr1);
                fprintf(fp,"MOV [R%d], R%d\n",reg2,reg1);
                register_deallocate();
                register_deallocate();
                return -1;
        }

    }
}


int get_stack_addr(struct tnode* T){
    int reg1,reg2;
    reg1 = allocate_register();
    
    struct Lsymbol *Lentry;
    Lentry = Llookup(T->NAME);
    
    if(Lentry != NULL){
        fprintf(fp,"MOV R%d, BP\n",reg1);
        fprintf(fp,"ADD R%d, %d\n",reg1,Lentry->index);
        
        if(T->Ptr1 != NULL){
            reg2 = code_gen(T->Ptr1);
            fprintf(fp,"ADD R%d, R%d\n",reg1,reg2);
            register_deallocate();
        }
        return reg1;
    }

    struct Gsymbol *Gentry;
    Gentry = Glookup(T->NAME);
    

    fprintf(fp,"MOV R%d, %d\n",reg1,Gentry->stack_addr);
    
    if(T->Ptr1 != NULL){
        reg2 = code_gen(T->Ptr1);
        fprintf(fp,"ADD R%d, R%d\n",reg1,reg2);
        register_deallocate();
    }
    return reg1;
}

void generate_target(struct tnode* T){
    fp = fopen("intermediate.xsm","w+"); 
    write_header(); 
    code_gen(T); 
    fclose(fp);
    printf("Intermediate Code Generated\n");
    parse1();
    printf("Label Table Created\n");
    parse2();
    printf("Target Code Generated\n");
    exit(1);
}