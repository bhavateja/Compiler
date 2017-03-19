struct labelT *START = NULL;
int line_cache = 2056;

void labelInstall(int lab_ID, int addr){
	if(START == NULL){
		START = malloc(sizeof(struct labelT));
		START->lab_ID = lab_ID;
		START->addr = addr;
		START->NEXT = NULL;
		return;
	}
	struct labelT *newLabel;
	newLabel = malloc(sizeof(struct labelT));
	newLabel->lab_ID = lab_ID;
	newLabel->addr = addr;
	newLabel->NEXT = START;
	START = newLabel;
}

int get_label(int lab_ID){
	struct labelT *iter;
	iter = START;
	while(iter!=NULL){
		if(iter->lab_ID == lab_ID) return iter->addr;
		iter = iter->NEXT;
	}
}

void parse1(){
	fp = fopen("intermediate.xsm","r+");
	target = fopen("target1.xsm","w+");
	char line[256];
	int i = 8;
	int lab_ID;
	while(i--){
		fgets(line,sizeof(line),fp);
		fprintf(target,"%s",line);		
	}
	while(fgets(line,sizeof(line),fp)){
		if(line[0]=='L' && line[1]!='E' && line[1]!='T'){
			lab_ID = 0;
			i = 1;
			while(line[i]!=':'){
				lab_ID*=10;
				lab_ID+=(line[i]-48);
				i++;
			}
			printf("Found L%d\n",lab_ID);
			labelInstall(lab_ID,line_cache);
		}
		else{
			fprintf(target,"%s",line);	
			line_cache+=2;
		}
	}
	fclose(target);
	fclose(fp);
}

void parse2(){
	target = fopen("target.xsm","w+");
	fp = fopen("target1.xsm","r+");
	char line[256];
	int i,lab_ID,R_ID;
	while(fgets(line,sizeof(line),fp)){
		if(line[0]=='J'){
			if(line[1]=='M' && line[2]=='P'){
				lab_ID = 0;
				i = 5;
				while(line[i]!='\n' && line[i]!='\0'){
					lab_ID*=10;
					lab_ID+=(line[i]-48);
					i++;
				}
				lab_ID = get_label(lab_ID);
				fprintf(target,"JMP %d\n",lab_ID);
			}
			if(line[1]=='Z'){
				R_ID = 0;
				i = 4;
				while(line[i]!=',' && line[i]!=' '){
					R_ID*=10;
					R_ID+=(line[i]-48);
					i++;
				}
				while(line[i]!='L') i++;
				i++;
				lab_ID = 0;
				while(line[i]!='\n' && line[i]!='\0'){
					lab_ID*=10;
					lab_ID+=(line[i]-48);
					i++;
				}
				lab_ID = get_label(lab_ID);
				fprintf(target,"JZ R%d, %d\n",R_ID,lab_ID);

			}
		}
		else if(line[0]=='C' && line[1]=='A' && line[2]=='L' && line[3]=='L' && line[5]=='L'){
			i = 6;
			lab_ID = 0;
			while(line[i]!='\n' && line[i]!='\0'){
				lab_ID*=10;
				lab_ID+=(line[i]-48);
				i++;
			}
			lab_ID = get_label(lab_ID);
			fprintf(target, "CALL %d\n",lab_ID );
		}
		else{
			fprintf(target,"%s",line);
		}
	}
}