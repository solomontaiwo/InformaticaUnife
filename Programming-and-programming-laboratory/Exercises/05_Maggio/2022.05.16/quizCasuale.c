#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    char risposta[50];
    char rispostaGiusta[] = "Azzurro";
    int numeroVite = 3;

    printf("**QUIZ**\n");
    printf("\nIstruzioni: se rispondi correttamente alla domanda, vinci un premio!\n");

    while (numeroVite > 0)
    {
        printf("\nDi quale colore e' il cielo?\n? ");
        scanf("%s", risposta);

        if (strcmp(risposta, rispostaGiusta) == 0)
        {
            printf("\nRisposta corretta!\n\n");
            break;
        }
        else
        {
            printf("\nRisposta sbagliata!\n\n");
            numeroVite--;
        }
    }

    if (numeroVite == 0)
        printf("\nHai sbagliato troppe volte! Ritenta, sarai più fortunato.\n\n");
}