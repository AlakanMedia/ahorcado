#include <stdlib.h>
#include "stack.h"

int
is_empty(stack *the_stack)
{
    return (the_stack->head) ? 0 : 1;
}

void
push(stack *the_stack, char character)
{
    node *new_node = (node *) malloc(sizeof(node));  
    new_node->ch.character = character;
    new_node->back = NULL;

    if (is_empty(the_stack))
	the_stack->head = new_node;
    else
    {
	new_node->back = the_stack->head;
	the_stack->head = new_node;
    }
}

char
pop(stack *the_stack)
{
    char character = '\n';

    if (!is_empty(the_stack))
    {
	character = the_stack->head->ch.character;

    	node *aux = the_stack->head;
    	the_stack->head = the_stack->head->back;
    	aux->back = NULL;
    	free(aux);
    }

    return character;
}
