prog: main.o file1.o file2.o file3.o
	gcc -g -o prog main.o file1.o file2.o file3.o

main.o: main.c file1.h file2.h
	gcc -g -c main.c

file1.o: file1.c file3.h	
	gcc -g -c file1.c

file2.o: file2.c file3.h
	gcc -g -c file2.c

file3.o: file3.c
	gcc -g -c file3.c