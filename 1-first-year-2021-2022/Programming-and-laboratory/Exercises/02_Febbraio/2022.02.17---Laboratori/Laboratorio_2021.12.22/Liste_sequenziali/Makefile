ripasso_liste_sequenziali: main.o liste_sequenziali_prototipi.o
	gcc -g -o ripasso_liste_sequenziali main.o liste_sequenziali_prototipi.o

main.o: main.c liste_sequenziali_prototipi.h
	gcc -g -c main.c

liste_sequenziali_prototipi.o: liste_sequenziali_prototipi.c liste_sequenziali_prototipi.h
	gcc -g -c liste_sequenziali_prototipi.c