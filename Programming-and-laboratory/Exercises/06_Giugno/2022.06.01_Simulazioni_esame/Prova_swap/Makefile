swap: main.o funzioniSwap.o
	gcc -g -o swap main.o funzioniSwap.o

main.o: main.c funzioniSwap.h
	gcc -g -c main.c

funzioniSwap.o: funzioniSwap.c funzioniSwap.h
	gcc -g -c funzioniSwap.c