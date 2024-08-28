// Questo programma stampa sulla stessa riga i numeri da 1 a 4

#include <stdio.h>

int main(void)

{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;

    printf("1, 2, 3, 4.\n"); // metodo 1  - senza specificatori di conversione

    printf("%d, %d, %d, %d.\n", a, b, c, d); // metodo 2 - con specificatori di conversione

    printf("1, ");
    printf("2, ");
    printf("3, ");
    printf("4.\n"); // metodo 3 - quattro istruzioni printf
}