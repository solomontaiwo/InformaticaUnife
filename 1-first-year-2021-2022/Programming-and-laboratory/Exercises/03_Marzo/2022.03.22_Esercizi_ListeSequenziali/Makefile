listeSequenziali: main.o listeSequenziali.o
	gcc -g -o listeSequenziali main.o listeSequenziali.o

main.o: main.c listeSequenziali.h
	gcc -g -c main.c

listeSequenziali.o: listeSequenziali.c listeSequenziali.h
	gcc -g -c listeSequenziali.c