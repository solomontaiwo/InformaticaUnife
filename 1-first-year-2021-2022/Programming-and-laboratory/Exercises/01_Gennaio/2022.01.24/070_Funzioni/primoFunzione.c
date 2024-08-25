/* Si scriva una funzione primo che restituisca 1 se il suo argomento intero è primo e 0 altrimenti. Si utilizzi la funzione in un programma che stampi tutti i numeri primi compresi fra 2 e un numero N richiesto all’utente. */
#include <stdio.h>

int primo(int n)
{
    // restituisce 1 se n non ha divisori compresi fra 2 e n-1
    if (n < 2)
        return 0;
    int d;
    for (d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;
    return 1;
}

int main()
{
    int N, i;
    printf("Inserisci un numero intero\n");
    scanf("%d", &N);

    // output = filter (primo, 2..N)

    for (i = 2; i <= N; i++)
        if (primo(i))
            printf("%d ", i);

    printf("\n");

    return 0;
}