#include <stdio.h>
main()
{
    int anno;
    printf("Inserisci un anno, ti dirò se è bisestile o meno.\n");
    scanf("%d", &anno);

    if ((anno % 4 == 0 && !(anno % 100 == 0)) || (anno % 400 == 0))
        printf("%d è bisestile.\n", anno);
    else
        printf("%d non è bisestile.\n", anno);
}