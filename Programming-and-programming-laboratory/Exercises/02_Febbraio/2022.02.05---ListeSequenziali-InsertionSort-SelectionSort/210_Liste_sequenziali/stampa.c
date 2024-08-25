void stampa(Lista l)
{
    int i;
    for (i = 0; i < l.n_elementi; i++)
    {
        printf("%d ", l.dati[i]);
    }
    puts("");
}