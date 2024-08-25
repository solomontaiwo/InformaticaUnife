#define SIZE 10

typedef struct
{
    int n_elementi;
    int dati[SIZE];
} Lista;

void listaNuova(Lista *pl)
{
    pl->n_elementi = 0;
}

int vuota(Lista l)
{
    return l.n_elementi == 0;
}

int piena(Lista l)
{
    return l.n_elementi == SIZE;
}

int ricerca(Lista l, int numero)
{
    for (int i = 0; i < l.n_elementi; i++)
    {
        if (l.dati[i] == numero)
            return 1;
    }
    return 0;
}

void insOrd(Lista *pl, int numero)
{
    if (piena(*pl))
    {
        printf("Lista piena, impossibile inserire nuovi elementi.\n");
        exit(-1);
    }
    int i = pl->n_elementi;
    while (i > 0 && pl->dati[i - 1] > numero)
    {
        pl->dati[i] = pl->dati[i - 1];
        i--;
    }
    pl->dati[i] = numero;
    pl->n_elementi++;
}

void elim1(Lista *pl, int numero)
{
    int i = 0;
    while (i < pl->n_elementi)
    {
        if (pl->dati[i] == numero)
        {
            for (int j = i; j < pl->n_elementi - 1; j++)
            {
                pl->dati[j] = pl->dati[j + 1];
            }
            pl->n_elementi--;
            return;
        }
        else
            i++;
    }
}

void insTesta(Lista *pl, int numero)
{
    if (piena(*pl))
    {
        printf("Impossibile eseguire un nuovo inserimento, lista gia' piena.\n");
        exit(-1);
    }
    else
    {
        for (int i = pl->n_elementi; i > 0; i--)
        {
            pl->dati[i] = pl->dati[i - 1];
        }
        pl->dati[0] = numero;
        pl->n_elementi++;
    }
}