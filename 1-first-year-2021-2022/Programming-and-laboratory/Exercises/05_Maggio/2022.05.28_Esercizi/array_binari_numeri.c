#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *pfb;

    if ((pfb = fopen("numeri.dat", "wb")) == NULL)
    {
        printf("Impossibile creare il file binario.\n");
        exit(-2);
    }

    int numeri[10];
    int numeriLetti[10];

    printf("Inserisci i dieci numeri: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &numeri[i]);
    }

    fwrite(numeri, sizeof(int), 10, pfb);

    fclose(pfb);

    if ((pfb = fopen("numeri.dat", "rb")) == NULL)
    {
        printf("Impossibile leggere il file binario.\n");
        exit(-3);
    }

    fread(numeriLetti, sizeof(int), 10, pfb);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numeriLetti[i]);
    }

    puts("");

    fclose(pfb);
    return 0;
}