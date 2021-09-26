//
// Created by A01229895 on 28/05/2019.
//

#ifndef CDS1LINKEDLIST_LINKED_LIST_H
#define CDS1LINKEDLIST_LINKED_LIST_H

#include <stdbool.h>
//to change type of data just change type of T
typedef int T;

typedef struct Node {
    T data;
    struct Node* next_node;
} Node;

typedef struct List {
    struct Node* head;
    int size;
} List;

typedef enum {                   //option to Erase the coincidences of an item, just the FIRST one/ or ALL matches found.
    FIRST, ALL
} Erase;

Node* create_node (T item);                 //create a new node with data, ref to next node, returns the pointer to mem loc.
Node* add_node (Node* node, List* list);
Node* add_new_node (T item, List* list);
void remove_node (T item, List* list, Erase type_of_deletion);
Node* search_node (T item, List* list);
bool compare_items (T item1, T item2);
List* create_list ();                      //create the List that stores nodes
void delete_list (List* list);
void reverse_list (List* list);
void print_list (List* list);
void private_remove_adjust (Node* remove, List* list, Erase type);       //adjust size, memory space, recurrent deletion
#endif //CDS1LINKEDLIST_LINKED_LIST_H
