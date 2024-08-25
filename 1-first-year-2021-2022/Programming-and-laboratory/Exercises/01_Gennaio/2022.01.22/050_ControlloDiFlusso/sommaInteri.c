// Si scriva un programma che stampi la somma dei primi n numeri naturali, dove n è un numero richiesto all’utente. //
#include <stdio.h>

int main()
{
    int naturale;
    int somma = 0;

    printf("Inserisci un numero naturale, ti indichero' la somma di tutti i valori precedenti (ed incluso) al numero da te inserito.\n");
    scanf("%d", &naturale);

    for (int i = 0; i <= naturale; i++)
    {
        somma += i;
    }
    printf("La somma dei valori pari ed inferiori a %d, numero naturale da te indicato, e' pari a %d.\n", naturale, somma);
}