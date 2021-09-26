//
// Created by A01229895 on 28/05/2019.
//

#include <malloc.h>
#include "Linked_List.h"
#include <stdio.h>
#include <stdbool.h>

List* create_list() {
    List* new_list = (List*) malloc(sizeof(List));       //reserve enough space for List structure
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

void delete_list(List* list) {
    Node* next_deletion = list->head;
    Node* delete = NULL;
    while (next_deletion != NULL) {               //free memory used by nodes on list
        delete = next_deletion;
        next_deletion = next_deletion->next_node;
        free(delete);
    }
    free(list);
    printf("deleted \n");
}

Node* create_node(T item) {
    Node* new_node = (Node*) malloc(sizeof(Node));   //cast to assure same pointer type
    new_node->next_node = NULL;
    new_node->data = item;
    return new_node;
}

Node* add_node(Node* node, List* list) {                  //Adds a node to the list
    list->size++;
    if(list->head == NULL){                               //if empty list, node is head
        list->head = node;
    } else {                                              //Add node, new head
       Node* temp = list->head;
       list->head = node;
       list->head->next_node = temp;
    }
    return node;
}

Node* add_new_node(T item, List* list) {                  //create and add a node to a list
    Node* new_node = create_node(item);              //create
    return add_node(new_node, list);                 //add
}

void remove_node(T item, List* list, Erase type_of_deletion) {
    if(list->size == 0) return;
    if(item == list->head->data) {                                   //case node is the head
        Node* remove = list->head;
        list->head = list->head->next_node;                         //change head
        private_remove_adjust(remove, list, type_of_deletion);
        return;
    }
    Node* search = list->head;
    Node* previous = NULL;
    while ( (search->next_node) != NULL && (search->data != item) ) {       //iterate to find node to Erase while list have isnt empty
        previous = search;
        search = search->next_node;
    }
    if(compare_items(search->data, item)) {                                           //match found, Erase node
        previous->next_node = search->next_node;                //delete reference from previous node
        private_remove_adjust(search, list, type_of_deletion);
    }
    else printf("No more nodes found\n");
}

void private_remove_adjust(Node* remove, List* list, Erase type) {
    list->size--;
    printf("You have erased: %i \n", remove->data);
    if(type == ALL)                                     //deletes all the coincidences
        remove_node(remove->data, list, ALL);
    free(remove);
}

Node* search_node(T item, List* list) {                       //returns node with item if found or NULL if not found
    Node* search = list->head;
    while ( (search->next_node) != NULL && (search->data != item) ) {       //iterate to find node to Erase
        search = search->next_node;
    }
    return (search->data == item) ? search : NULL;           //compare_items inline
}

bool compare_items(T item1, T item2) {
    return (item1 == item2);
}

void reverse_list(List* list) {
    Node* new_ref = list->head->next_node;                 //save left node list
    list->head->next_node = NULL;                         // last element on reversed list
    for (int i = 1; i < (list->size); ++i) {
        Node* temp = list->head;                       //add node, new head
        list->head = new_ref;
        new_ref = new_ref->next_node;                    //update left list of nodes
        list->head->next_node = temp;                     //reverse position
    }
}

void print_list(List* list) {
    Node* next = list->head;
    for (int i = 1; i <= list->size; ++i) {
        printf("element %i: %i \n", i, next->data);
        next = next->next_node;
    }
}