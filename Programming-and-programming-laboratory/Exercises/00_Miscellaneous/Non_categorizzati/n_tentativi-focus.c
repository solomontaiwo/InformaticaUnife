#include <stdio.h>

main()
{
    int pin = 44121;
    
    int n_tentativi = 0; // contatore

    while (n_tentativi < 3)
    {
        printf("Digita il PIN\n");
        scanf("%d", &pin);
        n_tentativi++;
        if (pin == 44121)
        break;
            
    }
    if (pin == 44121 && n_tentativi < 3)
        printf("Accesso consentito\n");
    else
        printf("Accesso negato\n");
}