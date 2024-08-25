swap: main.o swap.o
	gcc -g -o swap main.o swap.o

main.o: main.c swap.h
	gcc -g -c main.c

swap.o: swap.c swap.h
	gcc -g -c swap.c