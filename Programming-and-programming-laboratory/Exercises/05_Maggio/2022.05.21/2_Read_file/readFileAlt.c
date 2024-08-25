/* Write a program in C to read an existing file.
Test Data :
Input the file name to be opened : test.txt
Expected Output :

The content of the file test.txt is  :
This is the content of the file test.txt. 
https://www.w3resource.com/c-programming-exercises/file-handling/ */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *pft;
    char nomeFile[20];
    char stringa;

    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomeFile);

    if ((pft = fopen(nomeFile, "rt")) == NULL)
    {
        printf("Impossibile aprire il file di testo richiesto.\n");
        exit(0);
    }

    while ((stringa = fgetc(pft)) != EOF)
        printf("%c", stringa);

    puts("");

    fclose(pft);
}