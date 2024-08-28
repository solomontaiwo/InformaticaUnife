#include <stdio.h>

main()
{
    int pin = 44121;
    int corretto; // variabile di tipo logico che fa da FLAG
    corretto = 0;
    while (!corretto)
    {
        printf("Digita il PIN\n");
        scanf("%d", &pin);
        if (pin == 44121)
            corretto = 1;
    }
    if (corretto)
        printf("Accesso consentito\n");
    else
        printf("Accesso negato\n");
}