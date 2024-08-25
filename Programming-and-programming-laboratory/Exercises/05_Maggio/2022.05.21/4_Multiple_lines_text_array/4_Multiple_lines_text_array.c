/* Write a program in C to read the file and store the lines into an array.
Test Data :
Input the file name to be opened : test.txt
Expected Output :

 The content of the file test.txt  are :
 test line 1
 test line 2
 test line 3
 test line 4

 https://www.w3resource.com/c-programming-exercises/file-handling/ */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pft;
    char array[100];
    int i = 0;

    if ((pft = fopen("test.txt", "rt")) == NULL)
    {
        printf("Impossibile aprire il file di testo.\n");
        exit(0);
    }

    printf("Il contenuto del file di testo: \n");

    while ((array[i] = fgetc(pft)) != EOF)
    {
        printf("%c", array[i]);
        i++;
    }

    fclose(pft);
}