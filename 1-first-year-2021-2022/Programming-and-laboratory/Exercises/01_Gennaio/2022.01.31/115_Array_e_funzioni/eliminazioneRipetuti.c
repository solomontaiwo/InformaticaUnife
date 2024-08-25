// Scrivere e testare una procedura che elimini gli eventuali elementi ripetuti dall’array di interi che riceve come parametro. //
#include <stdio.h>

void elrip(int v[], int *pdl)
{
    int i, j;
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
    // dl vale 4 e gli elementi di a sono 1,4,2,6,...,...
    stampa(a, dl);
    return 0;
}