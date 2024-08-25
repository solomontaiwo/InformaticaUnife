// Programma che registra dati socio palestra: numero tessera socio, nome, cognome, data iscrizione e scadenza tessera ed infine prezzo del rinnovo
#include <stdio.h>

int main(void)
{
    FILE *sociPtr;

    if ((sociPtr = fopen("Dati soci palestra.txt", "w")) == NULL)
    {
        puts("Il file non esiste, si invita a crearlo manualmente.");
    }
    else
    {
        puts("L'utente e' pregato di inserire i seguenti dati relativi ai soci della palestra VATTELAPPESCA: numero tessera socio, nome utente, data di iscrizione, prezzo rinnovo iscrizione.");
        puts("Per uscire dal programma digita EXIT (tutto maiuscolo) oppure utilizza la combinazione di termine del tuo sistema operativo (ctrl+z per Windows, ctrz+d per Linux)");
        printf("%s", "? - ");

        unsigned int numeroTessera;
        char nome[20];

        unsigned int giorno, mese, anno;

        float costoIscrizione;

        scanf("%5d %19s %d/%d/%d %f", &numeroTessera, nome, &giorno, &mese, &anno, &costoIscrizione);

        while (!feof(stdin))
        {
            fprintf(sociPtr, "%d %s %d/%d/%d %.2f\n", numeroTessera, nome, giorno, mese, anno, costoIscrizione);
            printf("%s", "? - ");
            scanf("%5d %19s %d/%d/%d %f", &numeroTessera, nome, &giorno, &mese, &anno, &costoIscrizione);
        }
    }
    fclose(sociPtr);
}