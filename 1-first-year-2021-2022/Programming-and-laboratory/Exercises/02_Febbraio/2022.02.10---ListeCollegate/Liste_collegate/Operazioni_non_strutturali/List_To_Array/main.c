/* Scrivere una funzione che, ricevuta come parametro una lista di interi, restituisca l’indirizzo di un vettore, allocato dinamicamente, contenente tutti gli elementi della
lista.
*/

#include <stdio.h>
#include "funzListe.h"

int main(int argc, char *argv[])
{

    Lista oibo;

    int *p, i, n;

    generaListaNonOrdinata(&oibo, 5);

    p = listToArray(oibo);

    n = lunghezza(oibo);

    for (i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }
    puts("");
    return 0;
}