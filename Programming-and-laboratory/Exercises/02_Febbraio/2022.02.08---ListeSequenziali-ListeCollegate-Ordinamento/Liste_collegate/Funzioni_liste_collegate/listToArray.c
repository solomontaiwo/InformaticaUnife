#include <stdio.h>
#include "listaCollegata.h"

int *listToArray(Lista l)
{
    int *p, i;
    int n = lunghezza(l);
    p = (int *)malloc(sizeof(int) * n);

    i = 0;

    while (l)
    {
        p[i] = l->dato;
        i++;
        l = l->next;
    }
    return p;
}