/* Scrivere un programma che, per ogni numero compreso fra 1 e 100, scriva:
"bim" se il numero è divisibile per 3;
"bum" se il numero è divisibile per 5;
"bimbum" se il numero è divisibile per 3 e per 5;
altrimenti, il numero stesso.
*/
#include <stdio.h>

int main()
{

    for (int i = 1; i <= 100; i++)
    {
        if ((i % 3 == 0) && (i % 5 == 0))
        {
            printf("bimbum\n");
        }
        else if (i % 3 == 0)
        {
            printf("bim\n");
        }
        else if (i % 5 == 0)
        {
            printf("bum\n");
        }
        else
        {
            printf("%d\n", i);
        }
    }
}