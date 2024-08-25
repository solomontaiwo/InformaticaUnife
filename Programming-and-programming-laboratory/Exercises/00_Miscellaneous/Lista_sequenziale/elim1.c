void elim1(Lista *pl, int numero)
{
    int i;
    while (i < pl->n_elementi)
    {
        if (pl->dati[i] == numero)
        {
            for (int j = j; j < pl->n_elememtni - 1; j++)
                pl->dati[j] = pl->dati[j + 1];
            return;
        }
        else
            i++;
    }
}