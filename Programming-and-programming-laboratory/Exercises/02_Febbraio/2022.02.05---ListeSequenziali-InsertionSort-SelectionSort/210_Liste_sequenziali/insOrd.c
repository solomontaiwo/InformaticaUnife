void insOrd(Lista *pl, int numero)
{
    int i;
    if (piena(*pl))
    {
        printf("La lista e' piena.\n");
        exit(-1);
    }
    // sposto a destra tutti gli elementi maggiori del numero da inserire
    i = pl->n_elementi;

    while (i > 0 && pl->dati[i - 1] > numero)
    {
        pl->dati[i] = pl->dati[i - 1];
        i--;
    }
    pl->dati[i] = numero;
    pl->n_elementi++;
}