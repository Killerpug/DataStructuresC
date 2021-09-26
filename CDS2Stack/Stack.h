//
// Created by A01229895 on 01/06/2019.
//

#ifndef CDS1LINKEDLIST_STACK_H
#define CDS1LINKEDLIST_STACK_H
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

typedef struct Stack {
    struct Node* head;
    int size;
} Stack;

Node* create_node (T item);                 //create a new node with data, ref to next node, returns the pointer to mem loc.
Node* add_node (Node* node, Stack* stack);
Node* push(T item, Stack *stack);
T pop(Stack *stack);
T peek(Stack *stack);
Stack* create_stack();                      //create the Stack that stores nodes
void delete_stack(Stack* stack);
void reverse_stack(Stack* stack);
void print_stack(Stack* stack);
static void private_remove_adjust (Node* remove, Stack* stack);       //adjust size, memory space, recurrent deletion
int size(Stack* stack);
bool is_empty(Stack* stack);
#endif //CDS1LINKEDLIST_LINKED_LIST_H

#endif //CDS1LINKEDLIST_STACK_H
