#include <stdio.h>
// Gli array con due dimensioni sono le matrici (es. float M[20][30] 20 righe e 30 colonne)

int main()
{
    int M[3][3];
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            if (i == j)
                M[i][j] = 1;
            else
                M[i][j] = 0;
        }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }
    return 0;
}