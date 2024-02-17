all: program

program: main.o stack.o
	gcc -o ahorcado main.o stack.o

main.o: main.c stack.h
	gcc -c main.c

stack.o: stack.c stack.h letter.h
	gcc -c stack.c

clean:
	rm -f *.o ahorcado
