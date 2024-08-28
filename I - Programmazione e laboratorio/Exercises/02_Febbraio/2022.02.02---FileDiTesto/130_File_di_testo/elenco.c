/* È dato un file di testo elenco.txt le cui righe rappresentano ciascuna i dati di una persona, secondo il seguente formato:
1. cognome (esattamente 10 caratteri)
2. nome (esattamente 10 caratteri)
3. sesso (esattamente un carattere)
4. anno di nascita
I primi due possono contenere spazi al loro interno.
NB: non sono previsti spazi espliciti di separazione
*/
#include <stdio.h>
#include <stdlib.h>
#define TOTALPEOPLE 40

int main(void)
{
    typedef struct
    {
        char cognome[11], nome[11], sesso;
        int anno;
    } persona;

    persona p[TOTALPEOPLE];

    FILE *flista;
    int k = 0;

    if ((flista = fopen("elenco.txt", "rt")) == NULL)
    {
        perror("Impossibile aprire il file.\n");
        exit(1);
    }

    while (fscanf(flista, "%10c%10c%c%d", p[k].cognome, p[k].nome, &p[k].sesso, &p[k].anno) != EOF)
    {
        p[k].cognome[10] = p[k].nome[10] = '\0';
        k++;
    }

    fclose(flista);

    for (int i = 0; i < 4; i++)
        printf("%s%s%c%d\n", p[i].cognome, p[i].nome, p[i].sesso, p[i].anno);
}