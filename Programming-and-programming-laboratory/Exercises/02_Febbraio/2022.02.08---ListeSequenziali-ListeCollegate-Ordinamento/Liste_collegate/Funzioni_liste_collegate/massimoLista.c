// Scrivere una funzione che restituisca l'elemento massimo di una lista di interi. //
#include <stdio.h>
#include "listaCollegata.h"

int massimoLista(Lista l)
{
    int m = 0;
    while (l)
    {
        if (l->dato > m)
        {
            m = l->dato;
            l = l->next;
        }
        else
        {
            l = l->next;
        }
    }
    return m;
}