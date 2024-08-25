listeCollegateAutonomia: main.o funzioniListeCollegateAutonomia.o
	gcc -g -o listeCollegateAutonomia main.o funzioniListeCollegateAutonomia.o

main.o: main.c funzioniListeCollegateAutonomia.h
	gcc -g -c main.c

funzioniListeCollegateAutonomia.o: funzioniListeCollegateAutonomia.c funzioniListeCollegateAutonomia.h
	gcc -g -c funzioniListeCollegateAutonomia.c