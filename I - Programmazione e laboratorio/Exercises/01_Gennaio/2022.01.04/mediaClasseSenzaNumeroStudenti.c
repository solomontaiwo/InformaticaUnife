#include <stdio.h>

int numeroStudenti = 0;
int voto, totale = 0;
float media;
int contatore = 0;

int main()
{
    printf("Inserisci un voto: ");
    scanf("%d", &voto);

    while (voto != -1)
    {
        totale = totale + voto;
        contatore++;
        printf("Inserisci un voto: ");
        scanf("%d", &voto);
    }
    if (contatore != 0)
    {
        media = totale / contatore;
        printf("La media dei voti da te inseriti e' pari a %.2f.\n", media);
    }
    else
    {
        printf("Non sono stati inseriti dei dati validi.\n");
    }
}