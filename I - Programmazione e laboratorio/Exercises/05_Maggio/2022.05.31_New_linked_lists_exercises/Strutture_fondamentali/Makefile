struttureListeCollegate: main.o struttureListeCollegate.o
	gcc -g -o struttureListeCollegate main.o struttureListeCollegate.o

main.o: main.c struttureListeCollegate.h
	gcc -g -c main.c

struttureListeCollegate.o: struttureListeCollegate.c struttureListeCollegate.h
	gcc -g -c struttureListeCollegate.c