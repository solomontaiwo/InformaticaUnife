#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero, *ptr = &numero, fattoriale, i;

    printf("Inserisci un numero: ");
    scanf("%d", ptr);

    fattoriale = 1;

    for (i = 0; i < *ptr; i++)
        fattoriale = (*ptr - i) * fattoriale;

    printf("Il fattoriale di %d e' pari a %d\n", *ptr, fattoriale);

    return 0;
}