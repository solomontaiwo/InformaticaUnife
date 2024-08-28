listeCollegateAutonome: main.o funzioniListeCollegate.o
	gcc -g -o listeCollegateAutonome main.o funzioniListeCollegate.o

main.o: main.c funzioniListeCollegate.h
	gcc -g -c main.c 

funzioniListeCollegate.o: funzioniListeCollegate.c funzioniListeCollegate.h
	gcc -g -c funzioniListeCollegate.c