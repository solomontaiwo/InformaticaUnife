#include <stdio.h>

int main(void)
{

    FILE *puntatorePtr;

    if ((puntatorePtr = fopen("fileDiTesto.txt", "r")) == NULL)
    {
        puts("Non sono riuscito ad aprire il file, ora il programma si interrompera'.");
    }
    else
    {
        int numeroConto;
        char nomeProprietario[20];
        float bilancio;

        printf("%10s %15s %10s\n", "Numero Conto", "Proprietario", "Bilancio");
        fscanf(puntatorePtr, "%d%s%f", &numeroConto, nomeProprietario, &bilancio);

        while (!feof(puntatorePtr))
        {
            printf("%-16d%-15s%.2lf\n", numeroConto, nomeProprietario, bilancio);
            fscanf(puntatorePtr, "%d %s %f", &numeroConto, nomeProprietario, &bilancio);
        }
        fclose(puntatorePtr);
    }
}