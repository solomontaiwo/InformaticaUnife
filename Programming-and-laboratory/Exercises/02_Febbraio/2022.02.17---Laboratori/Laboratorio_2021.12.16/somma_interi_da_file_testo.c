#include <stdio.h>
#include <stdlib.h>

int somma_da_file(FILE *pf)
{
    int numero = 0;
    int somma = 0;
    while (fscanf(pf, "%d", &numero) == 1)
        somma += numero;
    return somma;
}

int main(int argc, char *argv[])
{
    FILE *pft;
    int s;

    if ((pft = fopen("interi.txt", "rt")) == NULL)
    {
        printf("Impossibile aprire il file.\n");
        exit(1);
    }

    s = somma_da_file(pft);

    fclose(pft);

    printf("Somma: %d\n", s);
}