/* Write a program in C to copy a file in another name. Go to the editor

Assume that the content of the file test.txt is :
test line 1
test line 2
test line 3
test line 4
Test Data :
Input the source file name : test.txt
Input the new file name : test1.txt
Expected Output :

The file test.txt  copied successfully in the file test1.txt.
If you read the new file you will see the content of the file :

test line 1
test line 2
test line 3
test line 4

https://www.w3resource.com/c-programming-exercises/file-handling/  */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *pft1, *pft2;
    char testo[500];
    int i = 0;
    char nomeTestoNuovo[30];

    if ((pft1 = fopen("test.txt", "rt")) == NULL)
    {
        printf("Impossibile aprire il file di testo di origine.\n");
        exit(0);
    }

    printf("Nome file di destinazione: ");
    scanf("%s", nomeTestoNuovo);

    if ((pft2 = fopen(nomeTestoNuovo, "wt")) == NULL)
    {
        printf("Impossibile creare il file di testo di destinazione.\n");
        exit(1);
    }

    while ((testo[i] = fgetc(pft1)) != EOF)
    {
        fprintf(pft2, "%c", testo[i]);
        i++;
    }

    printf("Il file e' stato copiato con successo nel documento %s.\n", nomeTestoNuovo);

    fclose(pft1);
    fclose(pft2);
}