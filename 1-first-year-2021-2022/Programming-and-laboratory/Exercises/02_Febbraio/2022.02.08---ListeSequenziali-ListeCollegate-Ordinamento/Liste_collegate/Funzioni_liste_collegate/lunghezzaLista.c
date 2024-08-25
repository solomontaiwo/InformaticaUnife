// Scrivere una funzione che restituisca la lunghezza (cioe' il numero di elementi) di un lista collegata intera//
#include <stdio.h>
#include "listaCollegata.h"

int lunghezza(Lista l)
{
    int c = 0;
    while (l)
    {
        c++;
        l = l->next;
    }
    return c;
}