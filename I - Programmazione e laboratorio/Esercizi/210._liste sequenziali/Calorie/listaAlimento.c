#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaAlimento.h"

void caricaCalorie(char nomeFileBinario[], Lista *pl)
{
    int numero;
    FILE *fb;
    fb = fopen(nomeFileBinario, "rb");
    if (fb == NULL)
    {
        printf("Impossibile aprire %s\n", nomeFileBinario);
        exit(3);
    }
    pl->n_elementi = fread(pl->dati, sizeof(Alimento), DIMENSIONE, fb);

    fclose(fb);
    return numero;
}

float calorieAlimento(char nomeAlimento[], Lista l)
{
    int i;
    for (i = 0; i < l.n_elementi; i++)
        if (strcmp(nomeAlimento, l.dati[i].nome) == 0)
            return l.dati[i].calorie;
    printf("Alimento non trovato\n");
    exit(4);
}