// Si scriva una procedura che ordini in senso crescente due variabili locali al chiamante; se la seconda è minore della prima, ne scambi i valori usando la procedura swap. //
#include <stdio.h>

void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void ordina2(int *pa, int *pb)
{
    // scambia i valori delle aree puntate dai parametri se non sono in ordine
    // crescente
    if (*pa > *pb)
        swap(pa, pb);
}

int main(void)
{
    int a, b;

    printf("Inserisci due numeri interi, te li mettero' in ordine: ");
    scanf("%d %d", &a, &b);

    ordina2(&a, &b);
    printf("%d %d\n", a, b);
}