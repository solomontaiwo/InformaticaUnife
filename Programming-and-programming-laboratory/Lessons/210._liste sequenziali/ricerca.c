int ricerca(Lista 1, int numero)
{
    int i;
    // scorro tutti gli elementi della lista
    for (i = 0; i < l.n_elementi; i++)
    // se trovo il numero cercato, ritorno 1
    {
        if (l.dati[i] == numero)
            return 1;
    }
    return 0;
}