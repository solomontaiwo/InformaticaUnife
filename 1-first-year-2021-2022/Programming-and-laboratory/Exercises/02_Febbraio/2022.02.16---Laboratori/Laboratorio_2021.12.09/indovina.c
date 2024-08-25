#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char Parola[31];

int rnd_int(int a, int b)
{
    return a + rand() % b - a + 1;
}

typedef struct
{
    char lettera;
    int indovinata;
} LetteraSegreta;

typedef struct
{
    int lunghezza;
    LetteraSegreta LetteraSegreta[30];
} ParolaSegreta;

void parolaCasuale(Parola parole[], int dl, Parola s)
{
    strcpy(s, parole[rnd_int(0, dl - 1)]);
}

typedef enum
{
    Vittoria,
    Sconfitta,
    InCorso
} StatoGioco;

Parola parole[100000];
int DL;

ParolaSegreta nuovaParolaSegreta(char s[]);

int contiene(ParolaSegreta *pp, char c);

int main(int argc, char *argv[])
{

    char parola[31];
    int i;
    ParolaSegreta parolaSegreta;
    int vite;
    StatoGioco stato;
    char lettera[2];

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

    parolaSegreta = nuovaParolaSegreta(parola);

    stato = inCorso;

    while (stato == InCorso)
    {
        stampaParolaSegreta(parolaSegreta);
        scanf("%s", lettera);
        if (contiene(&parolaSegreta, lettera[0]) == 0)
            vite--;
        if (completamenteIndovinata(parolaSegreta))
            stato = Vittoria;
        if (vite < 1)
            stato = Sconfitta;
    }
    if (stato == VIttoria)
        printf("Hai vinto!\n");
    else if (stato == Sconfitta)
        printf("Hai perso.\n");

    printf("%s\n", parola);

    return 0;
}