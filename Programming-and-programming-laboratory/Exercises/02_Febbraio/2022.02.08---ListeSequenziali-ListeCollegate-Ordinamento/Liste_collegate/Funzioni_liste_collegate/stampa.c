#include <stdlib.h>
#include "listaCollegata.h"

void stampa(Lista l)
{
    while (l) {
        printf("%d ", l->dato);
        l = l->next;
    }
    puts("");
}