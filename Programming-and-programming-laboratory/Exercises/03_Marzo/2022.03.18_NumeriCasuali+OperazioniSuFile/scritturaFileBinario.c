#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *binario;
    int *numero, *numeroLetto;

    if ((binario = fopen("fileBinario.dat", "wb")) == NULL)
    {
        printf("Impossibile creare o scrivere sul file binario richiesto.\n");
        exit(1);
    }

    printf("Inserisci un numero qualsiasi, la scrivero' nel file binario e poi te la riportero':\n");
    scanf("%d", &numero);
    printf("Valore inserito: %d\n", numero);

    fwrite(&numero, sizeof(int), 1, binario);

    fclose(binario);

    if ((binario = fopen("fileBinario.dat", "rb")) == NULL)
    {
        printf("Impossibile aprire il file binario richiesto.\n");
        exit(2);
    }

    fread(&numeroLetto, sizeof(int), 1, binario);

    printf("Questa e' il numero contenuto all'interno del file binario: %d\n", numeroLetto);

    fclose(binario);

    return 0;
}