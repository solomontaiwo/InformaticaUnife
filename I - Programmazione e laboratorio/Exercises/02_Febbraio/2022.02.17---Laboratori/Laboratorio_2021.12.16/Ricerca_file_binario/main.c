#include "ricerca.h"

int main(int argc, char *argv[])
{
    int numero;

    FILE *pfb;

    if ((pfb = fopen("numeri.dat", "rb")) == NULL)
    {
        printf("Impossibile aprire il file binario.\n");
        exit(1);
    }

    printf("Inserisci un numero da ricercare: ");
    scanf("%d", &numero);

    ricerca(pfb, numero);

    if (fclose(pfb) != 0)
    {
        printf("C'e' stato un errore nella chiusura del file binario.\n");
        exit(2);
    }
}