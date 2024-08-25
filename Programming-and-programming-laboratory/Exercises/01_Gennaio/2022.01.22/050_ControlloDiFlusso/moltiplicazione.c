// Stampare il prodotto di due numeri m e n richiesti all’utente, calcolandolo come somma di n addendi pari a m. //
#include <stdio.h>

int main()
{

    int m, n, somma = 0;

    printf("Inserisci due valori: faro' qualche magheggio e ne vedrai il risultato finale.\n");
    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++)
    {
        somma += m;
    }
    printf("Risultato: %d.\n", somma);
}