# CDS4HashMap
Fourth Data Structure on C, HashMap implemented with "chaining with separate lists" as collision resolution strategy.
This implementation allows for duplicated hash keys, when retrieving keys check for ALL matches of FIRST
Methods:
Hash_Table* create_map();                                            //create the Hash_Table that stores nodes
void clear_map(Hash_Table* hash_table);
void print_map(Hash_Table *hash_table);
bool is_empty_map(Hash_Table* hash_table);
bool contains_key(char key[], Hash_Table* hash_table);
bool contains_value(T item, Hash_Table* hash_table);
void replace_entry(T new_item, char key[], Hash_Table* hash_table, Match match_type);    //replaces key-match of old item with new_item
char* add_atomap(T item, Hash_Table* hash_table);               //add node to table with auto-generated key, returns key
char* add_mtomap(T item, char key[], Hash_Table** hash_table);     //add node to table with a manual-typed key
T get_entry(char key[], Hash_Table* hash_table);  //retrieves matches of key
void remove_entry(char key[], Hash_Table** hash_table, Match type_of_match);   //removes Erase match(es) of key


Note -writing Dynamic Arrays with pointers- Is important to note that T** leArray is a pointer to a pointer of type T,
so that its possible perform pointer arithmetic Eg:(*(T+i)), to reference the location of the i element of type T* as 
long as you allocate properly the memory for each of the followup elements in CONTIGUOUS memory(calloc())
as noted in the line: leStruct->leArray = (leType**) calloc(n, sizeOf(leType));
which allocates memory for n leType objects in contiguous memory.

Note: is important to remark that pointers are passed to functions as copies, only values of pointed data can be changed 
inside a function and hold its value outside the function; so when a change to a pointer location itself is needed 
double pointers are used to "access the value of the memory location".
