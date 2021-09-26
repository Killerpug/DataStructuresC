//
// Created by A01229895 on 03/06/2019.
//

#include "LinkedQueue.h"
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>

Queue* create_queue() {
    Queue* new_queue = (Queue*) malloc(sizeof(Queue));       //reserve enough space for Queue structure
    new_queue->head = NULL;
    new_queue->tail = NULL;
    new_queue->size = 0;
    return new_queue;
}

void clear_queue(Queue* queue) {
    if(queue->size == 0) {
        free(queue);
        return;
    }
    Node* next_deletion = queue->head;
    Node* delete = NULL;
    while (next_deletion != NULL) {               //free memory used by nodes on queue
        delete = next_deletion;
        next_deletion = next_deletion->next_node;
        free(delete);
    }
    free(queue);
    printf("queue deleted \n");
}

Node* create_node(T item) {                    //allocates memory and assigns initial values
    Node* new_node = (Node*) malloc(sizeof(Node));   //cast to assure same pointer type
    new_node->next_node = NULL;
    new_node->previous_node = NULL;
    new_node->data = item;
    return new_node;
}

Node* add_node(Node* node, Queue* queue) {                  //Adds a node to the queue
    queue->size++;
    if(queue->head == NULL){                               //if empty queue, added node is head and tail
        queue->head = node;
        queue->tail = node;
    } else {                                              //Add node, new head
        Node* temp = queue->head;
        queue->head = node;
        queue->head->next_node = temp;
        temp->previous_node = node;                     //previous node reference
    }
    return node;
}

Node* enqueue(T item, Queue* queue) {                  //create and add a node to a queue
    Node* new_node = create_node(item);              //create
    return add_node(new_node, queue);                 //add
}

T peek_queue(Queue* queue) {                       //returns item if size>0 or -1 if empty stack
    return queue->size == 0 ? (printf("Queue is empty\n"), -1) : queue->tail->data;
}

T dequeue(Queue* queue) {
    if(queue->size == 0) {
        printf("No elements on queue\n");
        return -1;
    } else {
        T dequeued_item = queue->tail->data;
        private_remove_adjust(queue->tail, queue);
        return dequeued_item;
    }
}

static void private_remove_adjust(Node* remove, Queue* queue) {
    queue->size--;
    queue->tail->previous_node->next_node = NULL;       //erase reference of previous node to next node
    queue->tail = queue->tail->previous_node;           //update tail
    printf("You have erased: %i \n", remove->data);
    free(remove);
}

bool contains(T item, Queue* queue) {                       //returns node with item if found or NULL if not found
    if(queue->size == 0) {
        printf("No elements on queue\n");
        return 0;
    }
    Node* search = queue->head;
    while ( (search->next_node) != NULL && (search->data != item) ) {       //iterate to find node to Erase
        search = search->next_node;
    }
    return (search->data == item);           //compare_items inline
}


void print_queue(Queue* queue) {
    Node* next = queue->tail;
    for (int i = 1; i <= queue->size; ++i) {
        printf("element %i: %i \n", i, next->data);
        next = next->previous_node;
    }
}
int size(Queue* queue) {
    return queue->size;
}

bool is_empty(Queue* queue) {
    return queue->size == 0;
}