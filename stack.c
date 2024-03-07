#include <stdlib.h>
#include "stack.h"

char
is_empty(stack *the_stack)
{
    return (the_stack->size) ? 0 : 1;
}

char
push(stack *the_stack, unsigned char character)
{
    node *new_node = (node *) malloc(sizeof(node));  

    if (!new_node)
		return 0;

	new_node->ch.character = character;
    new_node->back = NULL;

    if (is_empty(the_stack))
        the_stack->head = new_node;
    else
    {
        new_node->back = the_stack->head;
        the_stack->head = new_node;
    }

	return 1;
}

unsigned char
pop(stack *the_stack)
{
	if (is_empty(the_stack))
		return '\0';

    unsigned char character;
	character = the_stack->head->ch.character;

    node *aux = the_stack->head;
    the_stack->head = the_stack->head->back;
    aux->back = NULL;
    free(aux);
	aux = NULL;

    return character;
}
