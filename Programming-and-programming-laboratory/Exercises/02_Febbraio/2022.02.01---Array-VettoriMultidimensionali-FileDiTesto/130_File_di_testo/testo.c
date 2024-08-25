// Crea un programma che crei un file di testo, vi scriva i dati inseriti dall'utente ed infine ne stampi a video il contenuto //
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char stringa[50];
    char stringaLetta[50];
    char carattere;
    int i;

    FILE *fp;

inizio:
    if ((fp = fopen("esercizioDiProva.txt", "wt")) == NULL)
    {
        printf("Non e' stato possibile aprire il file da te richiesto.\n");
        goto inizio;
    }
    else
    {
        printf("Inserisci il testo che vuoi inserire all'interno del file: ");
        scanf("%s", stringa);
        fprintf(fp, "%s", stringa);
    }

    fclose(fp);

    puts("Di seguito il contenuto del file: ");

    fp = fopen("esercizioDiProva.txt", "rt");

    while (fscanf(fp, "%c", &stringaLetta[i]) && !feof(fp))
    {
        printf("%c", stringaLetta[i]);
        i++;
    }
    puts("");
}