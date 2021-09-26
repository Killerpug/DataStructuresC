//
// Created by A01229895 on 04/06/2019.
//

#ifndef CDS4HASHMAP_HASH_MAP_H
#define CDS4HASHMAP_HASH_MAP_H
#include <stddef.h>
#include <stdbool.h>
#define MAX_KEY_VALUE 16
#define MAX_LOAD 2
#define MIN_TABLE_SIZE 5
#define MIN_LOAD 0.5
#define UINT_MAX 4294967295
//to change type of data just change type of T
typedef int T;

typedef struct Node {
    T data;
    char key[MAX_KEY_VALUE];         //key is a string
    struct Node* next_node;
} Node;

typedef struct Hash_Table {
    struct Node** table;     //pointer to a  pointer to struct, in this case pointer to the beginning of an array of pointers to Nodes
    unsigned int size;          //# of elements
    unsigned int table_size;
    float load;
} Hash_Table;

typedef enum {                   //option to Erase the coincidences of an item, just the FIRST one/ or ALL matches found.
    FIRST, ALL
} Match;

Hash_Table* create_map();                                            //create the Hash_Table that stores nodes
void clear_map(Hash_Table* hash_table);
static void clear_table_nodes(Hash_Table* hash_table);
void print_map(Hash_Table *hash_table);
bool is_empty_map(Hash_Table* hash_table);
bool contains_key(char key[], Hash_Table* hash_table);
bool contains_value(T item, Hash_Table* hash_table);
void replace_entry(T new_item, char key[], Hash_Table* hash_table, Match match_type);    //replaces key-match old item with new_item
static Node* search_node(Node* iteration_node, char *with_key);
char* add_atomap(T item, Hash_Table** hash_table);               //add node to table with auto-generated key, returns key
static char* generate_key();
char* add_mtomap(T item, char key[], Hash_Table** hash_table);     //add node to table with a manual-typed key
static Node* node_init(T item, char key[]);                        //initializes node
static void resize_table(Hash_Table** hash_table, unsigned int new_table_size);
static unsigned int hash_code (char key[]);
T get_entry(char key[], Hash_Table* hash_table);  //retrieves matches of key
void remove_entry(char key[], Hash_Table** hash_table, Match type_of_match);   //removes Erase match(es) of key
static void search_remove_entry(Node* remove, Hash_Table** hash_table);


#endif //CDS4HASHMAP_HASH_MAP_H