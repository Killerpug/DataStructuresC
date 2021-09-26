
#include <stdio.h>
#include "LinkedQueue.h"
int main( )
{
    Queue* queue1 = create_queue();
    Queue* queue2 = create_queue();
    Queue* queue3 = create_queue();
    for (int i = 0; i < 100; ++i) {     //check memory leaks
        Queue* i = create_queue();
        enqueue(2, i);
        enqueue(2, i);
        clear_queue(i);
    }
    Queue* queue4 = create_queue();
    enqueue(40, queue3);
    enqueue(20, queue3);
    enqueue(1, queue2);
    enqueue(2, queue2);
    enqueue(3, queue2);
    enqueue(4, queue2);
    enqueue(5, queue2);

    bool contained_element = contains(3, queue1);

    print_queue(queue2);
    T item1 = dequeue(queue1);  //check empty queue
    T item12 = dequeue(queue3);     //check non-empty stack
    T item3 = peek_queue(queue2);
    T item4 = dequeue(queue2);
    clear_queue(queue1);
    bool emptylist = is_empty(queue4);
    clear_queue(queue2);
    clear_queue(queue3);
    clear_queue(queue4);
    return 0;

}
