programmaSelectionSort: main.o selectionSort.o swap.o
	gcc -g -o programmaSelectionSort main.o selectionSort.o swap.o

main.o: main.c selectionSort.h
	gcc -g -c main.c

selectionSort.o: selectionSort.c swap.h
	gcc -g -c selectionSort.c

swap.o: swap.c
	gcc -g -c swap.c
