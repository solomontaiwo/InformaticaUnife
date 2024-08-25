#include <stdio.h>

int main(void)
{

    FILE *cfPtr;

    if ((cfPtr = fopen("clients.txt", "w")) == NULL)
    {
        puts("Non e' stato possibile aprire il file");
    }
    else
    {
        puts("Inserisci l'account, il nome ed il bilancio.");
        puts("inserisci EOF per terminare l'input");
        printf("%s", "? ");

        unsigned int account;
        char nome[30];
        double bilancio;

        scanf("%d%29s%lf", &account, nome, &bilancio);

        while (!feof(stdin))
        {
            fprintf(cfPtr, "%d %s %.2f\n", account, nome, bilancio);
            printf("%s", "? ");
            scanf("%d%29s%lf", &account, nome, &bilancio);
        }
        fclose(cfPtr);
    }
}