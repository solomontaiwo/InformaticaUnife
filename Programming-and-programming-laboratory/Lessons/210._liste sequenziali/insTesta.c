void insTesta(Lista *pl, int numero)
{
    int i;
    if (piena(*pl))
    {
        printf("Errore: lista piena.\n");
        exit(-1);
    }
    
    for (i = pl->n_elementi; i > 0; i--)
        pl->dati[i] = pl->dati[i - 1];

    pl->dati[0] = numero;

    pl->n_elementi++;
}