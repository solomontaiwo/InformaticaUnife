#include <stdio.h>

int main(void)
{

    FILE *provaPtr;

    if ((provaPtr = fopen("fileAutonomia.txt", "w")) == NULL)
    {
        puts("Non riesco ad aprire il file, scusami.");
    }
    else
    {
        puts("inserisci nome, cognome e luogo di nascita dell'utente");
        puts("Immetti la combinazione di tasti ctrl+z per terminare le operazioni.");
        printf("- ");
    }

    char nome[10], cognome[10], luogoNascita[10];
    scanf("%s %s %s", nome, cognome, luogoNascita);

    while (!feof(stdin))
    {
        fprintf(provaPtr, "%s %s %s\n", nome, cognome, luogoNascita);
        printf("- ");
        scanf("%s %s %s", nome, cognome, luogoNascita);
    }
    fclose(provaPtr);
}