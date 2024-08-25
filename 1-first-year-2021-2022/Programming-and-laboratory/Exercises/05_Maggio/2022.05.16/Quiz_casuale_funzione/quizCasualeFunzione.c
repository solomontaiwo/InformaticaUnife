#include <stdio.h>
#include <string.h>

char risposta()
{
    char risposta[50];
    char rispostaGiusta[] = "Azzurro";
    int numeroVite = 3;

    while (numeroVite > 0)
    {
        printf("\nDi quale colore e' il cielo?\n\n? ");
        scanf("%s", risposta);

        if ((strcmp(risposta, rispostaGiusta)) == 0)
        {
            printf("\nRisposta corretta!\n\n");
            break;
        }
        else
        {
            printf("\nRisposta sbagliata!\n");
            numeroVite--;
            printf("\nVite rimanenti: %d\n", numeroVite);
        }
    }
    if (numeroVite == 0)
        printf("\nHai risposto erratamente troppe volte! Ritenta, sarai piu' fortunato.\n\n");
}