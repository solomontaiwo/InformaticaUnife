#include <stdio.h>

int main(int argc, char *argv[])
{
    char stringa[200];
    int lettere, numeri, speciali, i;
    lettere = numeri = speciali = i = 0;

    printf("Inserisci una stringa: ");
    fgets(stringa, sizeof(stringa), stdin);

    while (stringa[i] != '\0')
    {
        if (stringa[i] >= '0' && stringa[i] <= '9')
            numeri++;
        else if ((stringa[i] >= 'A' && stringa[i] <= 'Z') || (stringa[i] >= 'a' && stringa[i] <= 'z'))
            lettere++;
        else
            speciali++;

        i++;
    }

    printf("Numero di lettere: %d\n", lettere);
    printf("Numero di numeri: %d\n", numeri);
    printf("Numero di caratteri speciali: %d\n", speciali--);

    return 0;
}