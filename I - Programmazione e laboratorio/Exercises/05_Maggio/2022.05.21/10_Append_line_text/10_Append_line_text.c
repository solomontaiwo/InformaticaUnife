/* Write a program in C to append multiple lines at the end of a text file.
Assume that the content of the file test.txt is :
test line 1
test line 2
test line 3
test line 4
Test Data :
Input the file name to be opened : test.txt
Input the number of lines to be written : 3
The lines are :
test line 5
test line 6
test line 7
Expected Output :

The content of the file test.txt is  :
test line 1
test line 2
test line 3
test line 4

test line 5
test line 6
test line 7

https://www.w3resource.com/c-programming-exercises/file-handling/ */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pft;
    char caratt;
    int numeroLineeNuove;

    printf("Inserisci il numero di linee che vuoi inserire: ");
    scanf("%d", &numeroLineeNuove);

    if ((pft = fopen("test.txt", "at")) == NULL)
    {
        printf("Impossibile aprire il file di testo.\n");
        exit(0);
    }

    for (int i = 1; i <= numeroLineeNuove; i++)
        fprintf(pft, "test line %d\n", i + 4);

    fclose(pft);
}