#include <stdio.h>

char parola[20];

int main(void)
{

    printf("Inserisci una parola di massimo 19 caratteri: ");
    scanf("%19s", parola);
    printf("La parola che hai inserito e':\n%s\n", parola);
}