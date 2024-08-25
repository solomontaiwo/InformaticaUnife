// Scrivere un programma che stampi il plurale di una parola che termina in "cia" o "gia" digitata dall'utente //
#include <stdio.h>
#define DIM 25

int main(void)
{
    char parola[DIM];

    printf("Inserisci una parola terminante in 'cia' o 'gia': ");

    scanf("%s", parola);

    int i = 0;

    while (parola[i] != '\0' && parola[i] != 'c')
        i++;

    if (parola[i] == 'c')
        parola[i + 2] == 'e';

    printf("Parola inserita al plurale: %s.\n", parola);
}