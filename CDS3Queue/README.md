# CDS3Queue
Third Data Structure on C, dynamic queue. A Queue is a FIFO structure, it allows to retrieve information in the same order is added,
the main methods 3 of a Queue are:
 -enqueue(): Insert an element at the start(one end) of the queue
 -dequeue(): Removes and returns the oldest element of the Queue which is the farthest element from the start(other end).
 -peek(): same as dequeue() but without removing the element from the Queue.
 
Methods:

- Node* create_node (T item);                 //create a new node with data, ref to next node, returns the pointer to mem loc.
- Node* add_node (Node* node, Queue* queue);
- Node* enqueue (T item, Queue* queue);
- T peek_queue(Queue* queue);
- T dequeue (Queue* queue);
- bool contains (T item, Queue* list);
- Queue* create_queue ();                                                //create the Queue that stores nodes
- void clear_queue (Queue* queue);
- void print_queue (Queue* queue);                                      //prints queue FIFO
- static void private_remove_adjust (Node* remove, Queue* queue);       //adjust size, memory space
- int size (Queue* queue);
- bool is_empty (Queue* queue);
