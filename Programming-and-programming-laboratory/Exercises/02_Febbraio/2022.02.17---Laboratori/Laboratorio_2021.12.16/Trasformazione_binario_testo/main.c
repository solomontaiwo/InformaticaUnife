#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *pfb;
    FILE *pft;
    int i = 0;

    if ((pfb = fopen("numeri.dat", "rb")) == NULL)
    {
        printf("Errore nell'apertura del file binario.\n");
        exit(1);
    }

    if ((pft = fopen("numeri.txt", "wt")) == NULL)
    {
        printf("Errore nell'apertura del file binario.\n");
        exit(1);
    }

    int valore;

    while (fread(&valore, sizeof(int), 1, pfb))
    {
        fprintf(pft, "%d ", valore);
    }

    if (fclose(pfb) != 0)
    {
        printf("Errore nella chiusura del file binario.\n");
        exit(2);
    }

    if (fclose(pft) != 0)
    {
        printf("Errore nella chiusura del file binario.\n");
        exit(3);
    }
}