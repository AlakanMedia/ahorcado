#include <stdlib.h>
#include "stack.h"

char
is_empty(Stack *the_stack)
{
    return (the_stack->size) ? 0 : 1;
}

char
push(Stack *the_stack, unsigned char character)
{
    Node *new_node = (Node *) malloc(sizeof(Node));  

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

	the_stack->size++;

	return 1;
}

unsigned char
pop(Stack *the_stack)
{
	if (is_empty(the_stack))
		return '\0';

    unsigned char character = the_stack->head->ch.character;

    Node *aux = the_stack->head;
    the_stack->head = the_stack->head->back;
    aux->back = NULL;
    free(aux);
	aux = NULL;

	the_stack->size--;

    return character;
}
