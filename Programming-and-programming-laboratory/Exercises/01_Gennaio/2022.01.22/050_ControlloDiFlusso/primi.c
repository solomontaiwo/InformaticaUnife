// Stampare tutti i numeri primi minori o uguali a un numero richiesto all’utente. //
#include <stdio.h>

#include <stdio.h>

main()
{
    int n, i;
    int pot_primo;
    int massimo;

    scanf("%d", &massimo);

    printf("2 ");

    for (n = 3; n <= massimo; n += 2)
    {
        pot_primo = 1;
        if (n > 2 && n % 2 == 0)
            pot_primo = 0;
        i = 3;
        while (i * i <= n && pot_primo)
        {
            if (n % i == 0)
                pot_primo = 0;
            i = i + 2;
        }
        if (pot_primo)
            printf("%d ", n);
    }
    printf("\n");
}