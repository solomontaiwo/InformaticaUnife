#include <stdio.h>

int risultato = 0;
int superato = 0;
int fallito = 0;
int numeroStudenti = 10;
int contatore = 0;

void main()
{
    do
    {
        printf("Immettere risultato dell'esame (1 = superato, 2 = fallito): ");
        scanf("%d", &risultato);
        contatore++;

        if (risultato == 1 || risultato == 2)
        {
            if (risultato == 1)
                superato++;
            else if (risultato == 2)
                fallito++;
        }
        else
        {
            printf("Hai immesso un dato non valido.\n");
            break;
        }

    } while (contatore < numeroStudenti);

    printf("Il numero di studenti che ha superato l'esame e' pari a %d, mentre coloro che non l'hanno superato sono %d.\n", superato, fallito);
    if (superato >= 8)
        printf("Punti bonus per l'istruttore!\n");
}