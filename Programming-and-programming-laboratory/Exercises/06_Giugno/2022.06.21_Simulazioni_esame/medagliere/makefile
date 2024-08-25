medagliere: main.o listaNazioni.o
	gcc -g -o medagliere main.o listaNazioni.o

main.o: listaNazioni.h main.c
	gcc -g -c main.c

listaNazioni.o: listaNazioni.c listaNazioni.h
	gcc -g -c listaNazioni.c