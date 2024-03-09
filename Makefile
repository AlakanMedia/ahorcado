CC = gcc

all: ahorcado

ahorcado: main.o logic.o stack.o
	$(CC) $^ -o $@

main.o: main.c logic.h
	$(CC) -c main.c

logic.o: logic.c logic.h stack.h
	$(CC) -c logic.c

stack.o: stack.c stack.h letter.h
	$(CC) -c stack.c

clean:
	rm -rf *.o ahorcado
