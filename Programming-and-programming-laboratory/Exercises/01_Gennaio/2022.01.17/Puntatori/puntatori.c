#include <stdio.h>

int x = 69;
int *p1 = &x;
int **p2 = &p1;
int ***p3 = &p2;

int main(void)
{
    printf("Il valore di x e' di %d, mentre il suo indirizzo e' pari a %p.\n", x, &x);
    printf("Il valore di p1 e' di %p, mentre il suo indirizzo e' pari a %p.\n", p1, &p1);
    printf("Il valore di p2 e' di %p, mentre il suo indirizzo e' pari a %p.\n", p2, &p2);
    printf("Il valore di p3 e' di %p, mentre il suo indirizzo e' pari a %p.\n", p3, &p3);

    printf("Valore di x da p1: %d\n", *p1); // deferenziazione
    printf("Valore di x da p2: %d\n", **p2);
    printf("Valore di x da p2: %d\n", ***p3);
}