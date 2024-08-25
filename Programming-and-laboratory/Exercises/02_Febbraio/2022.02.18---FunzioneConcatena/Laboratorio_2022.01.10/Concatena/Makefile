concatena: main.o funzioniConcatena.o
	gcc -g -o concatena main.o funzioniConcatena.o

main.o: main.c funzioniConcatena.h
	gcc -g -c main.c

funzioniConcatena.o: funzioniConcatena.c
	gcc -g -c funzioniConcatena.c