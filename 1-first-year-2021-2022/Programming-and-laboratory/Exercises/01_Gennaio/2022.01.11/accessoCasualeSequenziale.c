#include <stdio.h>

struct clientData
{
    int numeroAccount;
    char cognome[15];
    char nome[15];
    double bilancio;
};

int main(void)
{

    FILE *cfPtr;

    if ((cfPtr = fopen("accounts.dat", "wb")) == NULL)
    {
        puts("File non trovato.");
    }
    else
    {
        struct clientData cliente = {0, "", "", 0.0};

        for (int i = 0; i <= 100; ++i)
        {
            fwrite(&cliente, sizeof(struct clientData), 1, cfPtr);
        }
        fclose(cfPtr);
    }
}