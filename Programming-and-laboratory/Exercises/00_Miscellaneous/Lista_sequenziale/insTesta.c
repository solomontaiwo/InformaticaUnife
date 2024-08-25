void insTesta(Lista *pl, int numero)
{
    if (piena(*pl))
    {
        printf("La lista e' piena.\n");
        exit(-1);
    }

    for (int i = pl->n_elementi; i > 0; i--)
        pl->dati[i] = pl->dati[i - 1];
    pl->dati[0] = numero;
    pl->n_elementi++;
}