pazienti: main.o listaPazienti.o
	gcc -g -o pazienti main.o listaPazienti.o

main.o: main.c listaPazienti.h
	gcc -g -c main.c

listaPazienti.o: listaPazienti.c listaPazienti.h
	gcc -g -c listaPazienti.c