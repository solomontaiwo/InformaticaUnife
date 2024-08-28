#include "listaCollegata.h"

Lista *ricerca(Lista *pl, Dato d)
{
    while (*pl)
    {
        if ((*pl)->dato == d)
        {
            break;
        }
        else
            pl = &(*pl)->next;
    }
    return pl;
}