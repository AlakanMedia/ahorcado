#ifndef STACK
#define STACK

#include "letter.h"

typedef struct node
{
    letter ch;
    struct node *back;
}
node;

typedef struct stack
{
    node *head; 
}
stack;

void push(stack *the_stack, char character);
char pop(stack *the_stack);
int is_empty(stack *the_stack);

#endif	// STACK
