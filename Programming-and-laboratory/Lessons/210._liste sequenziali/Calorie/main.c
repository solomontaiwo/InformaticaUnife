#include <stdio.h>
#include <stdlib.h>

#include "listaAlimento.h"

int main(int argc, char *argv[])
{
    char nome[31];
    float quantita;
    Lista l;
    float calorieTotali;

    FILE *ft;
    if (argc != 3)
    {
        printf("Uso: %s fileCalorie filePasto\n", argv[0]);
        exit(1);
    }

    caricaCalorie(argv[1], &l);

    if ((ft = fopen(argv[2], "rt")) == NULL)
    {
        printf("Errore apertura file %s", argv[2]);
        exit(2);
    }

    calorieTotali = 0.0;
    while (fscanf(ft, "%s%f", nome, &quantita) == 2)
    {
        float calorie100 = calorieAlimento(nome, l);
        float calorieConsumate = calorie100 * quantita;
        calorieTotali += calorieConsumate;
    }

    fclose(ft);
}