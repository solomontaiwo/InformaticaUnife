// Si inizializzi la matrice identità 3x3 //
#include <stdio.h>

/* typedef int riga[3];
typedef riga matrice[3];
*/

int main(void)
{
    int matrice[3][3];
    int i = 0, j = 0, d1;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == j)
                matrice[i][j] = 1;
            else
                matrice[i][j] = 0;
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matrice[i][j]);
        }
        puts("");
    }
}