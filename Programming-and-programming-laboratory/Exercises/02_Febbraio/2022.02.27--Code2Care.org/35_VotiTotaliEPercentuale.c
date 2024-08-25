#include <stdio.h>

int main(int argc, char *argv[])
{
    int inglese, francese, algebra, geometria, storia, geografia;
    int somma;
    float percentuale;

    printf("Inserisci il voto di inglese: ");
    scanf("%d", &inglese);
    printf("Inserisci il voto di francese: ");
    scanf("%d", &francese);
    printf("Inserisci il voto di algebra: ");
    scanf("%d", &algebra);
    printf("Inserisci il voto di geometria: ");
    scanf("%d", &geometria);
    printf("Inserisci il voto di storia: ");
    scanf("%d", &storia);
    printf("Inserisci il voto di geografia: ");
    scanf("%d", &geografia);

    somma = inglese + francese + algebra + geometria + storia + geografia;

    percentuale = (somma * 100) / 600;

    printf("Somma: %d\n", somma);
    printf("Percentuale: %.2f\n", percentuale);
}