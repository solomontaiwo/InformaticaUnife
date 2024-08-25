#include <stdio.h>

int main(void)
{

    FILE *aPtr;
    if ((aPtr = fopen("provaFile.txt", "w")) == NULL) // verifica apertura file in scrittura
    {
        puts("Non sono riuscito ad aprire il file.");
    }
    else
    {
        puts("inserisci il tuo nome, secondo nome, cognome e anno di nascita");
        puts("Immetti il parametro di EOF per terminare (ctrl+z).");
        printf("%s", "? ");
    }

    char nome[20];
    char secondoNome[20];
    char cognome[20];
    int annoNascita = 0;

    scanf("%s %s %s %d", nome, secondoNome, cognome, &annoNascita);

    while (!feof(stdin))
    {
        fprintf(aPtr, "%s %s %s %d\n", nome, secondoNome, cognome, annoNascita);
        printf("%s", "? ");
        scanf("%s %s %s %d", nome, secondoNome, cognome, &annoNascita);
    }
    fclose(aPtr); // chiusura file
}