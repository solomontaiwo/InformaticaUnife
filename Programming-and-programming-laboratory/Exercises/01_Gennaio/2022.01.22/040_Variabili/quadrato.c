/* Calcolare l’area e il perimetro di un quadrato il cui lato è richiesto all’utente. 
Perimetro = 4l
Area = l^2 */

#include <stdio.h>

int main()
{
    int l;

    printf("Inserisci il lato di un quadrato, calcolero' l'area ed il perimetro: ");
    scanf("%d", &l);

    printf("\nArea del quadrato: %d\n", l * l);
    printf("Perimetro del quadrato: %d\n", 4 * l);
}
