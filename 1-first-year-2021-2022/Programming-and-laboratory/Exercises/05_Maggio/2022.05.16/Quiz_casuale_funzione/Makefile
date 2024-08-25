quizCasualeFunzione: main.o quizCasualeFunzione.o
	gcc -g -o quizCasualeFunzione main.o quizCasualeFunzione.o

main.o: main.c quizCasualeFunzione.h
	gcc -g -c main.c

quizCasualeFunzione.o: quizCasualeFunzione.c quizCasualeFunzione.h
	gcc -g -c quizCasualeFunzione.c