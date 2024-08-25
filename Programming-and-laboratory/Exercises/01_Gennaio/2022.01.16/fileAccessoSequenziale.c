// Questo programma crea un file in cui vengono scritti il numero dell'account, il nome ed il bilancio all'interno del suddetto account. Buon divertimento.

#include <stdio.h>

int main(void)
{

    FILE *filePtr;

    if ((filePtr = fopen("fileAccountNomeBilancio.txt", "w")) == NULL)
    {
        printf("Impossibile aprile il file, il programma e' terminato.\n");
    }
    else
    {
        puts("Inserisci il numero dell'account, il nome ed infine il bilancio al suo interno.");
        puts("Premi EOF (ctrl + z in Windows, ctrl + d in linux) per terminare il programma.");
        printf("%c ", '?');

        unsigned int account;
        char nome[10];
        double bilancio;

        scanf("%d%s%lf", &account, nome, &bilancio);

        while (!feof(stdin))
        {
            fprintf(filePtr, "%d %s %.2lf\n", account, nome, bilancio);
            printf("%c ", '?');
            scanf("%d%s%lf", &account, nome, &bilancio);
        }
        fclose(filePtr);
    }
}