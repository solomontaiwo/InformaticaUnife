#include <stdio.h>

void azzera(int *pm)
{
    *pm = 0; // azzera il valore della variabile il cui indirizo è passato come parametro attuale
}

int main()
{
    int a = 4;
    azzera(&a);
    printf("%d\n", a); // il programma dovrebbe stampare 0

    return 0;
}