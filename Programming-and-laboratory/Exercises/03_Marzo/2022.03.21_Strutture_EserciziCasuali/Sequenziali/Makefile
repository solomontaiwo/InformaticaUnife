sequenziali: main.o listeSequenzialiMarzoAutonomo.o
	gcc -g -o sequenziali main.o listeSequenzialiMarzoAutonomo.o

main.o: main.c listeSequenzialiMarzoAutonomo.h
	gcc -g -c main.c

listeSequenzialiMarzoAutonomo.o: listeSequenzialiMarzoAutonomo.c listeSequenzialiMarzoAutonomo.h
	gcc -g -c listeSequenzialiMarzoAutonomo.c