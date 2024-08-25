#include <stdio.h>

void elrip(int v[], int *pdl)
{
    int i, j;
    i = 0;
    for (i = 0; i < *pdl - 1; i++)
        for (j = i + 1; j < *pdl; j++)
            if (v[i] == v[j])
            {
                int k;
                for (k = j + 1; k < *pdl; k++)
                    v[k - 1] = v[k];
                (*pdl)--;
            }
}

void stampa(int v[], int dl)
{
    int i;
    for (i = 0; i < dl; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main()
{
    int a[] = {1, 4, 2, 4, 1, 6};
    int dl = 6;
    elrip(a, &dl);
    stampa(a, dl);
    return 0;
}
