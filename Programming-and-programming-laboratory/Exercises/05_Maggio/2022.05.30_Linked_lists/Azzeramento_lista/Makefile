azzeramentoLista: main.o generatoreListe.o
	gcc -g -o azzeramentoLista main.o generatoreListe.o

main.o: main.c generatoreListe.h
	gcc -g -c main.c

generatoreListe.o: generatoreListe.c generatoreListe.h
	gcc -g -c generatoreListe.c