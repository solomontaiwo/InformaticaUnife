// Scrivere un programma che definisca un array inizializzato come negli esempi in questa diapositiva, e poi ne stampi gli elementi, uno su ogni riga. //
#include <stdio.h>

int main()
{
    int array[] = {2, 4, 6, 1, 2, 3};

    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", array[i]);
    }
}