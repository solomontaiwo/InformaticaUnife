#include <stdio.h>
#include <stdlib.h>
#include <string.h> // libreria con funzioni legate alle stringhe

char fullName[35];
int main()
{

    printf("Inserisci il tuo nome e cognome completi: \n");
    fgets(fullName, 35, stdin); // nome della funzione chiamata, numero massimo di caratteri letti e fonte dell'input (stdin = tastiera)
    printf("Il tuo nuome completo e' %s", fullName);
}