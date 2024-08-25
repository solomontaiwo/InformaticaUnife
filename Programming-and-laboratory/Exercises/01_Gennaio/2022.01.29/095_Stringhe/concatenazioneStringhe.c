// Date due stringhe, mettere in una terza stringa la concatenazione delle due //
#include <stdio.h>

int main(void)
{
    int i, f = 4;
    char a[] = "Gian", b[] = "luca", c[20];

    for (i = 0; a[i] != '\0'; i++)
    {
        c[i] = a[i];
    }

    for (i = 0; b[i] != '\0'; i++)
    {
        c[f] = b[i];
        f++;
    }

    c[f] = '\0';

    printf("Il contenuto all'interno dell'array c e' %s.\n", c);
}
