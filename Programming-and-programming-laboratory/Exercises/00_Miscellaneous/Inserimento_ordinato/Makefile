esercizioInserimentoOrdinato: main.o selectionSort.o insertionSort.o swap.o
	gcc -g -o esercizioInserimentoOrdinato main.o selectionSort.o insertionSort.o swap.o

main.o: main.c selectionSort.h insertionSort.h swap.h
	gcc -g -c main.c

selectionSort.o: selectionSort.c swap.h
	gcc -g -c selectionSort.c

insertionSort.o: insertionSort.c
	gcc -g -c insertionSort.c