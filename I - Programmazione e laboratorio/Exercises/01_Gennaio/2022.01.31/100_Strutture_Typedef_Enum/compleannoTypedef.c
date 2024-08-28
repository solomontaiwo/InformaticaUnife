/* • Si modifichi il programma dell’esercizio precedente (compleanno) definendo i tipi tramite la typedef.
• Inoltre, l’utente dovrà inserire il nome del mese, invece del numero
*/
#include <stdio.h>

int main(void)
{
    typedef struct
    {
        int giorno, anno;
        char mese[15];
    } data;

    typedef struct
    {
        char nome[10];
        int giorno, anno;
        char mese[15];
    } persona;

    data oggi;
    persona pincopallino;

    printf("Inserisci la data di oggi: ");
    scanf("%d %s %d", &oggi.giorno, oggi.mese, &oggi.anno);

    printf("Inserisci il tuo nome: ");
    scanf("%s", pincopallino.nome);

    printf("Inserisci la tua data di nascita: ");
    scanf("%d %s %d", &pincopallino.giorno, pincopallino.mese, &pincopallino.anno);

    if (pincopallino.giorno == oggi.giorno && pincopallino.mese == oggi.mese)
        printf("Auguri %s, oggi e' il tuo compleanno!\n", pincopallino.nome);
    else
        printf("Oggi non e' il tuo compleanno, mi dispiace %s.\n", pincopallino.nome);
}