// Letti una stringa ed un carattere, verificare se il carattere compare nella stringa //
#include <stdio.h>

int i, s;
char stringa[] = "Ferrara", carattere;

int main()
{
    printf("Inserisci un carattere, lo cerchero' all'interno di una stringa predeterminata: ");
    scanf("%c", &carattere);

    while (stringa[i] != '\0')
    {
        if (stringa[i] == carattere)
        {
            printf("Il carattere '%c' si trova all'indice %d.\n", carattere, i);
            i++;
        }
        else
        {
            i++;
        }
    }
}