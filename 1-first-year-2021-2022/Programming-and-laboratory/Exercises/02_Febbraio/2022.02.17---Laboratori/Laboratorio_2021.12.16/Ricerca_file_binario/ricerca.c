#include "ricerca.h"

void ricerca(FILE *pf, int numero)
{
    int contatore = 0;
    int trovato;
    while ((fread(&trovato, sizeof(int), 1, pf)) == 1)
    {
        if (trovato == numero)
        {
            printf("Il valore e' stato trovato.\n");
            return;
        }
    }
    printf("Non trovato.\n");
}