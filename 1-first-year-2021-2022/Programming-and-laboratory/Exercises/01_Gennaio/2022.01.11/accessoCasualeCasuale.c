#include <stdio.h>

struct clientData
{
    int numeroAccount;
    char cognome[15];
    char nome[10];
    double bilancio;
};

int main(void)
{
    FILE *cfPtr;
    if ((cfPtr = fopen("accounts.dat", "rb+")) == NULL)
    {
        puts("File non trovato");
    }
    else
    {
        struct clientData client = {0, "", "", 0.0}; // creazione oggetto clientData con informazioni predefinite
        printf("%s", "inserisci il numero del conto"
                     " (da 1 a 100, 0 per interrompere l'input): ");
        scanf("%d", &client.numeroAccount);
        while (client.numeroAccount != 0)
        {
            printf("%s", "\nInserisci cognome, nome e bilancio: ");
            fscanf(stdin, "%14s%9s%lf", client.cognome, client.nome, &client.bilancio);

            fseek(cfPtr, (client.numeroAccount - 1) * sizeof(struct clientData), SEEK_SET);
            fwrite(&client, sizeof(struct clientData), 1, cfPtr);
            
            printf("%s", "\nInserisci numero account: ");
            scanf("%d", &client.numeroAccount);
        }
        fclose(cfPtr);
    }
}