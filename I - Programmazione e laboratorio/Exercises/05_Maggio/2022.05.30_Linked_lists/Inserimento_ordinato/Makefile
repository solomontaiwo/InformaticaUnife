ordinato: main.o ordinato.o
	gcc -g -o ordinato main.o ordinato.o

main.o: main.c ordinato.h
	gcc -g -c main.c

ordinato.o: ordinato.c ordinato.h
	gcc -g -c ordinato.c