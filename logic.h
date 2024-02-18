#ifndef LOGIC
#define LOGIC

#define ATTEMPTS 8

void start_game();
void draw_board(unsigned char board[], int len_word);
void check_board(unsigned char board[], unsigned char *word, 
		 int len_word, int *num_attempts);

#endif // LOGIC
