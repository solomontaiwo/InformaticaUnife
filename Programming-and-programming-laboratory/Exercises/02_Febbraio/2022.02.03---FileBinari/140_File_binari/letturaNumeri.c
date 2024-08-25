/* Leggere da un file binario numeri.dat una sequenza di interi, scrivendoli in un array. 
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int numeri[10];
    FILE *fnumeri;

    if ((fnumeri = fopen("numeri.dat", "rb")) == NULL)
    {
        printf("Impossibile aprire il file binario.\n");
        exit(1);
    }
    else
    {
        fread(numeri, sizeof(int), 10, fnumeri);
    }
    for (int i = 0; i < 10; i++)
        printf("%d ", numeri[i]);
}