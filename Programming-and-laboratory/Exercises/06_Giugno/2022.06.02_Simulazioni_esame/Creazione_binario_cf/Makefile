creazioneBinarioCF: main.o funzioniCreazioneBinarioCF.o
	gcc -g -o creazioneBinarioCF main.o funzioniCreazioneBinarioCF.o

main.o: main.c funzioniCreazioneBinarioCF.h
	gcc -g -c main.c

funzioniCreazioneBinarioCF.o: funzioniCreazioneBinarioCF.c funzioniCreazioneBinarioCF.h
	gcc -g -c funzioniCreazioneBinarioCF.c