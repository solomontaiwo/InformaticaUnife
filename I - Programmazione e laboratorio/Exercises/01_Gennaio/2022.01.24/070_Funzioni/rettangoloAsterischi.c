// Scrivere un programma che stampi a video un rettangolo composto di asterischi di lati m e n richiesti all’utente, usando una funzione riga che stampi una riga di m asterischi. //
#include <stdio.h>

int m, n;

char riga(int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("*");
    }
    puts("");
}

int main()
{

    printf("Inserisci due valori interi m ed n, ti stampero' un rettangolo fatto del numero di asterischi da te indicati.\n");

    scanf("%d %d", &m, &n);

        for (int i = 0; i < n; i++)
    {
        riga(m);
    }
}