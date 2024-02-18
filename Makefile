all: program

program: main.o logic.o stack.o
	gcc -o ahorcado main.o logic.o stack.o

main.o: main.c stack.h
	gcc -c main.c

logic.o: logic.c logic.h
	gcc -c logic.c

stack.o: stack.c stack.h letter.h
	gcc -c stack.c

clean:
	rm -f *.o ahorcado
