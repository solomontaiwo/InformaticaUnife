/* Scrivere su un file di caratteri testo.txt una sequenza di caratteri. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char messaggio[] = {"Questa e' una prova!"};
    FILE *fcaratteri;

    if ((fcaratteri = fopen("testo.txt", "wb")) == NULL)
    {
        perror("Impossibile aprire il file.\n");
        exit(1);
    }
    else
    {
        fwrite(messaggio, strlen(messaggio) + 1, 1, fcaratteri);
    }
}