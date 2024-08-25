/* leggi da tastiera un carattere c; se c è minuscola visualizza "minuscola", 
se maiuscola visualizza "maiuscola" e se numero visualizza "numero" */

#include <stdio.h>
main()
{
    char c;
    printf("Inserisci un carattere oppure un numero.\n");
    scanf("%c", &c);
    if (c >= 97 && c <= 122)
        printf("%c e' minuscola.\n", c);
    else
    {
        if (c >= 65 && c <= 90)
            printf("%c e' maiuscola.\n", c);
        else
        {
            if (c >= 48 && c <= 57)
                printf("%c e' un numero.\n", c);
        }
    }
}