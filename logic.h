#ifndef LOGIC
#define LOGIC

#include "stack.h"

#define ATTEMPTS 8

void start_game();
void draw_board(unsigned char board[], int len_word);
void draw_hangman(int num_attempts);
void check_board(stack *the_stack, unsigned char board[], unsigned char *word, 
		 int len_word, int *num_attempts);
void finish_game(stack *the_stack, int num_attempts, 
		 unsigned char *word_selected);
int is_over(int num_attempts);
int is_victory(unsigned char board[], int len_word);

#endif // LOGIC
