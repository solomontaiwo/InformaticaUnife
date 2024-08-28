#include <stdio.h>
int main()
{
    int a;
    int password = 579422;
    int i;
    printf("Inserisci la password per accedere alle funzioni avanzate del presente programma: \n");
    scanf("%d", &a);
    if (a == password)
        printf("Accesso consentito, goditi le funzionalita' dell'app.\n");
    else
    {
        printf("Password errata, hai altri due tentativi: \n");
        {
            scanf("%d", &a);
            if (a == password)
                printf("Accesso consentito, goditi le funzionalita' dell'app.\n");
            else
            {
                printf("Password errata, hai un ultimo tentativo: \n");
                scanf("%d", &a);
                if (a == password)
                    printf("Accesso consentito, goditi le funzionalita' dell'app.\n");
                else
                    printf("Password errata, sfortunatamente non puoi beneficiare delle funzionalita' del programma!\n");
            }
        }
    }
}