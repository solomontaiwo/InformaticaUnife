/* Scrivere un programma che richieda all’utente tre coefficienti reali a, b e c e stampi le coppie ordinate xx, yy, dove y = ax^2 + bx + c, per x che varia fra -1.0 e 1.0 a passi di 0.1. Procedere in questo ordine:
1 riempire un vettore ascisse con tutti i valori di x.
2 riempire un vettore ordinate con i corrispondenti valori di y.
3 stampare le coppie ordinate.
*/
#include <stdio.h>
#define SIZE 21

double ascisseX[SIZE];
double ordinateY[SIZE];

double a, b, c;

int main()
{
    int i = 0;

    printf("Inserisci tre coefficienti reali, stampero' le coppie ordinate xx, yy.\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    for (double passi = -1; passi < 1.0; passi += 0.1)
    {
        ascisseX[i] = passi;
        ++i;
    }

    puts("");
    {
        int i = 0;
        for (double passi2 = -1.0; passi2 < 1.0; passi2 += 0.1)
        {
            ordinateY[i] = ((a * (ascisseX[i] * ascisseX[i])) + (b * ascisseX[i]) + c); // y = ax^2 + bx + c,
            i++;
        }

        for (int i3 = 0; i3 < SIZE; i3++)
        {
            printf("%.1lf %.1lf\n", ascisseX[i3], ordinateY[i3]);
        }
    }
}