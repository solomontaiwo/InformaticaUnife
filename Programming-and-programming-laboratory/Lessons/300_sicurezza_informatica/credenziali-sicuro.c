#include <stdio.h>
#include <string.h>
#include "stringhe.h"

typedef struct
{
    char password[16];
    char nome_utente[16];
} Credenziali;

int main()
{
    char pwd[16];
    Credenziali c;
    printf("Nome utente?\n");
    leggiStringa(c.nome_utente, 15);
    printf("Password?\n");
    leggiStringa(c.password, 15);
    strcpy(pwd, "segreto");
    if (strcmp(c.password, pwd) == 0)
        printf("Accesso consentito per %s\n", c.nome_utente);
    else
        printf("Accesso negato per %s\n", c.nome_utente);
}