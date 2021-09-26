# CDS2Stack
Second data structure on C, Dynamic Stack. The Stack provides LIFO access to the information, that means it retrieves information 
in the reverse order that it was stored like a stack of plates.
The main 3 methods of a Stack are:
Push(): Inserts an element at the top of the Stack.
Pop(): Removes and returns the top element of the Stack.
Peek(): Returns the top element of the Stack without removing it.

Methods:

Node* create_node (T item);                     //create a new node with data, ref to next node, returns the pointer to mem loc.
Node* add_node (Node* node, Stack* stack);
Node* push(T item, Stack *stack);
T pop(Stack *stack);
T peek(Stack *stack);
Stack* create_stack();                                               //create the Stack that stores nodes
void delete_stack(Stack* stack);
void reverse_stack(Stack* stack);
void print_stack(Stack* stack);
static void private_remove_adjust (Node* remove, Stack* stack);       //adjust size, memory space, recurrent deletion
int size(Stack* stack);
bool is_empty(Stack* stack);
