void elim1(Lista *pl, int numero)
{
    int i = 0;
    while (i < pl->n_elementi)
    {
        // se trovo un elemento uguale a quello da eliminare...
        if (pl->dati[i] == numero)
        {
            int j;
            // sposto a sinistra tutti gli elementi che lo seguono
            for (j = i; pl->n_elementi - 1; j++)
                pl->dati[j] = pl->dati[j + 1];
            pl->n_elementi--;
            return;
        }
        else
            i++;
    }
}