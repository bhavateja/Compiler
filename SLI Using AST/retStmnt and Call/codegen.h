int allocate_register();

void register_deallocate();

void write_header();

int get_stack_addr(struct tnode* T);

int code_gen(struct tnode* T);

void generate_target(struct tnode* T);
