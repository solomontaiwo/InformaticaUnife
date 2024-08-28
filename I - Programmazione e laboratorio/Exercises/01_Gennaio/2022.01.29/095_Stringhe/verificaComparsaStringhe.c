// Date due stringhe, verificare se una contiene l’altra (es "zio" è contenuta in "Tizio"). //
#include <stdio.h>

int main(void)
{
    char stringa1[] = "Tizio";
    char stringa2[] = "zio";
    int trovato, i = 0, j = 0;

    trovato = 0; // flag!

    while (!trovato && stringa2[i] != '\0')
    {
        i = 0;
        while (stringa1[i] != '\0' && stringa2[j + i] != '\0' && stringa1[i] == stringa2[j + i])
            i++;
        if (stringa1[i] == '\0')
            trovato = 1;
        j++;
    }
    if (trovato)
        printf("%s si trova all'interno di %s.\n", stringa2, stringa1);
    else
        printf("%s non si trova all'interno di %s.\n", stringa2, stringa1);
}