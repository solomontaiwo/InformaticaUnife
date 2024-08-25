#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char Parola[31];

int rnd_int(int a, int b)
{
    return a + rand() % b - a + 1;
}

void parolaCasuale(Parola parole[], int dl, Parola s)
{
    strcpy(s, parole[rnd_int(0, dl - 1)]);
}

Parola parole[100000];
int DL;

int main(int argc, char *argv[])
{

    char parola[31];
    int i;

    FILE *pf;

    if ((pf = fopen("words.italian.txt", "rt")) == NULL)
    {
        printf("Errore nell'apertura del file vocabolario.\n");
        exit(1);
    }
    i = 0;
    while (fscanf(pf, "%s", parole[i]) == 1)
        i++;

    if (fclose(pf) != 0)
    {
        printf("Impossibile chiudere il file vocabolario.\n");
        exit(2);
    }

    int DL = i;

    srand(time(NULL));

    parolaCasuale(parole, DL, parola);

    printf("%s\n", parola);

    return 0;
}