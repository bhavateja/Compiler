// header file to store all the structures and declarations of functions dealing with type declarations

struct Typetable {
    char *NAME;                 //type name
    struct Fieldlist *fields;   //pointer to the head of fields list
    struct Typetable *NEXT;     // pointer to the next type table entry
};

struct Fieldlist {
  char *NAME;              //name of the field
  int fieldIndex;          //the position of the field in the field list
  struct Typetable *TYPE;  //pointer to type table entry of the field's type
  struct Fieldlist *NEXT;  //pointer to the next field
};

void TypeTableCreate();

struct Typetable *Tlookup (char *name);

struct Typetable *Tinstall (char *name, struct Fieldlist *fields);

struct Fieldlist *FLookup(struct Typetable *type, char *name);

struct Fieldlist *Finstall(char *name); 

struct Typetable *ttable; // this is the current type table that is
struct Typetable *temp_ttable;
struct Fieldlist *current_flist;
struct Fieldlist *temp_current_flist;
struct Fieldlist *temp_flist;

struct Typetable *VAR_TYPE_INT = NULL;
struct Typetable *VAR_TYPE_BOOL = NULL;
struct Typetable *VAR_TYPE_VOID = NULL;