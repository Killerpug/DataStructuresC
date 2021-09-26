//
// Created by A01229895 on 03/06/2019.
//

#ifndef CDS3QUEUE_LINKEDQUEUE_H
#define CDS3QUEUE_LINKEDQUEUE_H
#include <stdbool.h>
//to change type of data just change type of T
typedef int T;

typedef struct Node {
    T data;
    struct Node* next_node;
    struct Node* previous_node;
} Node;

typedef struct Queue {
    struct Node* head;
    struct Node* tail;
    int size;
} Queue;

Node* create_node (T item);                 //create a new node with data, ref to next node, returns the pointer to mem loc.
Node* add_node (Node* node, Queue* queue);
Node* enqueue (T item, Queue* queue);
T peek_queue(Queue* queue);
T dequeue (Queue* queue);
bool contains (T item, Queue* list);
Queue* create_queue ();                      //create the Queue that stores nodes
void clear_queue (Queue* queue);
void print_queue (Queue* queue);            //prints queue FIFO
static void private_remove_adjust (Node* remove, Queue* queue);       //adjust size, memory space
int size (Queue* queue);
bool is_empty (Queue* queue);

#endif //CDS3QUEUE_LINKEDQUEUE_H
