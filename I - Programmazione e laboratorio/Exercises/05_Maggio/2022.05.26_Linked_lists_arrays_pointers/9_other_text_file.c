#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

int main(int argc, char *argv[])
{
    FILE *pft;
    char stringa[SIZE];
    int numeroStringhe, i;

    if ((pft = fopen("testo_di_prova.txt", "wt")) == NULL)
    {
        printf("Impossibile creare il file di testo.\n");
        exit(1);
    }

    printf("Quante stringhe vuoi inserire? ");
    scanf("%d", &numeroStringhe);

    getchar();

    for (i = 0; i < numeroStringhe; i++)
    {
        printf("Inserisci la stringa #%d: ", i + 1);
        fgets(stringa, sizeof(stringa), stdin);
        fprintf(pft, "%s", stringa);
    }

    fclose(pft);
    return 0;
}