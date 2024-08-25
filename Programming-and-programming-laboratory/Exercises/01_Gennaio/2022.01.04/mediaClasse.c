#include <stdio.h>

int numeroStudenti = 10;
float voto, totale = 0;
int contatore = 0;
float media;

int main()
{
    while (contatore < 10)
    {
        printf("Inserisci il voto ottenuto dallo studente: ");
        scanf("%f", &voto);
        totale = totale + voto;
        contatore++;
    }

    media = totale / numeroStudenti;
    printf("La media dei voti ottenuti dagli alunni e' %.2f.\n", media);
}
