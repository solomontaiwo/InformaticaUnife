// si chieda all'utente due numeri, il programma ne stamperà la somma ed il prodotto

#include <stdio.h>

int numero1;
int numero2;

int main()
{
    printf("Ciao, immetti il primo numero intero: ");
    scanf("%d", &numero1);

    printf("Immetti il secondo numero intero: ");
    scanf("%d", &numero2);

    printf("Il prodotto dei numeri da te inseriti e' %d.\n", numero1 * numero2);
}