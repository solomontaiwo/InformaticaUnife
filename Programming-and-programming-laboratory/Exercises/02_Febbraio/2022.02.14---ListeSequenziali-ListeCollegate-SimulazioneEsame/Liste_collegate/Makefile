tengenListeCollegate: main.o dichiarazioniListeCollegate.o
	gcc -g -o tengenListeCollegate main.o dichiarazioniListeCollegate.o

main.o: main.c dichiarazioniListeCollegate.h
	gcc -g -c main.c

dichiarazioniListeCollegate.o: dichiarazioniListeCollegate.c
	gcc -g -c dichiarazioniListeCollegate.c