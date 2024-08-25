#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char stringa[100];
    int frequenza[255];
    int i = 0, max;
    int ascii;

    printf("Inserisci una stringa: ");
    fgets(stringa, sizeof(stringa), stdin);

    for (i = 0; i < 255; i++)
    {
        frequenza[i] = 0;
    }

    i = 0;

    while (stringa[i] != '\0')
    {
        ascii = (int)stringa[i];
        frequenza[ascii] = frequenza[ascii] + 1;

        i++;
    }

    max = 0;

    for (i = 0; i < 255; i++)
    {
        if (i != 32)
        {
            if (frequenza[i] > frequenza[max])
                max = i;
        }
    }
    
    printf("La frequenza piu' elevata del carattere '%c' appare %d volte.\n", max, frequenza[max]);

    return 0;
}