#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, b, *ptr1 = &a, *ptr2 = &b;

    printf("Inserisci il primo numero: ");
    scanf("%d", ptr1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", ptr2);

    if (*ptr1 > *ptr2)
        printf("\n%d e' il numero piu' grande.\n", *ptr1);
    else
        printf("\n%d e' il numero piu' grande.\n", *ptr2);

    return 0;
}