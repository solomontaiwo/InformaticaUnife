/* Un file di testo rubrica.txt contiene una rubrica del telefono, in cui per ogni persona sono memorizzati di seguito
1. nome (stringa di max 20 caratteri senza spazi, incluso ‘\0’)
2. indirizzo (stringa di max 30 caratteri senza spazi, incluso ‘\0’)
3. numero (stringa di max 15 caratteri incluso ‘\0’)
Si scriva un programma C che legge da tastiera un nome, cerca la persona corrispondente nel file rubrica.txt e visualizza sullo schermo i dati della persona (se trovata).
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char nomeFile[20];
    char nomeInTesto[10];
    char nomeRicercato[10];

    FILE *fp;

    printf("Scrivi il nome del file da aprire: ");
    scanf("%s", nomeFile);

    if ((fp = fopen(nomeFile, "rt")) == NULL)
        printf("Impossibile aprire il file richiesto.\n");
    else
    {
        printf("Inserisci un nome: ");
    }
}