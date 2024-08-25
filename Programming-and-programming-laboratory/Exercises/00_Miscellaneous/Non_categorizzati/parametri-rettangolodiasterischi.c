// rettangolo composto di asterischi di lati m ed n richiesti all'utente,
// usando una funzione riga che stampi una riga di m asterischi
#include <stdio.h>

int riga(int m)
{
    int i;
    for (i = 0; i < m; i++)
        printf("*");
    printf("\n");
}

int main(void)
{
    int m, n;
    int i;
    printf("Inserisci due valori\n");
    scanf("%d%d", &m, &n);
    for (i = 0; i < n; i++)
        riga(m);
    return 0; // tutto ok
}