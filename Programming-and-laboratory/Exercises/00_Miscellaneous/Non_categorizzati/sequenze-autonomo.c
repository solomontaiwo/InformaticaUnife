// stampa la somma del quadrato dei numeri pari contenuti fra 0 e 20
#include <stdio.h>
main()
{
    int v, j;
    int acc = 0;

    for (v = 0; v <= 20; v++) // ottenimento valori da 0 a 20 - s1
    {
        if (v % 2 == 0) // filter - s2
        {
            j = 4 * v; // map s3
            acc = j + acc;
        }
    }
    printf("%d\n", acc);
}