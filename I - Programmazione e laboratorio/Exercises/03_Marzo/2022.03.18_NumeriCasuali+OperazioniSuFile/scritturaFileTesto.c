#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *testo;
    char parola[20], parolaLetta[20];

    if ((testo = fopen("Prova.txt", "w+")) == NULL)
    {
        printf("Impossibile aprire il file.\n");
        exit(1);
    }

    printf("Scrivi una parola: ");
    scanf("%s", parola);

    fprintf(testo, "%s", parola);

    fclose(testo);

    if ((testo = fopen("Prova.txt", "r+")) == NULL)
    {
        printf("Impossibile leggere il file.\n");
        exit(2);
    }

    fscanf(testo, "%s", parolaLetta);

    printf("Di seguito la parola letta dal file di testo: %s\n", parolaLetta);

    fclose(testo);

    return 0;
}