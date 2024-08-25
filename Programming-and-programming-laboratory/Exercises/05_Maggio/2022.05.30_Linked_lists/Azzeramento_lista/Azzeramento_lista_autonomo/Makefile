azzeramento: main.o azzeramento.o
	gcc -g -o azzeramento main.o azzeramento.o

main.o: main.c azzeramento.h
	gcc -g -c main.c

azzeramento.o: azzeramento.c azzeramento.h
	gcc -g -c azzeramento.c