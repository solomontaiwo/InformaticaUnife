/* Se a è una variabile intera, scrivere espressioni che la aggiornino
al suo valore incrementato di 2
al doppio del suo valore
al quadrato del suo valore
Verificare la correttezza delle espressioni con opportuni programmi che
1 Richiedano in input il valore a;
2 Aggiornino a come richiesto;
3 Stampino in output il nuovo valore di a; */

#include <stdio.h>

int main()
{
    int a;

    printf("Inserisci un valore intero, ne incrementero' il valore di 2, lo raddoppiero' e te ne mostrero' il quadrato: ");
    scanf("%d", &a);

    printf("Il valore di %d incrementato di 2 e' pari a %d.\n", a, a + 2);
    printf("Il valore di %d raddoppiato e' pari a %d.\n", a, a * 2);
    printf("Il valore di %d al quadrato e' pari a %d.\n", a, a * a);
}