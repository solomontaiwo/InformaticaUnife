void elim1(Lista *pl, int numero)
{
    int i = 0;
    while (i < pl->n_elementi)
    {
        if (pl->dati[i] == numero)
        {
            int j;
            for (j = i; j < pl->n_elementi - 1; j++)
                pl->dati[j] = pl->dati[j + 1];
            pl->n_elementi--;
        }
        else
            i++;
    }
}