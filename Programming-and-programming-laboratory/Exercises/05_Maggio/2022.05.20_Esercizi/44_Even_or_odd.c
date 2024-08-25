#include <stdio.h>

int main(int argc, char *argv[])
{

    int a;

    printf("Inserisci un valore: ");
    scanf("%d", &a);

    if ((a % 2) == 0)
        printf("Il numero da te inserito e' pari.\n");
    else
        printf("Il numero inserito e' dispari.\n");
}