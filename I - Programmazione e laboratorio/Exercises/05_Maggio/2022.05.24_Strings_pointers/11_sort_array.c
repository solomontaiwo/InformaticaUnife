#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char stringa[100], temp;
    int i, lunghezza, j;

    printf("Inserisci una stringa: ");
    fgets(stringa, sizeof(stringa), stdin);

    lunghezza = strlen(stringa);

    for (i = 1; i < lunghezza; i++)
    {
        for (j = 0; j < lunghezza - 1; j++)
        {
            if (stringa[j] > stringa[j + 1])
            {
                temp = stringa[j];
                stringa[j] = stringa[j + 1];
                stringa[j + 1] = temp;
            }
        }
    }

    printf("Stringa in ordine crescente: %s\n", stringa);
}