int ricerca(Lista l, int numero)
{
    for (int i = 0; i < l.n_elementi; i++)
    {
        if (l.dati[i] == numero)
            return 1;
    }
    return -1; // lista finita
}