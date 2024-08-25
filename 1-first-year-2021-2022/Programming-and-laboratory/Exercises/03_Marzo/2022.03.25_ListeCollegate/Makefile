LinkedLists: main.o LinkedListsFunctions.o
	gcc -g -o LinkedLists main.o LinkedListsFunctions.o

main.o: main.c LinkedListsFunctions.h
	gcc -g -c main.c

LinkedListsFunctions.o: LinkedListsFunctions.c LinkedListsFunctions.h
	gcc -g -c LinkedListsFunctions.c