insertionSort: main.o insertionSort.o
	gcc -g -o insertionSort main.o insertionSort.o

main.o: main.c insertionSort.h
	gcc -g -c main.c

insertionSort.o: insertionSort.c insertionSort.h
	gcc -g -c insertionSort.c