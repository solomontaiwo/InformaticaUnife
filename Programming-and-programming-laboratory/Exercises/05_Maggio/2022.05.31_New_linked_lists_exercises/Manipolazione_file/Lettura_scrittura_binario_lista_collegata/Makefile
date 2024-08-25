scritturaBinario: main.o scritturaBinario.o
	gcc -g -o scritturaBinario main.o scritturaBinario.o

main.o: main.c scritturaBinario.h
	gcc -g -c main.c

scritturaBinario.o: scritturaBinario.c scritturaBinario.h
	gcc -g -c scritturaBinario.c