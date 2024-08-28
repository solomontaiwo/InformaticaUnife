Quadrato: main.o funzioneAlQuadrato.o
	gcc -g -o Quadrato main.o funzioneAlQuadrato.o

main.o: main.c funzioneAlQuadrato.h
	gcc -g -c main.c

funzioneAlQuadrato.o: funzioneAlQuadrato.c funzioneAlQuadrato.h
	gcc -g -c funzioneAlQuadrato.c