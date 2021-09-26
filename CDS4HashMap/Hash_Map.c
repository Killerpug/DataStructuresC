//
// Created by A01229895 on 04/06/2019.
//

#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include "Hash_Map.h"
#include <time.h>


Hash_Table* create_map() {
    Hash_Table* new_table = (Hash_Table*) malloc(sizeof(Hash_Table));
    new_table->table = (Node**) calloc(MIN_TABLE_SIZE, sizeof(Node));          //allocate and initialize(to NULL) table array of 5 elements
    new_table->size = 0;
    new_table->table_size = 5;
    new_table->load = 0.0f;
    return new_table;
}

void clear_map(Hash_Table* hash_table) {
    clear_table_nodes(hash_table);
    free(hash_table->table);            //free table (calloc())
    free(hash_table);                   //free hash_table (malloc())
}

static void clear_table_nodes(Hash_Table* hash_table) {
    for (int i = 0; i < hash_table->table_size; ++i) {          //iterate through old table,
        Node* entry = hash_table->table[i];
        Node* previous_node = NULL;
        while (entry != NULL) {                                 //erase all nodes on the table cell
            previous_node = entry;
            entry = entry->next_node;
            free(previous_node);
        }
    }
}

void print_map(Hash_Table *hash_table) {
    for (int i = 0; i < hash_table->table_size; ++i) {          //iterate through old table,
        Node* entry = hash_table->table[i];
        printf("Bucket %i:", i + 1);
        while (entry != NULL) {                                 //reallocate all nodes of each cell on array, on new table
            printf(" %i,", entry->data);
            entry = entry->next_node;
        }
        printf("\b. \n");
    }
}

bool is_empty_map(Hash_Table* hash_table) { return hash_table->size == 0; }

bool contains_key(char key[], Hash_Table* hash_table) {
    unsigned int hash_index = hash_code(key) % hash_table->table_size;
    Node* table_entry = hash_table->table[hash_index];;
    return search_node(table_entry, key) != NULL;
}

bool contains_value(T item, Hash_Table* hash_table){
    Node* entry;
    for (int i = 0; i < hash_table->table_size; ++i) {              //iterate table and bucket, comparing data
        entry = hash_table->table[i];
        while (entry != NULL && item != entry->data)
            entry = entry->next_node;
        if(entry != NULL) return true;
    }
    return false;
}

void replace_entry(T new_item, char key[], Hash_Table* hash_table, Match match_type) {
    unsigned int hash_index = hash_code(key) % hash_table->table_size;
    Node* entry_node = hash_table->table[hash_index];
    Node* is_match = search_node(entry_node, key);
    if (is_match == NULL) {             //list is empty or does not contain node
        printf("Bucket does not contain element with key: '%s'.\n", key);
        return;
    }
    if (match_type == FIRST) {          //search and replace item of first key-match
        printf("Match found and replaced at bucket: %i\n", hash_index);
        is_match->data = new_item;
    } else {                            //replace all matches
        int total_matches = 0;
        while (is_match != NULL) {
            is_match->data = new_item;          //replace data
            is_match = search_node(is_match->next_node, key);
            total_matches++;
        }
        printf("A total of %i matches of key '%s' were found and replaced on bucket[%i]. \n", total_matches, key, hash_index);
    }
}

static Node* search_node(Node* iteration_node, char* with_key) {        //iterate Bucket, searching key-match
    while (iteration_node != NULL && !strstr(iteration_node->key, with_key)) {
        iteration_node = iteration_node->next_node;
    }
    return iteration_node;
}

char* add_atomap(T item, Hash_Table** hash_table) {
    char* gen_k = generate_key();
    char* key = add_mtomap(item, gen_k, hash_table);
    free(gen_k);
    return key;
}

static char* generate_key() {
    char key[MAX_KEY_VALUE];
    for (int i = 0; i < MAX_KEY_VALUE-1; ++i) {
        key[i] = (char) (rand() % 126);
    }
    return strdup(key);
}

