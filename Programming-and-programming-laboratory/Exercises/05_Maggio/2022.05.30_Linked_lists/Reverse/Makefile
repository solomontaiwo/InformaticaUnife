reverse: main.o reverse.o
	gcc -g -o reverse main.o reverse.o

main.o: main.c reverse.h
	gcc -g -c main.c

reverse.o: reverse.c reverse.h
	gcc -g -c reverse.c