#include <stdio.h>
#include <stdlib.h>

int somma_da_file(FILE *pf) // funzione ricorsiva
{
    int numero;
    if (fscanf(pf, "%d", &numero) == 1)
        return numero + somma_da_file(pf);
    else
        return 0;
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