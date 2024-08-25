#include <stdio.h>

int indice_max(int v[], int dl)
{
    int m = 0; // indice del massimo
    int i;
    if (dl < 1)
    {
        printf("Array senza elementi!\n");
        return -1;
    }
    for (i = 1; i < dl; i++)
        if (v[i] > v[m])
            m = i;
    return m;
}

int main()
{
    int a[10], n, i;
    printf("Quanti elementi?\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Indice del massimo: %d\n", indice_max(a, n));
    return 0;
}