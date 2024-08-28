// Verificare se un numero, richiesto all’utente, è primo, ossia se non ha divisori interi a parte 1 e se stesso. //
#include <stdio.h>

int main()
{
    int n, i, c;
    printf("Digita un numero naturale\n");
    scanf("%d", &n);
    c = 0; // valore iniziale del contatore
    for (i = 1; i <= n; i++)
    {
        // i assume i valori naturali fra 1 e n
        // filtriamo i divisori di n
        if (n % i == 0)
        {
            // i assume i valori che sono divisori di n
            c++;
        }
    }
    // c contiene il numero di divisori di n
    if (c == 2)
        // gli unici divisori sono 1 e n
        printf("%d e` primo\n", n);
    else
        printf("%d non e` primo\n", n);
}