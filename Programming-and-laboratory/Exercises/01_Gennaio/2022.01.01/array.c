// chiedere all'utente un numero tra 1 e 5 e stampare l'elemento corrispondente dell'array
#include <stdio.h>
#include <stdlib.h>

int array[] = {15, 30, 45, 60, 75};
int a;

int main()
{
    printf("Dammi un valore tra 0 e 4, ti mostrero' il corrispettivo all'interno di un array che il mio bravissimo programmatore ha definito: ");

sbagliato:
    scanf("%d", &a);
    if (a < 0 || a > 4)
    {
        printf("Hai inserito un valore o troppo basso o troppo alto, ritenta: ");
        goto sbagliato;
    }
    else
        printf("Il valore %d da te inserito, nell'array corrisponde a %d.\n", a, array[a]);
}