#include <stdio.h>
#define SIZE 80

void reverse(const char *const sPtr); // prototipo di funzione

int main(void)
{

    char frase[SIZE];

    puts("Inserisci una riga di testo: ");

    fgets(frase, SIZE, stdin); // array in cui salvare l'input, dimensione massima dell'input e metodo di acquisizione (in questo caso, tastiera)

    printf("\nLa linea stampata al contrario e':");
    reverse(frase);
    puts("");
}

void reverse(const char *const sPtr)
{

    if ('\0' == sPtr[0])
    {
        return;
    }
    else
    {
        reverse(&sPtr[1]);
        putchar(sPtr[0]);
    }
}