lista-ordinata: main.o lista.o
	gcc -g -o lista-ordinata main.o lista.o

main.o: main.c lista.h
	gcc -g -c main.c

lista.o: lista.c lista.h
	gcc -g -c lista.c

// NOTA BENE 1: con l'opzione -c si compila il file per ottenere, dal sorgente, un file .o che non e' passato per il linking
// NOTA BENE 2: con l'opzione -o rinomino l'output del gcc!