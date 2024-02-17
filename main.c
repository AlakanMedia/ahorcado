#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int
main()
{
    stack *the_stack = (stack *) malloc(sizeof(stack));
    the_stack->head = NULL;

    push(the_stack, 'h');
    push(the_stack, 'o');
    push(the_stack, 'l');
    push(the_stack, 'a');

    printf("%c\n", pop(the_stack));
    printf("%c\n", pop(the_stack));
    printf("%c\n", pop(the_stack));
    printf("%c\n", pop(the_stack));

    free(the_stack);

    return 0; 
}
