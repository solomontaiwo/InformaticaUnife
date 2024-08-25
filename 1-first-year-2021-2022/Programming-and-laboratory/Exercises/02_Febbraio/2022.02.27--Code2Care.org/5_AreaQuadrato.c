#include <stdio.h>

int main(int argc, char *argv[])
{
    int lato, area;

    printf("Inserisci il valore del lato del quadrato: ");

    scanf("%d", &lato);

    area = lato * lato;

    printf("Area del quadrato pari a %d.\n", area);
}