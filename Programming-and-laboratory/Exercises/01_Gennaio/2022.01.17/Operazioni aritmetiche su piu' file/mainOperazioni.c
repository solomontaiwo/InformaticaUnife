#include <stdio.h>
#include "istruzioni.h"
#include "operazioni.h"

char istruzioniValori();
char istruzioniOperatori();

int addizione(int numero1, int numero2);
int sottrazione(int numero1, int numero2);
int moltiplicazione(int numero1, int numero2);
float divisione(float numero1, float numero2);

int main(void)
{
    puts("Benvenuto in uno dei primi programmi realizzati in autonomia da Solomon! Il programma ti fornira' una brevissima guida su come utilizzarlo.\n");

    istruzioniValori();

    float numero1, numero2;

    scanf("%f%f", &numero1, &numero2);

    istruzioniOperatori();

    int operazione;

    scanf("%d", &operazione);

sceltaOperazione:
    switch (operazione)
    {
    case 1:
    {
        printf("Addizione: ");
        printf("%d\n", addizione(numero1, numero2));
        break;
    }
    case 2:
    {
        printf("Sottrazione: \n");
        printf("%d\n", sottrazione(numero1, numero2));
        break;
    }
    case 3:
    {
        printf("Moltiplicazione\n");
        printf("%d\n", moltiplicazione(numero1, numero2));
        break;
    }

    case 4:
    {
        printf("Divisione\n");
        printf("%.2f\n", divisione(numero1, numero2));
        break;
    }
    default:
    {
        printf("Valore non valido\n");
        goto sceltaOperazione;
    }
    }
}
