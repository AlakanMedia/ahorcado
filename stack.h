#ifndef STACK_H
#define STACK_H

#include "letter.h"

typedef struct Node
{
    Letter ch;
    struct Node *back;
}
Node;

typedef struct Stack
{
    Node *head; 
	int size;
}
Stack;

char push(Stack *the_stack, unsigned char character);
unsigned char pop(Stack *the_stack);
char is_empty(Stack *the_stack);

#endif	// STACK_H
