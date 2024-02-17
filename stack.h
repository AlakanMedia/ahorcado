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

#endif	// STACK
