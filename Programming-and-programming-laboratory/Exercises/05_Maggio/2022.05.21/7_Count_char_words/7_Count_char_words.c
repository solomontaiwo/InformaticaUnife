/* Write a program in C to count a number of words and characters in a file. Go to the editor
Test Data :
Input the file name to be opened : test.txt
Expected Output :

The content of the file test.txt are :
test line 1
test line 2
test line 3
test line 4
The number of words in the  file test.txt are : 12
The number of characters in the  file test.txt are : 36

https://www.w3resource.com/c-programming-exercises/file-handling/ */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *pft;
    int caratteri = 1;
    int parole = 1;
    char caratt;

    if ((pft = fopen("test.txt", "rt")) == NULL)
    {
        printf("Impossibile aprire il file di testo.\n");
        exit(0);
    }

    while ((caratt = fgetc(pft)) != EOF)
    {
        if (caratt == ' ' || caratt == '\n')
        {
            parole++;
        }
        else
            caratteri++;
    }

    printf("Il numero di parole all'interno del file di testo e' pari a %d\nIl numero di caratteri e' %d\n", parole, caratteri - 1);

    fclose(pft);
}