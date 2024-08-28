#include <stdio.h>
main()
{
    int giorno, mese, anno;
    int giorni_del_mese;
    
    printf("Dammi una data completa (giorno, mese, anno in numeri interi).\n");
    scanf("%d%d%d", &giorno, &mese, &anno);
    if (giorno == 31 && mese == 12)
        printf("01/01/%d\n", anno + 1);
    else
    {
        if ((giorno == 30) && (mese == 4, 6, 9, 11))
            printf("01/%d/%d\n", mese + 1, anno);
        else
        {
            if ((anno % 4 == 0) && !(anno % 100 == 0) || (anno % 400 == 0))
                printf("%d/02/%d\n", giorno + 1, anno);
            else
                printf("01/%d/%d\n", mese + 1, anno);
        }
    }
    printf("%d/%d/%d", giorno + 1, mese + 1, anno + 1);
}