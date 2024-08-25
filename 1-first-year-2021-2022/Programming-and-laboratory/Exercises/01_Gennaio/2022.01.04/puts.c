#include <stdio.h>

int main()
{
    int grade;
    printf("Che punteggio hai ottenuto, in centesimi, all'esame di ieri?\n");
    scanf("%d", &grade);

    if (grade >= 60)
    {
        puts("Superato.");
    }

    else
    {
        puts("Non superato.");
        puts("Devi rifare l'esame.");
    }
}