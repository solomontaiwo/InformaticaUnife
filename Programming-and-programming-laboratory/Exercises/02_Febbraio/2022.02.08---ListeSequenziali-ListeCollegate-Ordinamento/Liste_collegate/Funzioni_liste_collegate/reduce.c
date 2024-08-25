// Questa funzione calcola la somma degli elementi di una lista. //
#include <stdio.h>
#include "listaCollegata.h"

int somma(Lista l)
{
    int s = 0; // accumulatore //
    while (l)
    {
        s += l->dato;
        l = l->next;
    }
    return s;
}