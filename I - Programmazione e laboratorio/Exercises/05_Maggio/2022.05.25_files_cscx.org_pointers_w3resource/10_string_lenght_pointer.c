#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char stringa[20];
    int conta = 0, i = 0;

    printf("Inserisci una stringa: ");
    scanf("%s", stringa);

    while (*(stringa + i) != '\0')
    {
        conta++;
        i++;
    }

    printf("Lunghezza della stringa %s : %d\n", stringa, conta);

    return 0;
}