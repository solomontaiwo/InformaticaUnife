/* • Si legga da tastiera una struttura costituita da 3 campi interi contenente la data di oggi
• Si legga una struttura contenente il nome di una persona e la sua data di nascita
• Se oggi è il compleanno della persona, si stampi "Auguri" seguito dal nome della persona
*/
#include <stdio.h>

int main(void)
{
    struct data
    {
        int giorno, mese, anno;
    } oggi;

    struct persona
    {
        char nome[10];
        int giorno, mese, anno;
    } pincopallino;

    printf("Inserisci la data di oggi: ");
    scanf("%d %d %d", &oggi.giorno, &oggi.mese, &oggi.anno);

    printf("Inserisci il tuo nome: ");
    scanf("%s", pincopallino.nome);

    printf("Inserisci la tua data di nascita: ");
    scanf("%d %d %d", &pincopallino.giorno, &pincopallino.mese, &pincopallino.anno);

    if (pincopallino.giorno == oggi.giorno && pincopallino.mese == oggi.mese)
        printf("Auguri %s, oggi e' il tuo compleanno!\n", pincopallino.nome);
    else
        printf("Oggi non e' il tuo compleanno, mi dispiace %s.\n", pincopallino.nome);
}