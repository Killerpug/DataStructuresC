//
// Created by A01229895 on 28/05/2019.
//

#include <malloc.h>
#include "Stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>

Stack* create_stack() {
    Stack* new_stack = (Stack*) malloc(sizeof(Stack));       //reserve enough space for Stack structure
    new_stack->head = NULL;
    new_stack->size = 0;
    return new_stack;
}

void delete_stack(Stack* stack) {
    Node* next_deletion = stack->head;
    Node* delete = NULL;
    while (next_deletion != NULL) {               //free memory used by nodes on stack
        delete = next_deletion;
        next_deletion = next_deletion->next_node;
        free(delete);
    }
    free(stack);
    printf("deleted \n");
}

Node* create_node(T item) {
    Node* new_node = (Node*) malloc(sizeof(Node));   //cast to assure same pointer type
    new_node->next_node = NULL;
    new_node->data = item;
    return new_node;
}

Node* add_node(Node* node, Stack* stack) {                  //Adds a node to the stack
    stack->size++;
    if(stack->head == NULL){                               //if empty stack, node is head
        stack->head = node;
    } else {                                              //Add node, new head
        Node* temp = stack->head;
        stack->head = node;
        stack->head->next_node = temp;
    }
    return node;
}

Node* push(T item, Stack *stack) {                  //create and add a node to a stack
    Node* new_node = create_node(item);              //create
    return add_node(new_node, stack);                 //add
}

T pop(Stack *stack) {
    if(stack->size == 0) {
        printf("Stack is empty\n");
        return -1;
    } else {                                   //case node is the head
        Node* remove = stack->head;
        T deleted_data = remove->data;                                          //store node to return it
        stack->head = stack->head->next_node;                         //change head reference
        private_remove_adjust(remove, stack);
        return deleted_data;
    }
}

static void private_remove_adjust(Node* remove, Stack* stack) {        //free memory and deletions details
    stack->size--;
    printf("You have erased: %i \n", remove->data);
    free(remove);
}

T peek(Stack* stack) {                       //returns item if size>0 or -1 if empty stack
    return stack->size == 0 ? (printf("Stack is empty\n"), -1) : stack->head->data;
}

void reverse_stack(Stack* stack) {
    Node* new_ref = stack->head->next_node;                 //save left node stack
    stack->head->next_node = NULL;                         // last element on reversed stack
    for (int i = 1; i < (stack->size); ++i) {
        Node* temp = stack->head;                       //add node, new head
        stack->head = new_ref;
        new_ref = new_ref->next_node;                    //update left stack of nodes
        stack->head->next_node = temp;                     //reverse position
    }
}

void print_stack(Stack* stack) {
    Node* next = stack->head;
    for (int i = 1; i <= stack->size; ++i) {
        printf("element %i: %i \n", i, next->data);
        next = next->next_node;
    }
}

int size(Stack* stack) {
    return stack->size;
}

bool is_empty(Stack* stack) {
    return stack->size == 0;
}