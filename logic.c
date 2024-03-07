#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "logic.h"

void
clean_buffer()
{
    int ch_clean;

    // Esta línea la uso para limpiar el buffer
    while ((ch_clean = getchar()) != '\n' && ch_clean != EOF);
}

void
start_game()
{
    system("clear");

    stack *the_stack = (stack *) malloc(sizeof(stack));

    if (!the_stack)
		printf("Error: no se pudo asignar memoria\n");
    else
    {
		the_stack->head = NULL;
		the_stack->size = 0;

		srand(time(NULL));
		int index = rand() % NUM_WORDS;

    	unsigned char *word_selected = words_game[index];
    	int len_word = strlen(word_selected);
    	unsigned char board[len_word];
    	int num_attempts = ATTEMPTS;

    	for (int i = 0; i < len_word; i++)
    	    *(board + i) = '_';

    	while (!is_over(num_attempts) && !is_victory(board, len_word))
    	{
    	    system("clear");
    	    draw_hangman(num_attempts);
    	    draw_board(board, len_word);
    	    check_board(the_stack, board, word_selected,
						len_word, &num_attempts);
    	}

    	finish_game(the_stack, num_attempts, word_selected);
    	free(the_stack);
    	the_stack = NULL;
    }
}

void
finish_game(stack *the_stack, int num_attempts, unsigned char *word_selected)
{
    system("clear");
    draw_hangman(num_attempts);
    printf("La palabra es: %s\n\n", word_selected);

    if (is_over(num_attempts))
		printf("Fuiste ahorcado...\n");
    else
		printf("Felicitaciones, salvaste tu vida, por ahora...\n");

    printf("Letras seleccionadas: ");

    while (the_stack->head)
		printf("%c, ", pop(the_stack));

    printf("\n\nPresiona cualquier tecla para salir: ");
    getchar();
    clean_buffer();
}

char
is_over(int num_attempts)
{
    return (num_attempts > 0) ? 0 : 1;
}

char
is_victory(unsigned char board[], int len_word)
{
    for (int i = 0; i < len_word; i++)
		if (*(board + i) == '_')
	    	return 0;
    
    return 1;
}

void
draw_board(unsigned char board[], int len_word)
{
    for (int i = 0; i < len_word; i++)
		printf("%c ", *(board + i));

    printf("\n");
}

void
draw_hangman(int num_attempts)
{
    printf("  __\n");    
    printf(" |  %c\n", (num_attempts < 8) ? '|' : ' ');
    printf(" |  %c\n", (num_attempts < 7) ? '|' : ' ');
    printf(" |  %c\n", (num_attempts < 6) ? 'O' : ' ');
    printf(" | %c%c%c\n", (num_attempts < 4) ? '/' : ' ',
			  (num_attempts < 5) ? '|' : ' ',
			  (num_attempts < 3) ? '\\' : ' ');
    printf(" | %c %c\n", (num_attempts < 2) ? '/' : ' ',
			 (num_attempts < 1) ? '\\' : ' ');
    printf(" |\n");
    printf("---\n"); 
}

void
check_board(stack *the_stack, unsigned char board[], unsigned char *word,
	    	int len_word, int *num_attempts)
{
    unsigned char character;
    char is_in_word = 0;

    printf("Digite una letra: ");
    character = getchar();
    clean_buffer();

    if (push(the_stack, character))
    {
        for (int i = 0; i < len_word; i++)
	    	if (*(word + i) == character)
	    	{
				*(board + i) = character;
				is_in_word = 1;
	    	}
    
	    if (!is_in_word)
	    	(*num_attempts)--;
    }
    else
		printf("\nSucedió un error inesperado");
}
