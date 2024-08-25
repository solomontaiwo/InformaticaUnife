#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dim;
    float *v;
    int i;
    printf("Quanti elementi?\n");
    scanf("%d", &dim);

    /// ora si procede con il riservare una parte di memoria tramite l'allocazione di dimensione pari a dim float

    v = (float *)malloc(sizeof(float) * dim);
    if (v == NULL)
    {
        printf("Impossibile allocare il vettore.\n");
        exit(1);
    }
    for (i = 0; i < dim; i++)
        v[i] = 1.0 / (i + 1);
    // oppure *(v + i) = 1.0 / (i + 1);

    for (i = 0; i < dim; i++)
        printf("%f\n", *(v + i));

    // liberazione memora e far diventare NULL i puntatori delle aree di memoria appena liberate
    free(v);
    v = NULL;

    return 0;
}