#include <stdio.h>

int main(void)
{

    FILE *cfPtr;

    if ((cfPtr = fopen("clients.txt", "r")) == NULL)
    {
        puts("Non e' stato possibile aprire il file");
    }
    else
    {
        int account;
        char nome[20];
        double bilancio;

        printf("%-10s%-13s%s\n", "Account", "Nome", "Bilancio");
        fscanf(cfPtr, "%d%19s%lf", &account, nome, &bilancio);

        while (!feof(cfPtr))
        {
            printf("%-10d%-13s%7.2f\n", account, nome, bilancio);
            fscanf(cfPtr, "%d%19s%lf", &account, nome, &bilancio);
        }
        fclose(cfPtr);
    }
}