void insOrd(Lista *pl, int numero)
{
    if (piena(*pl))
    {
        printf("La lista e' piena.\n");
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