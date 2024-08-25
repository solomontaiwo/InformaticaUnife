medagliere: main.o listaNazioni.o
	gcc -g -o medagliere main.o listaNazioni.o

main.o: main.c listaNazioni.h
	gcc -g -c main.c

listaNazioni.o: listaNazioni.c listaNazioni.h
	gcc -g -c listaNazioni.c