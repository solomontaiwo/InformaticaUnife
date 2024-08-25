#include <stdio.h>
#include <stdlib.h>
#include <string.h> // libreria con funzioni legate alle stringhe

int main()
{
    char city[40];
    printf("Inserisci il nome della tua citta' preferita: ");
    fgets(city, 40, stdin); // nome della funzione chiamata, numero massimo di caratteri letti e fonte dell'input (stdin = tastiera)

    fputs(city, stdout);
    printf("e' una citta' fantastica, hai dei gusti eccezionali.\n");

    return 0;
}