insertionSort_mergeSort_hybridSort: main.o insertionSort_mergeSort_hybridSort.o
	gcc -g -o insertionSort_mergeSort_hybridSort main.o insertionSort_mergeSort_hybridSort.o

main.o: main.c insertionSort_mergeSort_hybridSort.h
	gcc -g -c main.c

insertionSort_mergeSort_hybridSort.o: insertionSort_mergeSort_hybridSort.c insertionSort_mergeSort_hybridSort.h
	gcc -g -c insertionSort_mergeSort_hybridSort.c