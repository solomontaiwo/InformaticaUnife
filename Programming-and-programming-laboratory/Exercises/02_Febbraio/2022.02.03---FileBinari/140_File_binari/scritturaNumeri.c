// Salvare su un file binario numeri.dat il contenuto di un array di dieci interi. //
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int numeri[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    FILE *fnumeri;

    fnumeri = fopen("numeri.dat", "wb");

    if (fnumeri == NULL)
    {
        printf("Impossibile aprire il file.\n");
        exit(1);
    }
    else
        fwrite(numeri, sizeof(int), 10, fnumeri);
    fclose(fnumeri);
}