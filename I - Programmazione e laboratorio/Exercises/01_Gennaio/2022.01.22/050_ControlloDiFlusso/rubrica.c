/* Scrivere un programma che simuli la scelta del numero da chiamare in una rubrica
telefonica. In particolare, il programma deve
1 stampare l’elenco dei contatti, ognuno preceduto da un identificativo intero
progressivo
2 richiedere all’utente l’identificativo del contatto da chiamare
3 stampare un messaggio che indichi che la chiamata al contatto selezionato è in
corso.
*/

#include <stdio.h>

int main()
{
    int contattoSolomon = 1, contattoRachele = 2, contattoErmenegildo = 3, contattoMarco = 4;
    int scelta;

    puts("Inserisci l'identificatico del contatto da chiamare.");

    puts("");

    puts("1. Solomon: 123-456789");
    puts("2. Rachele: 987-654321");
    puts("3. Ermenegildo: 456-789123");
    puts("4. Marco: 789-123456");

    puts("");

    scanf("%d", &scelta);

    puts("");

    if (scelta == 1)
    {
        printf("Chiamata di Solomon al 123-456789 in corso...\n");
    }
    else
    {
        if (scelta == 2)
        {
            printf("Chiamata di Rachele al 987-654321 in corso...\n");
        }
        else
        {
            if (scelta == 3)
            {
                printf("Chiamata di Ermenegildo al 456-789123 in corso...\n");
            }
            else
            {
                if (scelta == 4)
                {
                    printf("Chiamata di Marco al 789-123456 in corso...\n");
                }
                else
                {
                    printf("Hai inserito un numero non associato ad alcun contatto.\n");
                }
            }
        }
    }
}