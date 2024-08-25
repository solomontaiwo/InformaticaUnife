#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaUtenti.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Errore, argomento non valido o non inserito.\n");
        exit(1);
    }

    FILE *pfb, *pft;
    Record r;
    Lista l;
    Chiamata c;

    if ((pfb = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile leggere file binario %s.\n", argv[1]);
        exit(2);
    }

    if ((pft = fopen(argv[2], "rt")) == NULL)
    {
        printf("Impossibile leggere file di testo %s.\n", argv[2]);
        exit(3);
    }

    nuovaLista(&l);

    while ((fread(&r, sizeof(Record), 1, pfb)) == 1)
    {
        aggiornaLista(&l, r);
    }

   /*  while (l != NULL)
    {
        while ((fscanf(pft, "%s %d", c.numero, &c.durata)) != EOF)
        {
            if ((strcmp(l->d.numero, c.numero)) == 0)
            {
                if (l->d.piano == 'A')
                    l->d.residuo -= 0.31 * c.durata;
                else
                    l->d.residuo -= 0.15 * c.durata;
            }
        }
        l = l->next;
    }
    */

    fclose(pfb);
    fclose(pft);

    stampaLista(l);

    return 0;
}