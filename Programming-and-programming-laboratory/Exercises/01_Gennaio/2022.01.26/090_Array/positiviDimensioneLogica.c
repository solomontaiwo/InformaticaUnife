// NOTA BENE: Un array può avere una dimensione logica (cioè il numero di elementi significativi) inferiore (e mai superiore!) alla sua dimensione fisica (cioè il numero di celle di memoria riservate per l’array quando è stato definito). //
#include <stdio.h>
#define SIZE 5

int main()
{
    int a[SIZE], b[SIZE], i, dl = 0;

    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < SIZE; i++)
    {
        if (a[i] > 0)
        {
            b[dl] = a[i];
            dl++;
        }
    }
    for (i = 0; i < dl; i++)
    {
        printf("%d\n", b[i]);
    }
}