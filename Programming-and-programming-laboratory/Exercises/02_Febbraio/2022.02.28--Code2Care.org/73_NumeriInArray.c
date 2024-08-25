#include <stdio.h>

int main(int argc, char *argv[])
{
    int array[10], somma;
    for (int i = 0; i < 10; i++)
    {
        printf("Inserisci il numero %d: ", i + 1);
        scanf("%d", &array[i]);
        somma += array[i];
    }
    printf("Somma: %d\n", somma);
}