#include <stdio.h>

int main(void)
{
    FILE *puntatorePtr;

    if ((puntatorePtr = fopen("fileDiTesto.txt", "w")) == NULL)
    {
        puts("Non sono riuscito a trovare il file, il programma verra' interrotto");
        puts("...");
    }
    else
    {
        puts("Inserisci i valori relativi al numero del conto, il nome del proprietario dello stesso ed il bilancio complessivo all'interno di esso.");
        puts("Inserisci la combinazione di tasti per EOF del sistema operativo utilizzato per uscire dal programma salvando i dati inseriti fino a quel punto (ctrl+z per Windows, ctrl+d per Linux)");
        printf("%s ", "? -");

        int numeroConto;
        char nomeProprietario[20];
        float bilancio;

        scanf("%d%s%f", &numeroConto, nomeProprietario, &bilancio);

        while (!feof(stdin))
        {
            fprintf(puntatorePtr, "%d %s %.2f\n", numeroConto, nomeProprietario, bilancio);
            printf("%s ", "? -");
            scanf("%d%s%f", &numeroConto, nomeProprietario, &bilancio);
        }
    }
    fclose(puntatorePtr);
}