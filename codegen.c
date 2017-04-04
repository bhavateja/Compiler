int allocate_register(){
    reg_num++;
    return reg_num-1;
}

void register_deallocate(){
    reg_num--;
    return;
}

void write_header(){
    fprintf(fp,"0\n2056\n0\n0\n1024\n0\n0\n0\n");
    fprintf(fp,"BRKP\n");
    
    fprintf(fp,"MOV SP, %d\n",curr_stack-1);
    fprintf(fp,"MOV BP, %d\n",curr_stack);
    fprintf(fp,"PUSH R0\n");
    fprintf(fp,"CALL L0\nINT 10\n");
    return;
}


int get_stack_addr(struct tnode* T){
    int reg1,reg2;
    struct ArgList *argEntry = NULL;
    struct Lsymbol *Lentry;
    struct Gsymbol *Gentry;
    struct Fieldlist *flist = NULL;

    switch(T->NODETYPE){
        
        case ID:
            
            printf("ID Stack addr\n");
            reg1 = allocate_register();
            
            argEntry = ArgLookup(T->NAME);
            if(argEntry != NULL){

                fprintf(fp,"MOV R%d, BP\n",reg1);
                fprintf(fp, "SUB R%d, %d\n",reg1,3+ argEntry->index);

                return reg1;
            }

            Lentry = Llookup(T->NAME);
            
            if(Lentry != NULL){
                fprintf(fp,"MOV R%d, BP\n",reg1);
                fprintf(fp,"ADD R%d, %d\n",reg1,1+Lentry->index);
                
                if(T->Ptr1 != NULL){
                    reg2 = code_gen(T->Ptr1);
                    fprintf(fp,"ADD R%d, R%d\n",reg1,reg2);
                    register_deallocate();
                }
                return reg1;
            }

            Gentry = Glookup(T->NAME);
            

            fprintf(fp,"MOV R%d, %d\n",reg1,Gentry->stack_addr);
            
            if(T->Ptr1 != NULL){
                reg2 = code_gen(T->Ptr1);
                fprintf(fp,"ADD R%d, R%d\n",reg1,reg2);
                register_deallocate();
            }
            return reg1;
            break;

        case FIELD:
            printf("Field, Stack addr\n");

            reg1 = get_stack_addr(T->Ptr1);

         //   if(T->Ptr1->TYPE == NULL) printf("Ptr1 TYPE NULL\n");

            flist = T->Ptr1->TYPE->fields;

            while(flist!=NULL){
                if(strcmp(flist->NAME,T->Ptr2->NAME)==0){
                    break;
                }
                flist = flist->NEXT;
            }
            
            reg2 = allocate_register();
            fprintf(fp,"MOV R%d, [R%d]\n",reg1,reg1);
            fprintf(fp,"MOV R%d, %d\n",reg2,flist->fieldIndex);
            fprintf(fp,"ADD R%d, R%d\n",reg1,reg2);
            register_deallocate();
            
            return reg1;
            break;
    }
}

