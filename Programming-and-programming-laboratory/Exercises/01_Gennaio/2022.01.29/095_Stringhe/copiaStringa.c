// Data una stringa di caratteri, copiarla in un altro array di caratteri (di lunghezza non inferiore).
#include <stdio.h>

int main(void)
{
    int i;
    char array1[] = {"Pincopallo"};
    char array2[100];

    for (i = 0; array1[i] != '\0'; i++)
    {
        array2[i] = array1[i];
    }
    array2[i] = '\0';

    printf("Array1 (%s) e' uguale ad Array2 (%s).\n", array1, array2);
}