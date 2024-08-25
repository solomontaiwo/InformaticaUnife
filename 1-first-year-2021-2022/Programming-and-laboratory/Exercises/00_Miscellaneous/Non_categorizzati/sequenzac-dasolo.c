// stampa la somma del triplo dei numeri dispari contenuti tra 20 e 30
#include <stdio.h>
main()
{
    int i, j;
    int acc = 0;
    
    for (i = 20; i <= 30; i++) // ottenimento valori da 20 a 30 - generazione sequenza s1
    {
        if (i % 2 == 1) // filter per ottenimento numeri dispari - filter s2
        {
            j = 3 * i; // map s3
            acc = j + acc;
        }
    }
    printf("%d\n", acc);
}