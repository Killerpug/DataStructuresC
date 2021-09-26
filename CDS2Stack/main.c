//
// Created by A01229895 on 01/06/2019.
//
#include <stdio.h>
#include "Stack.h"
int main() {
    Stack* stack1 = create_stack();
    Stack* stack2 = create_stack();
    Stack* stack3 = create_stack();
    for (int i = 0; i < 100; ++i) {     //check memory leaks
        Stack* i = create_stack();
        push(2, i);
        push(2, i);
        delete_stack(i);
    }
    Stack* stack4 = create_stack();
    push(4, stack3);
    push(2, stack4);
    push(1, stack2);
    push(2, stack2);
    push(3, stack2);
    push(4, stack2);
    push(5, stack2);

    print_stack(stack2);
    reverse_stack(stack2);
    print_stack(stack2);
    T item1 = pop(stack1);  //check empty stack
    T item12 = pop(stack3);     //check non-empty stack
    T item3 = peek(stack1);
    delete_stack(stack1);
    delete_stack(stack2);
    delete_stack(stack3);
    delete_stack(stack4);


    return 0;
}
