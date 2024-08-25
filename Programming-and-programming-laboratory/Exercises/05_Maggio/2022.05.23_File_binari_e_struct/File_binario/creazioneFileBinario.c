#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *pfb;
    char parola[10];

    if ((pfb = fopen("fileBinario", "wb")) == NULL)
    {
        printf("Impossibile creare il file binario.\n");
        exit(1);
    }

    printf("Inserisci la parola che vuoi scrivere nel file binario: ");
    scanf("%s", parola);
    fwrite(parola, 1, sizeof(parola), pfb);

    fclose(pfb);
}