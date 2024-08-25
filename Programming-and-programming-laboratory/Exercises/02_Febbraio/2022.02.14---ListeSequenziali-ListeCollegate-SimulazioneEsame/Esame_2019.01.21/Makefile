immobili: main.o listaImmobili.o
	gcc -g -o immobili main.o listaImmobili.o

listaImmobili.o: listaImmobili.c
	gcc -g -c listaImmobili.c

main.o: main.c listaImmobili.h
	gcc -g -c main.c