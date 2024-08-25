#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo
{
    int valore;
    struct nodo *next;
};

main(int argc, char *argv[])
{
    srand(time(NULL));
    struct nodo *testa;

    testa = (struct nodo *)malloc(sizeof(struct nodo));
    testa->next = NULL;
    testa->valore = 5;

    int dimensioni = 6 + rand() % (10 - 6 + 1);
    struct nodo *corrente = testa;

    while (dimensioni-- > 0)
    {
        corrente->next = (struct nodo *)malloc(sizeof(struct nodo));
        corrente = corrente->next;
        corrente->valore = 1 + rand() % (20 - 1 + 1);
        corrente->next = NULL;
    }

    corrente = testa;
    int i;
    for (i = 0; corrente; corrente = corrente->next)
        printf("Il nodo %d contiene un valore di %d\n", i++, corrente->valore);

    free(corrente);
}