#include <stdio.h>

// funzioni in completa autonomia

void datiPersonaggio(char nome[], int eta) { printf("%s ha %d anni.\n", nome, eta); }

int main(void)
{

    datiPersonaggio("Solomon", 25);
    datiPersonaggio("Franco", 55);
    datiPersonaggio("Claudio", 42);
}