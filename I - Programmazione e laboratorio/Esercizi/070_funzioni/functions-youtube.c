#include <stdio.h>

void saluto(char nome[], int eta) { printf("Ciao %s, so che hai %d, sbaglio?\n", nome, eta); }

int main(void)
{
    saluto("Marco", 49);
    saluto("Pino", 22);
    saluto("Ermenegildo", 26);
}