#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int vite = 3;
    char nome[10];
    char risposta[10], rispostaUtente[10];
    int rispostaNumero, rispostaNumeroUtente = 0;

    printf("Inserisci il tuo nome: %s", nome);
    scanf("%s", nome);

    printf("\nBenvenuto al quiz dei quiz, %s! Hai tre vite, rispondi correttamente alle seguenti due domande per vincere.\n", nome);

    puts("\n**PRIMA DOMANDA**\n");

    rispostaNumero = 45;

    printf("Quanto fa 5x9?\n? ");
    scanf("%d", &rispostaNumeroUtente);

    while (rispostaNumero != rispostaNumeroUtente)
    {
        vite--;
        if (vite > 0)
        {
            printf("Risposta sbagliata! Vite rimaste: %d\n", vite);
            printf("Quanto fa 5x9?\n? ");
            scanf("%d", &rispostaNumeroUtente);
        }
        else
        {
            vite = 0;
            printf("Le tue vite sono pari a %d: gioco termminato.\n");
            exit(1);
        }
    }

    puts("\nSECONDA DOMANDA\n");

    strncpy(risposta, "Vero", 10);
    printf("Il Sole e' piu' grande della Luna. Vero o falso?\n? ");
    scanf("%s", rispostaUtente);

    while ((strcmp(rispostaUtente, risposta)) != 0)
    {
        vite--;
        if (vite > 0)
        {
            printf("Risposta sbagliata! Vite rimaste: %d\n", vite);
            printf("Il Sole e' piu' grande della Luna. Vero o falso?\n? ");
            scanf("%s", risposta);
        }
        else
        {
            vite = 0;
            printf("Le tue vite sono pari a %d: gioco termminato.\n");
            exit(2);
        }
    }

    printf("Complimenti %s, hai vinto il quiz veloce made by Solomon Taiwo!\n", nome);
}