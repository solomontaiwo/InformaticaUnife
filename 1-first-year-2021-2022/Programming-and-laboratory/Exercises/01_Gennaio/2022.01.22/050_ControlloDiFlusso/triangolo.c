/* Scrivere un programma che richieda all’utente i tre lati di un triangolo e scriva se il triangolo è rettangolo oppure no.
Triangolo rettangolo = a^2 + b^2 = c^2
*/

#include <stdio.h>

int main()
{
    int lato1, lato2, lato3;

    printf("Inserisci i tre lati di un triangolo, ti diro' se e' rettangolo oppure no: ");
    scanf("%d %d %d", &lato1, &lato2, &lato3);

    if ((lato1 * lato1) + (lato2 * lato2) == (lato3 * lato3))
    {
        printf("Il triangolo creato dai lati %d, %d e %d che mi hai fornito e' rettangolo.\n", lato1, lato2, lato3);
    }
    else
    {
        printf("Il triangolo dato da %d, %d e %d non e' rettangolo.\n", lato1, lato2, lato3);
    }
}