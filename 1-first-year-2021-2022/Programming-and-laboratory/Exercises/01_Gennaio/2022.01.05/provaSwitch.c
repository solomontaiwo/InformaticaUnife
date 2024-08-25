#include <stdio.h>

int punteggio;

int main()
{

    printf("Inserisci il tuo punteggio in centesimi: \n");
    scanf("%d", &punteggio);
    switch (punteggio)
    {
    case 100:
        printf("Hai ottenuto il punteggio massimo, complimenti!\n");
        break;
    case 75:
        printf("Hai ottenuto un ottimo punteggio.\n");
        break;
    case 50:
        printf("Non male.\n");
        break;
    case 25:
        printf("Si puo' fare decisamente meglio.\n");
        break;
    case 0:
        printf("Molto male, ritenta.\n");
        break;
    }
}