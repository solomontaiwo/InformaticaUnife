/* Write a program in C to Find the Number of Lines in a Text File.
Test Data :
Input the file name to be opened : test.txt
Expected Output :

 The lines in the file test.txt are : 4

 https://www.w3resource.com/c-programming-exercises/file-handling/ */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pft;
    int conta = 0;
    char carattere;

    if ((pft = fopen("test.txt", "rt")) == NULL)
    {
        printf("Impossibile aprire il file di testo.\n");
        exit(0);
    }

    while ((carattere = fgetc(pft)) != EOF)
    {
        if (carattere == '\n')
            conta++;
    }

    printf("Le righe nel file di testo sono %d\n", conta);

    fclose(pft);
}