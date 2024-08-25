#include <stdio.h>

int main(int argc, char *argv[])
{
    char stringa[50];
    int conto = 0;
    int i = 0;

    printf("Immetti una stringa: ");
    fgets(stringa, sizeof(stringa), stdin);

    while (stringa[i] != '\n')
    {
        conto++;
        i++;
    }

    printf("Lunghezza della stringa: %d\n", conto);

    return 0;
}