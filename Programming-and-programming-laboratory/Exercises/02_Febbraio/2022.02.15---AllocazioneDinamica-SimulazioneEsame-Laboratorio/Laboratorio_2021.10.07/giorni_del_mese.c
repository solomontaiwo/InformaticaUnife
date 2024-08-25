#include <stdio.h>

int main(int argc, char *argv[])
{
    int mese, anno;

    printf("Inserisci mese e giorno: ");
    scanf("%d %d", &mese, &anno);

    if (mese == 2)
    {
        if (anno % 4 == 0 && anno % 100 != 0 || anno % 400 == 0)
        {
            printf("Il mese ha 29 giorni.\n");
        }
        else
            printf("Il mese ha 28 giorni.\n");
    }
    else
    {
        if (mese != 4, 6, 9, 11, 2)
        {
            printf("Il numero di giorni in quel mese e' pari a 31.\n");
        }
        else if (mese == 4, 6, 9, 11)
            printf("Numero di giorni: 30\n");
    }
}