char* add_mtomap(T item, char key[], Hash_Table** hash_table) {
    Hash_Table* hashy = *hash_table;                                  //hashy: alias to dereference double pointer, to work with Hashtable*
    hashy->load = (float) hashy->size / hashy->table_size;
    if(hashy->load >= MAX_LOAD)                                      //collisions are highly probable, increase size to reduce collisions
        resize_table(hash_table, hashy->table_size * 2 + 1);
    hashy = *hash_table;                                             //re-assign hashy; resize_table() erase previous hashy pointer
    Node* node = node_init(item, key);
    unsigned int hash_index = hash_code(key) % hashy->table_size;
    Node* table_entry = hashy->table[hash_index];                    //*(ht->table + i) = ht->table[i], read i bucket of table
    if(table_entry == NULL) {
        hashy->table[hash_index] = node;                            //Insert node at first position
    } else {
        while (table_entry->next_node != NULL) {                     //search last node on list
            table_entry = table_entry->next_node;
        }
        table_entry->next_node = node;                               //insert node on last-node->next-position
    }
    hashy->size++;
    return node->key;
}

static void resize_table(Hash_Table** hash_table, unsigned int new_table_size) {
    //create a new resized Hash Table to reallocate contents
    Hash_Table* hashy = *hash_table;                                    //dereference double pointer, work with Hashtable*
    Hash_Table* new_table = (Hash_Table*) malloc(sizeof(Hash_Table));
    new_table->table = (Node**) calloc(new_table_size, sizeof(Node));          //allocate resized space for table
    new_table->size = 0;
    new_table->table_size = new_table_size;
    //copy and redistribute contents of old table to new one
    for (int i = 0; i < hashy->table_size; ++i) {          //iterate through old table,
        Node* entry = hashy->table[i];
        while (entry != NULL) {                                 //reallocate all nodes of each cell on array, on new table
            add_mtomap(entry->data, entry->key, &new_table);
            entry = entry->next_node;
        }
    }
    new_table->load = (float) new_table->size / new_table->table_size;
    clear_map(*hash_table);                 //erase nodes and pointers of old table
    *hash_table = new_table;                //point old hash_table to new contents (which memory locations are new_table).
}

static Node* node_init(T item, char key[]) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = item;
    strcpy(node->key, key);                      //copy key to node->key
    node->next_node = NULL;
    return  node;
}

static unsigned int hash_code(char key[]) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        hash = (31*hash + key[i]) % (unsigned int) UINT_MAX;        //avoid overflow
    }
    return hash;
}

T get_entry(char key[], Hash_Table* hash_table) {            //retrieves matches of key
    unsigned int hash_index = hash_code(key) % hash_table->table_size;
    Node* table_entry = hash_table->table[hash_index];
    while (table_entry != NULL && !strstr(table_entry->key, key)) {
        table_entry = table_entry->next_node;
    }
    return table_entry != NULL ? table_entry->data : (printf("Match not found"), -1);
}

void remove_entry(char key[], Hash_Table** hash_table, Match type_of_match) {
    Hash_Table* hashy = *hash_table;
    unsigned int hash_index = hash_code(key) % hashy->table_size;
    Node* iterative_node = hashy->table[hash_index];
    if (iterative_node == NULL) {                             //Bucket is empty
        printf("Bucket is empty");
        return;
    }
    Node* previous_node = NULL;
    while (iterative_node != NULL) {
        if(!strstr(iterative_node->key, key)) {     //node is not the target, update values and go to next iteration
            previous_node = iterative_node;
            iterative_node = iterative_node->next_node;
            continue;
        }
        if (previous_node != NULL) {                //target on middle, skip and delete target from chaining list
            Node* temp = iterative_node;
            previous_node->next_node = iterative_node->next_node;
            iterative_node = iterative_node->next_node;
            search_remove_entry(temp, hash_table);
        } else {                                     //target is start of bucket
            Node *temp = iterative_node;
            iterative_node = iterative_node->next_node;
            search_remove_entry(temp, hash_table);
            hashy->table[hash_index] = iterative_node;  //put new head at bucket start
        }
        if(type_of_match == FIRST) break;       //only one iteration for FIRST deletion match
    }
    hashy->load = (float) hashy->size / hashy->table_size;                  //load calculated at end of deletion to avoid invalid memory
    if(hashy->load <= MIN_LOAD && hashy->table_size >  MIN_TABLE_SIZE)       //table is oversized, reduce size to save memory
        resize_table(hash_table, (hashy->table_size - 1) / 2);
}

static void search_remove_entry(Node* remove, Hash_Table** hash_table) {
    Hash_Table* hashy = *hash_table;        //alias to dereference double pointer, work with Hashtable*
    hashy->size--;
    printf("You have erased: %i \n", remove->data);
    free(remove);
}