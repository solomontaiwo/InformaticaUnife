#include <stdio.h>
#include "listaCollegata.h"

// nelle liste collegate, il ciclo ForEach e' sostituito da while perche' non e' possibile accedere all'elemento alla i-esima //

void stampa(Lista l)
{
    while (l != NULL)
    {
        printf("%d ", l->dato);
        l = l->next;
    }
    puts("");
}