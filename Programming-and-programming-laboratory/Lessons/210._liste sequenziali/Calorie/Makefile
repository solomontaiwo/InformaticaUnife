calcolo-calorie-pasto: main.o listaAlimento.o
	gcc -g -o calcolo-calorie-pasto main.o listaAlimento.o

main.o: main.c listaAlimento.h
	gcc -g -c main.c

funzioniCalorie.o: funzioniCalorie.c listaAlimento.h
	gcc -g -c funzioniCalorie.c