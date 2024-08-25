/*  Scrivere un programma che richieda all’utente un intero e scriva
compreso se il numero è compreso fra 2 e 5;
non compreso altrimenti. 
*/

#include <stdio.h>

int main()
{
    int valore;

    printf("Inserisci un valore compreso fra 2 e 5: ");
    scanf("%d", &valore);

    if (valore <= 5 && valore >= 2)
    {
        printf("Il numero da te inserito (%d) e' compreso fra 2 e 5.\n", valore);
    }
    else
    {
        printf("Il valore %d non e' compreso fra 2 e 5.\n", valore);
    }
    
}