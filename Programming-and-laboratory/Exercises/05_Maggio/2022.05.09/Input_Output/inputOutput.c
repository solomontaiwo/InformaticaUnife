#include <stdio.h>

int main(int argc, char *argv[])
{
    char parolaInserita[50];

    printf("Inserisci una parola: ");
    scanf("%s", &parolaInserita);

    printf("Questa e' la parola che hai inserito: %s\n", parolaInserita);
}