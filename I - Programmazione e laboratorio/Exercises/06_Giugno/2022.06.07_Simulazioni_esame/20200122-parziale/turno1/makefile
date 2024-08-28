fatture: main.o listaVeicoli.o
	gcc -g -o fatture main.o listaVeicoli.o

main.o: main.c listaVeicoli.h
	gcc -g -c main.c

listaVeicoli.o: listaVeicoli.c listaVeicoli.h
	gcc -g -c listaVeicoli.c