#include <stdio.h>
#include "logic.h"

int
main()
{
    int option_selected;

    do
    {
	printf("El juego del ahorcado\n\n");

	printf("1 - Empezar a jugar\n");
	printf("2 - Salir del juego\n");

	printf("\nElija una opción: ");

	scanf("%d", &option_selected);

	if (option_selected == 1)
	    start_game();
    }
    while (option_selected != 2);

    return 0; 
}
