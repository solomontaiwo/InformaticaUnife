#include <malloc.h>
#include "listeCollegatePrototipi.h"

void elimTesta(Lista *pl)
{
    Nodo *aux = *pl;
    *pl = (*pl)->next;
    free(aux);
}