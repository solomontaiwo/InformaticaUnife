programmaListeCollegate: main.o programmaListeCollegate.o
	gcc -g -o programmaListeCollegate main.c programmaListeCollegate.c

main.o: main.c programmaListeCollegate.h
	gcc -g -c main.c

programmaListeCollegate.o: programmaListeCollegate.c
	gcc -g -c programmaListeCollegate.c