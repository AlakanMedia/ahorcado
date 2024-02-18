#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logic.h"

void
start_game()
{
    system("clear");

    unsigned char *word_selected = "Zanahoria";
    int len_word = strlen(word_selected);
    unsigned char board[len_word];
    int num_attempts = ATTEMPTS;

    for(int i = 0; i < len_word; i++)
	*(board + i) = '_';

    while (num_attempts)
    {
	system("clear");
	draw_board(board, len_word);
    	check_board(board, word_selected, len_word, &num_attempts);
    }
}

void
draw_board(unsigned char board[], int len_word)
{
    for (int i = 0; i < len_word; i++)
	printf("%c ", *(board + i));

    printf("\n");
}

void
check_board(unsigned char board[], unsigned char *word,
	    int len_word, int *num_attempts)
{
    unsigned char character;
    int is_in_word = 0;
    int clean_buffer;

    // Esta línea la uso para limpiar el buffer
    while ((clean_buffer = getchar()) != '\n' && clean_buffer != EOF);

    printf("Digite una letra: ");
    character = getchar();

    for (int i = 0; i < len_word; i++)
    {
	if (*(word + i) == character)
	{
	    *(board + i) = character;
	    is_in_word = 1;
	}
    }

    if (!is_in_word)
	(*num_attempts)--;
}
