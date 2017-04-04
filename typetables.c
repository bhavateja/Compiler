

void TypeTableCreate() {

  // add "boolean" as a type

  ttable = (struct Typetable *) malloc(sizeof(struct Typetable));
  ttable -> NAME = (char *) malloc(sizeof(char) * 30);
  strcpy(ttable -> NAME, "boolean");
  ttable -> fields = NULL;
  ttable -> NEXT = NULL;
  VAR_TYPE_BOOL = ttable;

  // add integer as type

  struct Typetable *new_ttable = (struct Typetable *) malloc(sizeof(struct Typetable));
  new_ttable -> NAME = (char *) malloc(sizeof(char) * 30);
  strcpy(new_ttable -> NAME, "integer");
  new_ttable -> fields = NULL;
  new_ttable -> NEXT = ttable;
  ttable = new_ttable;
  VAR_TYPE_INT = ttable;
}

// search through the type table and return pointer to type table entry of type 'name'.
// Returns NULL if entry is not found.

struct Typetable *Tlookup (char *name) {
  temp_ttable = ttable;
  while (temp_ttable != NULL) {
    if (strcmp(temp_ttable -> NAME, name) == 0) {
      return temp_ttable;
    }
    temp_ttable = temp_ttable -> NEXT;
  }
  return NULL;
}

struct Typetable *Tinstall (char *NAME, struct Fieldlist *fields) {
   temp_ttable = (struct Typetable *) malloc(sizeof(struct Typetable));
   temp_ttable -> NAME = (char *) malloc(sizeof(char) * 30);
   strcpy(temp_ttable -> NAME, NAME);
   temp_ttable -> fields = fields;
   temp_ttable -> NEXT = ttable;
   ttable = temp_ttable;
}

struct Fieldlist *FLookup(struct Typetable *type, char *name) {
  struct Fieldlist *reqd_fieldlist = type -> fields;
  while (reqd_fieldlist != NULL) {
    if (strcmp(reqd_fieldlist -> NAME, name)  == 0) {
      return reqd_fieldlist;
    }
    reqd_fieldlist = reqd_fieldlist -> NEXT;
  }
  return NULL;
}

struct Fieldlist *Finstall(char *name) {

  // this will install a field of type 'type' with name 'name' :-P to the temp_current_flist
  struct Fieldlist *new_flist = (struct Fieldlist *) malloc(sizeof(struct Fieldlist));
  new_flist -> NAME = (char *) malloc(sizeof(char) * 30);
  strcpy(new_flist -> NAME, name);

  if (temp_current_flist == NULL) {
    new_flist -> NEXT = NULL;
  }
  else {
    new_flist -> NEXT = temp_current_flist;
  }
  temp_current_flist = new_flist;
  return new_flist;
}

