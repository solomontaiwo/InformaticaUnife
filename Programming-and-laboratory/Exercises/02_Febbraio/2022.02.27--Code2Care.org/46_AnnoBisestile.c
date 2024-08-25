#include <stdio.h>

int main(int argc, char *argv[])
{
    int anno;

    printf("Inserisci un anno: ");
    scanf("%d", &anno);

    if (anno % 400 == 0 || anno % 100 != 0 && anno % 4 == 0)
        printf("%d e' un anno bisestile\n");
    else
        printf("%d non e' un anno bisestile.\n");
}