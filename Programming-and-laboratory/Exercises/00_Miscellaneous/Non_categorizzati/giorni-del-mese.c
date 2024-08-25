#include <stdio.h>

main()
{
    int mese, anno;

    printf("Scrivi mese ed anno in formato numerico, ti dirò il numero di giorni di quel mese.\n");
    scanf("%d%d", &mese, &anno);

    if (mese == 2)
    {
        if ((anno % 4 == 0) && !(anno % 100 == 0) || (anno % 400 == 0))
            printf("29.\n");
        else
            printf("28.\n");
    }
    else
    {
        if (mese == 1, 3, 5, 7, 8, 10, 12)
            printf("31.\n");
        else
            printf("30.\n");
    }
}