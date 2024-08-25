libretto: main.o listaEsami.o
	gcc -g -o libretto main.o listaEsami.o

main.o: main.c listaEsami.h
	gcc -g -c main.c

listaEsami.o: listaEsami.c listaEsami.h
	gcc -g -c listaEsami.c