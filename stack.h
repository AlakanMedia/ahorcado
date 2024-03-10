#ifndef STACK_H
#define STACK_H

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
	int size;
}
stack;

char push(stack *the_stack, unsigned char character);
unsigned char pop(stack *the_stack);
char is_empty(stack *the_stack);

#endif	// STACK_H
