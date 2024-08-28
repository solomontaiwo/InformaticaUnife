algos_comparison: main.o Algorithms.o 
	gcc -g -o algos-comparison main.o Algorithms.o

main.o: main.c Algorithms.h
	gcc -g -c main.c

Algorithms.o: Algorithms.c
	gcc -g -c Algorithms.c