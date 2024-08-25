/* Scrivere un programma che:
1 crei un array a con gli interi compresi fra 1900 e 2100;
2 crei un secondo array b con gli elementi di a che rappresentano anni bisestili
3 stampi il contenuto di b.
*/
#include <stdio.h>
#define SIZE 201

int main()
{
    int a[SIZE], b[SIZE], anno = 1900, dl = 0;

    for (int i = 0; i < SIZE; i++)
    {
        a[i] = anno;
        anno++;
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (a[i] % 4 == 0)
        {
            b[dl] = a[i];
            dl++;
        }

        for (int i = 0; i < dl; i++)
        {
            printf("%d\n", b[i]);
        }
    }
}