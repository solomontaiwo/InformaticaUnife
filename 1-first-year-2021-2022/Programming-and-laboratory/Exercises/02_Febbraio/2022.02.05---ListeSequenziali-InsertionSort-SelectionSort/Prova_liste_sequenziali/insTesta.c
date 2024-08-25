void insTesta(Lista *pl, int numero)
{
    int i;
    if (piena(*pl))
    {
        printf("La lista e' piena.\n");
        exit(-1);
    }
    // faccio spazione per il nuovo elemento spostando gli altri a destra
    for (i = pl->n_elementi; i > 0; i--)
        pl->dati[i] = pl->dati[i - 1];
    pl->dato[0] = numero;
    pl->n_elementi--;
}