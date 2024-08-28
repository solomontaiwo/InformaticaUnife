#include <stdio.h>
int main()
{
    int scelta, ritorno;
    ritorno = 1;
    goto logo;
elenco:
    printf("1. Tizio 123-456789\n");
    printf("2. Caio 987-654321\n");
    printf("Scegliere un contatto\n");
    scanf("%d", &scelta);
    ritorno = 2;
    goto logo;
chiamata:
    printf("Chiamata del contatto %d in corso\n", scelta);
    goto fine;
logo: // subroutine
    printf("#############\n");
    printf("#  Rubrica  #\n");
    printf("#############\n");
    if (ritorno == 1)
        goto elenco;
    else if (ritorno == 2)
        goto chiamata;
fine:
    printf("Fine\n");
}