#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *v;
    int n;
    printf("Dimensione: ");
    scanf("%d", &n);

    v = (float *)malloc(n * sizeof(float));

    for (int i = 0; i < n; i++)
        scanf("%f", &v[i]);

    for (int i = 0; i < n; i++)
        printf("%.1f ", v[i]);

    puts("");

    free(v);
    v = NULL;
}