// esercizio casuale in cui l'utente immette dei caratteri
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[20];
    int eta;
    float maturita; // numero con virgola per poter chiedere all'utente un float

    printf("Inserisci il tuo nome: ");
    scanf("%s", nome);

    printf("Inserisci la tua eta': ");
    scanf("%d", &eta);

    printf("Con quanto sei uscito alle superiori? ");
    scanf("%f", &maturita);

    printf("Da quello che mi hai detto, ti chiami %s, hai %d anni ed hai terminato gli studi di scuola secondaria di secondo grando con %.2f.\n", nome, eta, maturita);
}