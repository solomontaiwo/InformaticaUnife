#include <stdio.h>

main()
{
    printf("Immetti un anno, ti dirò se è bisestile.\n");
    int anno;
    scanf("%d", &anno);

    if (anno % 4 == 0)
    {
        if (anno % 100 == 0)
        {
            if (anno % 400 == 100)
                printf("%d è bisestile.\n", anno);

            else
                printf("%d non è bisestile.\n", anno);
        }
        else
        {
            printf("%d è bisestile.\n", anno);
        }
    }
    else
        printf("%d non è bisestile.\n", anno);
}