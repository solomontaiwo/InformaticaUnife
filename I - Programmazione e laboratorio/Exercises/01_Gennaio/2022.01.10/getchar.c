#include <stdio.h>
#define SIZE 80

int main(void)
{

    int c;
    char frase[SIZE];
    int i = 0;

    puts("Inserisci una linea di testo:");

    while ((i < SIZE - 1) && (c = getchar()) != "\n")
    {
        frase[i++] = c;
    }
    frase[i] = '\0';

    puts("\nLa linea inserita e': ");
    puts(frase);
}