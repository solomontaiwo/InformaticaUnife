#define SIZE 5

typedef struct
{
    int numeroElementi;
    int dati[SIZE];
} Lista;

int vuota(Lista l)
{
    return l.numeroElementi == 0;
}

int piena(Lista l)
{
    return l.numeroElementi == SIZE;
}

void inizializza(Lista *pl, int numero)
{
    pl->numeroElementi = 0;
}

void stampa(Lista l)
{
    for (int i = 0; i < l.numeroElementi; i++)
    {
        printf("%d ", l.dati[i]);
    }
    puts("");
}

void insTesta(Lista *pl, int numero)
{
    if (piena(*pl))
    {
        printf("impossobile aggiungere elementi a lista piena.\n");
        exit(-1);
    }
    else
    {
        int i = pl->numeroElementi;
        while (i > 0)
        {
            pl->dati[i] = pl->dati[i - 1];
        }
        pl->dati[0] = numero;
        pl->numeroElementi++;
    }
}

void insOrd(Lista *pl, int numero)
{
    if (piena(*pl))
    {
        printf("Impossibile aggiungere valori a lista piena.\n");
        exit("");
    }
    else
    {
        int i = pl->numeroElementi;
        while (i > 0 && pl->dati[i - 1] > numero)
        {
            pl->dati[i] = pl->dati[i - 1];
            i--;
        }
        pl->dati[i] = numero;
        pl->numeroElementi++;
    }
}

void elim1(Lista *pl, int numero)
{
    for (int i = 0; i < pl->numeroElementi; i++)
    {
        if (pl->dati[i] == numero)
        {
            for (int j = i; j < pl->numeroElementi - 1; j++)
                pl->dati[j] = pl->dati[j + 1];
        }
        pl->numeroElementi--;
        return;
    }
}