int code_gen(struct tnode* T){
    int idx;
    int reg1;
    int reg2;
    int temp;
    int i;
    struct Gsymbol* GPtr;
    struct ArgList *List;
    struct tnode* tUse;
    int start_label, end_label;
    if(T == NULL) return -1;
    if(T->NODETYPE == -1){
         // Evaluate ptr1 first, then go to ptr2
        code_gen(T->Ptr1);
        code_gen(T->Ptr2);
    }
    else{
        // Statement
        switch(T->NODETYPE){

            case INIT:
                printf("INIT::\n");
                reg2 = allocate_register();

                temp = 4;
                i=0;
                while(i<temp){
                    fprintf(fp,"PUSH R%d\n",i);
                    i++;
                }
                
                fprintf(fp,"MOV R%d, \"Heapset\"\n",reg2);
                fprintf(fp,"PUSH R%d\n",reg2);
                
                fprintf(fp,"PUSH R0\n");
                fprintf(fp,"PUSH R0\n");
                fprintf(fp,"PUSH R0\n");
                fprintf(fp,"PUSH R0\n");
                fprintf(fp,"CALL 0\n");
                
//                fprintf(fp,"MOV R%d, [SP]\n",reg2);

                fprintf(fp,"SUB SP, 5\n");

                
                i = 3;
                while(i>=0){
                    fprintf(fp, "POP R%d\n", i);
                    i--;
                }
                fprintf(fp,"MOV R%d, SP\n",reg2);
                fprintf(fp,"ADD R%d, 9\n",reg2);  
                fprintf(fp,"MOV R%d, [R%d]\n",reg2,reg2);
                fprintf(fp,"BRKP\n");
              
                return reg2;
                break;

            case ALLOC:
                printf("ALLOC::\n");
                reg2 = allocate_register();
                
                temp = 4;
                i=0;
                while(i<temp){
                    fprintf(fp,"PUSH R%d\n",i);
                    i++;
                }

                fprintf(fp,"MOV R%d, \"Alloc\"\n",reg2);
                fprintf(fp,"PUSH R%d\n",reg2);
                
                fprintf(fp,"PUSH R0\n");
                fprintf(fp,"PUSH R0\n");
                fprintf(fp,"PUSH R0\n");
                fprintf(fp,"PUSH R0\n");
            
                fprintf(fp,"BRKP\n");
                fprintf(fp,"CALL 0\n");
                
                fprintf(fp,"BRKP\n");
                //fprintf(fp,"MOV R%d, [SP]\n",reg2);

                fprintf(fp,"SUB SP, 5\n");

                i = 3;
                while(i>=0){
                    fprintf(fp, "POP R%d\n", i);
                    i--;
                }
                
                fprintf(fp,"MOV R%d, SP\n",reg2);
                fprintf(fp,"ADD R%d, 9\n",reg2);  
                fprintf(fp,"MOV R%d, [R%d]\n",reg2,reg2);
                //fprintf(fp,"ADD R%d, 1024\n",reg2);
                fprintf(fp, "BRKP\n");
                return reg2;
                break;

            case FREE:
                printf("FREE::\n");
                reg2 = allocate_register();
                
                temp = 4;
                i=0;
                while(i<temp){
                    fprintf(fp,"PUSH R%d\n",i);
                    i++;
                }

                fprintf(fp,"MOV R%d, \"Free\"\n",reg2);
                fprintf(fp,"PUSH R%d\n",reg2);
                
                register_deallocate();
                reg1 = get_stack_addr(T->Ptr1);

                fprintf(fp,"MOV R%d, [R%d]\n",reg1,reg1);
                
                fprintf(fp,"PUSH R%d\n",reg1);
                fprintf(fp,"PUSH R0\n");
                fprintf(fp,"PUSH R0\n");
                fprintf(fp,"PUSH R0\n");
                fprintf(fp,"CALL 0\n");
                
                //fprintf(fp,"MOV R%d, [SP]\n",reg1);

                fprintf(fp,"SUB SP, 5\n");
                register_deallocate();
                

                i = 3;
                while(i>=0){
                    fprintf(fp, "POP R%d\n", i);
                    i--;
                }
                
                /*
                fprintf(fp,"MOV R%d, SP\n",reg1);
                fprintf(fp,"ADD R%d, 9\n",reg1);  
                fprintf(fp,"MOV R%d, [R%d]\n",reg1,reg1);
                */
                return -1;
                break;


            case EXIT:
                printf("EXIT::\n");
                fprintf(fp,"INT 10\n");
                /*
                fprintf(fp,"MOV R%d, SP\n",reg1);
                fprintf(fp,"ADD R%d, 9\n",reg1);  
                fprintf(fp,"MOV R%d, [R%d]\n",reg1,reg1);
                */
                return -1;
                break;

            case FUNC:
                printf("FUNC::\n");
                temp = 4;
                i=0;
                while(i<temp){
                    fprintf(fp,"PUSH R%d\n",i);
                    i++;
                }
                idx = 0;
                tUse = T->Args;
                GPtr = Glookup(T->NAME);
                while(tUse != NULL){
                    reg1 = code_gen(tUse);
                    idx++;
                    fprintf(fp,"PUSH R%d\n",reg1);
                    register_deallocate();
                    tUse = tUse->NEXT;
                }
                printf("%d\n",idx);
                fprintf(fp,"PUSH R0\n");
                fprintf(fp,"CALL L%d\n",GPtr->Label);

                reg2 = allocate_register();
                fprintf(fp,"POP R9\n");
                //while(idx--) fprintf(fp,"POP R%d\n",reg2);

                fprintf(fp,"SUB SP, %d\n",idx);
                register_deallocate();

                i = 3;
                while(i>=0){
                    fprintf(fp, "POP R%d\n", i);
                    i--;
                }

                reg1 = allocate_register();
                fprintf(fp,"MOV R%d, R9\n",reg1);
                return reg1;
                break;

            case PLUS:
                printf("PLUS::\n");
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"ADD R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;

            case MINUS:
                printf("MINUS::\n");
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"SUB R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;

           case MUL:
                printf("MUL::\n");
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"MUL R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;
           
           case DIV:
                printf("DIV::\n");
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"DIV R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;

            case MOD:
                printf("MOD::\n");
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                temp = allocate_register();
                fprintf(fp,"MOV R%d, R%d\n",temp,reg1);
                fprintf(fp,"DIV R%d, R%d\n",temp,reg2);
                fprintf(fp,"MUL R%d, R%d\n",temp,reg2);
                fprintf(fp,"SUB R%d, R%d\n",reg1,temp);
                register_deallocate();
                register_deallocate();
                return reg1;
                break;
            

           case LT:
                printf("LT::\n");
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"LT R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;

           case GT:
                printf("GT::\n");
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"GT R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;

           case EQ:
                printf("EQ::\n");
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"EQ R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;


           case LE:
                printf("LE::\n");
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"LE R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;

           case GE:
                printf("GE::\n");
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"GE R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;

           case NEQ:
                printf("NEQ::\n");
                reg1 = code_gen(T->Ptr1);
                reg2 = code_gen(T->Ptr2);
                fprintf(fp,"NE R%d, R%d\n",reg1,reg2);
                register_deallocate();
                return reg1;
                break;
        
            case CONST:
                printf("CONST::\n");
                reg1 = allocate_register();
                fprintf(fp,"MOV R%d, %d\n",reg1,T->VALUE);
                //printf("num %d\n",T->VALUE);
                return reg1;                

            case ID:
                printf("ID::\n");
                reg1 = allocate_register(); 
                reg2 = get_stack_addr(T);
                fprintf(fp,"MOV R%d, [R%d]\n",reg1,reg2);
                register_deallocate();
                return reg1;

            case FIELD:
                printf("FIELD::\n");
                reg1 = allocate_register(); 
                reg2 = get_stack_addr(T);
                fprintf(fp,"MOV R%d, [R%d]\n",reg1,reg2);
                register_deallocate();
                return reg1;

            case NULL_NODE:
                printf("NULL_NODE::\n");
                reg1 = allocate_register();
                fprintf(fp,"MOV R%d, -1\n",reg1);
                return reg1;

            case READ:
                printf("READ::\n");
                reg1 = allocate_register();
                
                temp = 4;
                i=0;
                while(i<temp){
                    fprintf(fp,"PUSH R%d\n",i);
                    i++;
                }

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
                fprintf(fp,"SUB SP, 5\n");
                
                i = 3;
                while(i>=0){
                    fprintf(fp, "POP R%d\n", i);
                    i--;
                }

                register_deallocate();
                register_deallocate();
                return -1;

            case WRITE:
                printf("WRITE::\n");
                reg1 = code_gen(T->Ptr1);
                fprintf(fp,"MOV [%d], R%d\n",4096,reg1);

                temp = 4;
                i=0;
                while(i<temp){
                    fprintf(fp,"PUSH R%d\n",i);
                    i++;
                }


                fprintf(fp,"MOV R%d, \"Write\"\n",reg1);
                fprintf(fp,"PUSH R%d\n",reg1);                   //FUNC CODE
                
                fprintf(fp,"MOV R%d, -2\n",reg1); 
                fprintf(fp,"PUSH R%d\n",reg1);                   //1st ARG
                fprintf(fp,"MOV R%d, 4096\n",reg1);
                fprintf(fp,"PUSH R%d\n",reg1);                   //2nd ARG ADDR of RESULT
                
                fprintf(fp,"PUSH R%d\n",reg1);                   // 3rd ARG
                fprintf(fp,"PUSH R%d\n",reg1);                   // RESULT
               
                fprintf(fp,"CALL 0\n");
                fprintf(fp,"POP R%d\n",reg1);                
                fprintf(fp,"POP R%d\n",reg1);                
                fprintf(fp,"POP R%d\n",reg1);                
                fprintf(fp,"POP R%d\n",reg1);
                fprintf(fp,"POP R%d\n",reg1);
                

                
                i = 3;
                while(i>=0){
                    fprintf(fp, "POP R%d\n", i);
                    i--;
                }

 
                register_deallocate();
                return -1;    

            case IF:
                printf("IF::\n");
                
                if(T->Ptr3 != NULL){
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
                
                }
                else{
                    start_label = label_counter+1;
                    label_counter+=1;
                    reg1 = code_gen(T->Ptr1);
                    fprintf(fp,"JZ R%d, L%d\n",reg1,start_label);
                    code_gen(T->Ptr2);
                                                                                                        //////////TEST CODE ONCE
                    ////ELSE PART
                    fprintf(fp,"L%d:\n",start_label);
                    
                    register_deallocate();    
                    
                }

                return -1;

            case WHILE:
                printf("WHILE::\n");
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
                printf("ASSGN::\n");

                reg1 = code_gen(T->Ptr2);
                reg2 = get_stack_addr(T->Ptr1);
                
              
                fprintf(fp,"MOV [R%d], R%d\n",reg2,reg1);
                register_deallocate();
                register_deallocate();
                return -1;
        }

    }
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