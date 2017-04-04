typedef struct labelT{
	int lab_ID;
	int addr;
	struct labelT *NEXT;
}labelT;

void labelInstall(int lab_ID, int addr);

int get_label(int lab_ID);

void parse1();

void parse2();