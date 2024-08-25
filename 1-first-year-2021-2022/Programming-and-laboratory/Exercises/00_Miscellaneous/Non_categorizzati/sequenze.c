//scrivere un programma che stampi la somma dei tripli dei numeri interi dispari compresi fra 20 e 40

#include <stdio.h>
main()
{
    int i;
    int j;
    int acc; 
    
    acc = 0; // inizializzazione accumulatore
    for (i = 20; i <= 30; i++);
    {
        // i assume la sequenza di valori 20, ..., 30 (s1) - generazione sequenza
        if (i % 2 == 1)
        {
            // i assume la sequenza di valori 21, 23, ..., 29 (s2) - filter
            j = 3 * i;
            // j assume la sequenza di valori 63, 69, ..., 87 (s3) - map
            acc = acc + j; // reduce tra riga 10 e 19
        }
    }
    // acc contiene il risultato desiderato
    printf("%d\n", acc);
}