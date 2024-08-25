#include <stdio.h>
#include <stdlib.h>

#include "listaImmobili.h"

int main(int argc, char *argv[])
{
    Immobile imm;
    Lista l;
    FILE *f;
    int nVaniMin;

    if (argc != 2)
    {
        printf("Uso: %s nomeFile\n", argv[0]);
        exit(-1);
    }

    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile aprire %s\n", argv[1]);
        exit(-2);
    }

    nuovaLista(&l);
    // inserisce ogni record del file nella lista ordinata
    // per distanza dal centro crescente
    while (fread(&imm, sizeof(Immobile), 1, f) == 1)
        insOrd(&l, imm);
    fclose(f);

    stampa(l, stdout);

    // printf("Numero minimo di vani?\n");
    scanf("%d", &nVaniMin);
    if ((f = fopen("vani.txt", "wt")) == NULL)
    {
        printf("Impossibile aprire 'vani.txt'\n");
        exit(-2);
    }
    // stampa su file la lista filtrata e ordinata come specificato
    stampa(filtra(l, nVaniMin), f);
    fclose(f);
    return 0;
}